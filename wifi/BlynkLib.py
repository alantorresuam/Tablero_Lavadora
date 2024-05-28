# Definición de la versión del código
__version__ = "1.0.0"
 
# Importación de módulos necesarios
import struct  # Módulo para manejar datos estructurados binarios
import time  # Módulo para trabajar con el tiempo
import sys  # Módulo que proporciona acceso a algunas variables usadas o mantenidas por el intérprete
import os  # Módulo que proporciona funciones para interactuar con el sistema operativo
 
# Manejo de importaciones condicionales según el entorno
try:
    import machine  # Importa el módulo "machine" si está disponible (microPython)
    gettime = lambda: time.ticks_ms()  # Función para obtener el tiempo en milisegundos
    SOCK_TIMEOUT = 0  # Tiempo de espera de socket
except ImportError:
    const = lambda x: x  # Función de identidad
    gettime = lambda: int(time.time() * 1000)  # Función para obtener el tiempo en milisegundos
    SOCK_TIMEOUT = 0.05  # Tiempo de espera de socket
 
# Función dummy que no hace nada
def dummy(*args):
    pass
 
# Definición de constantes para diferentes tipos de mensajes
MSG_RSP = const(0)
MSG_LOGIN = const(2)
MSG_PING  = const(6)
MSG_TWEET = const(12)
MSG_NOTIFY = const(14)
MSG_BRIDGE = const(15)
MSG_HW_SYNC = const(16)
MSG_INTERNAL = const(17)
MSG_PROPERTY = const(19)
MSG_HW = const(20)
MSG_HW_LOGIN = const(29)
MSG_EVENT_LOG = const(64)
MSG_REDIRECT  = const(41)  # Mensaje de redirección (no implementado)
MSG_DBG_PRINT  = const(55) # Mensaje de depuración (no implementado)
STA_SUCCESS = const(200)  # Estado de conexión exitosa
STA_INVALID_TOKEN = const(9)  # Estado de token de autenticación inválido
DISCONNECTED = const(0)  # Estado de desconexión
CONNECTING = const(1)  # Estado de conexión en proceso
CONNECTED = const(2)  # Estado de conexión establecida
 
# Definición de la clase EventEmitter para manejar eventos
class EventEmitter:
    def __init__(self):
        self._cbks = {}  # Diccionario para almacenar los manejadores de eventos
 
    # Método para registrar manejadores de eventos
    def on(self, evt, f=None):
        if f:
            self._cbks[evt] = f
        else:
            def D(f):
                self._cbks[evt] = f
                return f
            return D
 
    # Método para emitir eventos
    def emit(self, evt, *a, **kv):
        if evt in self._cbks:
            self._cbks[evt](*a, **kv)
 
# Definición de la clase BlynkProtocol que gestiona la conexión con el servidor Blynk
class BlynkProtocol(EventEmitter):
    def __init__(self, auth, tmpl_id=None, fw_ver=None, heartbeat=50, buffin=1024, log=None):
        EventEmitter.__init__(self)
        self.heartbeat = heartbeat*1000
        self.buffin = buffin
        self.log = log or dummy
        self.auth = auth
        self.tmpl_id = tmpl_id
        self.fw_ver = fw_ver
        self.state = DISCONNECTED
        self.connect()
 
    # Métodos para enviar diferentes tipos de mensajes al servidor Blynk
    def virtual_write(self, pin, *val):
        self._send(MSG_HW, 'vw', pin, *val)
 
    def send_internal(self, pin, *val):
        self._send(MSG_INTERNAL,  pin, *val)
 
    def set_property(self, pin, prop, *val):
        self._send(MSG_PROPERTY, pin, prop, *val)
 
    def sync_virtual(self, *pins):
        self._send(MSG_HW_SYNC, 'vr', *pins)
 
    def log_event(self, *val):
        self._send(MSG_EVENT_LOG, *val)
 
    # Método interno para enviar mensajes
    def _send(self, cmd, *args, **kwargs):
        if 'id' in kwargs:
            id = kwargs.get('id')
        else:
            id = self.msg_id
            self.msg_id += 1
            if self.msg_id > 0xFFFF:
                self.msg_id = 1
                
        if cmd == MSG_RSP:
            data = b''
            dlen = args[0]
        else:
            data = ('\0'.join(map(str, args))).encode('utf8')
            dlen = len(data)
        
        self.log('<', cmd, id, '|', *args)
        msg = struct.pack("!BHH", cmd, id, dlen) + data
        self.lastSend = gettime()
        self._write(msg)
 
    # Método para establecer la conexión con el servidor Blynk
    def connect(self):
        if self.state != DISCONNECTED: return
        self.msg_id = 1
        (self.lastRecv, self.lastSend, self.lastPing) = (gettime(), 0, 0)
        self.bin = b""
        self.state = CONNECTING
        self._send(MSG_HW_LOGIN, self.auth)
 
    # Método para desconectar del servidor Blynk
    def disconnect(self):
        if self.state == DISCONNECTED: return
        self.bin = b""
        self.state = DISCONNECTED
        self.emit('disconnected')
 
    # Método para procesar los datos recibidos del servidor Blynk
    def process(self, data=None):
        if not (self.state == CONNECTING or self.state == CONNECTED): return
        now = gettime()
        if now - self.lastRecv > self.heartbeat+(self.heartbeat//2):
            return self.disconnect()
        if (now - self.lastPing > self.heartbeat//10 and
            (now - self.lastSend > self.heartbeat or
             now - self.lastRecv > self.heartbeat)):
            self._send(MSG_PING)
            self.lastPing = now
        
        if data != None and len(data):
            self.bin += data
 
        while True:
            if len(self.bin) < 5:
                break
 
            cmd, i, dlen = struct.unpack("!BHH", self.bin[:5])
            if i == 0: return self.disconnect()
                      
            self.lastRecv = now
            if cmd == MSG_RSP:
                self.bin = self.bin[5:]
 
                self.log('>', cmd, i, '|', dlen)
                if self.state == CONNECTING and i == 1:
                    if dlen == STA_SUCCESS:
                        self.state = CONNECTED
                        dt = now - self.lastSend
                        info = ['ver', __version__, 'h-beat', self.heartbeat//                        1000, 'buff-in', self.buffin, 'dev', sys.platform+'-py']
                        if self.tmpl_id:
                            info.extend(['tmpl', self.tmpl_id])
                            info.extend(['fw-type', self.tmpl_id])
                        if self.fw_ver:
                            info.extend(['fw', self.fw_ver])
                        self._send(MSG_INTERNAL, *info)
                        try:
                            self.emit('connected', ping=dt)
                        except TypeError:
                            self.emit('connected')
                    else:
                        if dlen == STA_INVALID_TOKEN:
                            self.emit("invalid_auth")
                            print("Invalid auth token")
                        return self.disconnect()
            else:
                if dlen >= self.buffin:
                    print("Cmd too big: ", dlen)
                    return self.disconnect()
 
                if len(self.bin) < 5+dlen:
                    break
 
                data = self.bin[5:5+dlen]
                self.bin = self.bin[5+dlen:]
 
                args = list(map(lambda x: x.decode('utf8'), data.split(b'\0')))
 
                self.log('>', cmd, i, '|', ','.join(args))
                if cmd == MSG_PING:
                    self._send(MSG_RSP, STA_SUCCESS, id=i)
                elif cmd == MSG_HW or cmd == MSG_BRIDGE:
                    if args[0] == 'vw':
                        self.emit("V"+args[1], args[2:])
                        self.emit("V*", args[1], args[2:])
                elif cmd == MSG_INTERNAL:
                    self.emit("internal:"+args[0], args[1:])
                elif cmd == MSG_REDIRECT:
                    self.emit("redirect", args[0], int(args[1]))
                else:
                    print("Unexpected command: ", cmd)
                    return self.disconnect()
 
import socket
 
# Clase Blynk que hereda de BlynkProtocol y gestiona la conexión con el servidor Blynk a través de un socket
class Blynk(BlynkProtocol):
    def __init__(self, auth, **kwargs):
        self.insecure = kwargs.pop('insecure', False)  # Establece si la conexión es segura o no
        self.server = kwargs.pop('server', 'blynk.cloud')  # Dirección del servidor Blynk
        self.port = kwargs.pop('port', 80 if self.insecure else 443)  # Puerto del servidor Blynk
        BlynkProtocol.__init__(self, auth, **kwargs)  # Inicializa la conexión con el servidor Blynk
        self.on('redirect', self.redirect)  # Maneja los eventos de redirección
 
    # Método para manejar la redirección del servidor Blynk
    def redirect(self, server, port):
        self.server = server
        self.port = port
        self.disconnect()
        self.connect()
 
    # Método para establecer la conexión con el servidor Blynk
    def connect(self):
        print('Connecting to %s:%d...' % (self.server, self.port))
        s = socket.socket()  # Crea un nuevo socket
        s.connect(socket.getaddrinfo(self.server, self.port)[0][-1])  # Conecta el socket al servidor
        try:
            s.setsockopt(socket.IPPROTO_TCP, socket.TCP_NODELAY, 1)  # Configura el socket para enviar datos inmediatamente
        except:
            pass
        if self.insecure:
            self.conn = s  # Si la conexión no es segura, asigna el socket directamente
        else:
            try:
                import ussl
                ssl_context = ussl  # Importa el módulo ussl para establecer una conexión segura
            except ImportError:
                import ssl
                ssl_context = ssl.create_default_context()  # Crea un contexto SSL predeterminado
            self.conn = ssl_context.wrap_socket(s, server_hostname=self.server)  # Establece una conexión segura con el servidor Blynk
        try:
            self.conn.settimeout(SOCK_TIMEOUT)  # Configura el tiempo de espera del socket
        except:
            s.settimeout(SOCK_TIMEOUT)
        BlynkProtocol.connect(self)  # Inicia la conexión con el servidor Blynk
 
    # Método para escribir datos en el socket
    def _write(self, data):
        self.conn.write(data)  # Escribe datos en el socket
        # TODO: manejar desconexión
 
    # Método para ejecutar el bucle principal de la conexión con el servidor Blynk
    def run(self):
        data = b''
        try:
            data = self.conn.read(self.buffin)  # Lee datos del socket
        except KeyboardInterrupt:
            raise
        except socket.timeout:
            # No se recibieron datos, llama al método process para enviar mensajes de ping cuando sea necesario
            pass
        except: # TODO: manejar desconexión
            return
        self.process(data)  # Procesa los datos recibidos del servidor Blynk


