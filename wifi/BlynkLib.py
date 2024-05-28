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
 
  