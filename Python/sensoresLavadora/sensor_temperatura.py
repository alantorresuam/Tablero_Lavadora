import machine
import onewire
import ds18x20
import time

def init_temperatura(pin_ds18x20: int):
    """Construye un objeto sensor de temperatura usando el DS18B20.

    Args:
        pin (int): El pin GPIO al que está conectado el pin DATA del DS18B20.
    """
    pin = machine.Pin(pin_ds18x20)
    ds_sensor = ds18x20.DS18X20(onewire.OneWire(pin))
    roms = ds_sensor.scan()
    return ds_sensor, roms

def obtener_temperaturas(ds_sensor, roms):
    """Regresa las temperatura actual del sensor conectado.

    Args:
        ds_sensor: El objeto del sensor DS18B20.
        roms: Lista de ROMs de los sensores conectados.

    Regresa:
        Un flotante
    """
    ds_sensor.convert_temp()
    time.sleep_ms(750)
    temp = [ds_sensor.read_temp(roms[0])]
    return temp


def nivel_temperatura(temp):
    """Clasifica la temperatura en baja, media o alta.

    Args:
        temp (float): La temperatura en grados Celsius.

    Regresa:
        str: Nivel de temperatura ('baja', 'media' o 'alta').
    """
    if temp < 18:
        return "baja"
    elif 18 <= temp <= 24:
        return "media"
    else:
        return "alta"
