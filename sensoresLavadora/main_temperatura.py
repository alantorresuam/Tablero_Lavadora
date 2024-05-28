from sensor_temperatura import init_temperatura, obtener_temperaturas, nivel_temperatura
from utime import sleep
    
def main():
    pin_num = 16  
    ds_sensor, roms = init_temperatura(pin_num)

    while True:
        temperaturas = obtener_temperaturas(ds_sensor, roms)
        
        for temp in temperaturas:
            temp_celsius = f"{temp:.2f}°C"
            nivel = nivel_temperatura(temp)
            print(f"Temperatura: {temp_celsius}, Nivel: {nivel}")
        
        sleep(1)

if __name__ == "__main__":
    main()
