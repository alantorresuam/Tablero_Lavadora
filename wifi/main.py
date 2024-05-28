import time  
import network  
import BlynkLib  

# Configuración inicial de valores y conexión Wi-Fi
temps = 50.0
value_10bit = 20.0

# Configura la conexión Wi-Fi
wlan = network.WLAN(network.STA_IF)
wlan.active(True)  
wlan.connect("#WUAMC", "wificua6")  

# Configuración de la autenticación Blynk
BLYNK_AUTH = 'QTjQHRc6BuQmsjB9cYAOjG3WXH5Y2URa'

# Conecta al servicio Blynk
blynk = BlynkLib.Blynk(BLYNK_AUTH)

def read_temperature():
    return temps

def read_value_10bit():
    return value_10bit

def update_temperature():
    blynk.virtual_write(2, temps)

def update_value_10bit():
    blynk.virtual_write(3, value_10bit)

def send_value_to_blynk(pin, value):
    blynk.virtual_write(pin, value)

def connect_wifi():
    # Espera a que se establezca la conexión de red
    wait = 10
    while wait > 0:
        if wlan.status() < 0 or wlan.status() >= 3:
            break
        wait -= 1
        print('waiting for connection...')  
        time.sleep(1)  

    # Maneja el error de conexión de red
    if wlan.status() != 3:
        raise RuntimeError('network connection failed')  
    else:
        print('connected')  
        ip = wlan.ifconfig()[0]  
        print('IP: ', ip)  

def run():
    connect_wifi()

    # Bucle principal para ejecutar la comunicación con Blynk
    while True:
        update_temperature()  # Llamada a la función sin argumentos adicionales
        update_value_10bit()  # Llamada a la función sin argumentos adicionales
        blynk.run()

run()
