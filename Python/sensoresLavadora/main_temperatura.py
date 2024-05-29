from sensor_temperatura import init_temperatura, obtener_temperaturas, nivel_temperatura
from utime import sleep
    
def main():
    pin_ds18x20 = 18 
    ds_sensor, roms = init_temperatura(pin_ds18x20)

    while True:
        temperatura = obtener_temperaturas(ds_sensor, roms)
        temp_celsius = f"{temperatura:.2f}°C"
        nivel = nivel_temperatura(temperatura)
        print(f"Temperatura: {temp_celsius}, Nivel: {nivel}")
        sleep(1)

if __name__ == "__main__":
    main()
