from machine import ADC, Pin

def init_nivel_agua():
    adc = ADC(Pin(26))
    return adc

def leer_nivel_agua(adc):
    value_16bit = adc.read_u16()  
    value_10bit = value_16bit >> 6  
    return value_10bit

def interpretar_nivel_agua(value):
    return #
