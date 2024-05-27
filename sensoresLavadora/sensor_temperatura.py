import machine
import onewire
import ds18x20
import time

def init_temperatura(pin_num: int):
    pin = machine.Pin(pin_num)
    ds_sensor = ds18x20.DS18X20(onewire.OneWire(pin))
    roms = ds_sensor.scan()
    return ds_sensor, roms

def obtener_temperaturas(ds_sensor, roms):

    return ??


def nivel_temperatura(temp):

    return ??
