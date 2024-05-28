import time  
import network  
import BlynkLib  

temps = 4.0
value_10bit = 10.0

class WasherPeripheral:
    def __init__(self):
        # Configura la conexión Wi-Fi
        self.wlan = network.WLAN(network.STA_IF)
        self.wlan.active(True)  
        self.wlan.connect("#WUAMC", "wificua6")  

        # Configuración de la autenticación Blynk
        self.BLYNK_AUTH = 'QTjQHRc6BuQmsjB9cYAOjG3WXH5Y2URa'

        # Conecta al servicio Blynk
        self.blynk = BlynkLib.Blynk(self.BLYNK_AUTH)
        
        self.button_state = 0  # Variable para almacenar el estado del botón virtual
        self.temperature = temps
        self.value_10bit = value_10bit

    def read_temperature(self):
        return self.temperature

    def read_value_10bit(self):
        return self.value_10bit

    def update_temperature(self):
        self.blynk.virtual_write(2, self.temp)

    def update_value_10bit(self):
        self.blynk.virtual_write(3, self.val)

    def connect_wifi(self):
        # Espera a que se establezca la conexión de red
        wait = 10
        while wait > 0:
            if self.wlan.status() < 0 or self.wlan.status() >= 3:
                break
            wait -= 1
            print('waiting for connection...')  
            time.sleep(1)  

        # Maneja el error de conexión de red
        if self.wlan.status() != 3:
            raise RuntimeError('network connection failed')  
        else:
            print('connected')  
            ip = self.wlan.ifconfig()[0]  
            print('IP: ', ip)  

    def run(self):
        self.connect_wifi()

        # Registra el manejador de pin virtual
        @self.blynk.on("V1")  
        def v1_write_handler(value):  
            self.button_state = int(value[0])  # Almacena el valor recibido del botón virtual

        # Bucle principal para ejecutar la comunicación con Blynk
        while True:
            self.update_temperature()  # Llamada a la función sin argumentos adicionales
            self.update_value_10bit()  # Llamada a la función sin argumentos adicionales
            self.blynk.run()

washer_peripheral = WasherPeripheral()
washer_peripheral.run()
