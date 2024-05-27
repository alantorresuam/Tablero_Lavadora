import machine
import onewire
import ds18x20
import time

def init_temperatura(pin_num: int):
    """Construye un objeto sensor de temperatura usando el DS18B20.

    Args:
        pin (int): El pin GPIO al que está conectado el pin DATA del DS18B20.
    """
    pin = machine.Pin(pin_num)
    ds_sensor = ds18x20.DS18X20(onewire.OneWire(pin))
    roms = ds_sensor.scan()
    return ds_sensor, roms

def obtener_temperaturas(ds_sensor, roms):
    """Regresa las temperaturas actuales de todos los sensores conectados.

    Args:
        ds_sensor: El objeto del sensor DS18B20.
        roms: Lista de ROMs de los sensores conectados.

    Regresa:
        list[float]: Lista de temperaturas en grados Celsius.
    """
    ds_sensor.convert_temp()
    time.sleep_ms(750)
    temps = [ds_sensor.read_temp(rom) for rom in roms]
    return temps


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
