from machine import ADC, Pin

def init_nivel_agua():
    """Inicializa el sensor de nivel de agua."""
    adc = ADC(Pin(26))
    return adc

def leer_nivel_agua(adc):
    """Lee el valor analógico del sensor de nivel de agua.

    Args:
        adc: El objeto ADC configurado para el sensor.

    Regresa:
        int: El valor analógico leído del sensor (0-1023).
    """
    value_16bit = adc.read_u16()  
    value_10bit = value_16bit >> 6  
    return value_10bit

def interpretar_nivel_agua(value):
    """Interpreta el valor leído del sensor de nivel de agua y determina el nivel.

    Args:
        value (int): El valor analógico leído del sensor (0-1023).

    Regresa:
        str: 'bajo', 'medio' o 'alto' basado en el nivel de agua.
    """
    if value < 300:
        return "seco"
    elif 300 <= value < 530:
        return "bajo"
    elif 530 <= value < 560:
        return "medio"
    else:
        return "alto"
