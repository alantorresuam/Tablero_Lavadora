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
    ds_sensor.convert_temp()
    time.sleep_ms(750)
    temps = [ds_sensor.read_temp(rom) for rom in roms]
    return temps

def nivel_temperatura(temp):
    if temp < 18:
        return "baja"
    elif 18 <= temp <= 24:
        return "media"
    else:
        return "alta"

