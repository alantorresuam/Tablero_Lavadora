from sensor_nivel_agua import init_nivel_agua, leer_nivel_agua, interpretar_nivel_agua
from utime import sleep

def main():
    adc = init_nivel_agua()

    while True:
        valor = leer_nivel_agua(adc)
        nivel = interpretar_nivel_agua(valor)
        print(f"Nivel de agua: {nivel}, Rango: {valor}")
        sleep(1)

if __name__ == "__main__":
    main()
