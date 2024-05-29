from sensor_temperatura import init_temperatura, obtener_temperaturas

if __name__ == "__main__":
    sensor, rom = init_temperatura(18)  
    temperatura = obtener_temperaturas(sensor, rom)
    print(f"Temperatura: {temperatura[0]:.2f}°C")
