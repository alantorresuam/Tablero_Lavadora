import fsm_actions
import shared_obj
from time import sleep
import machine
from machine import UART
from machine import I2C, Pin
from ssd1306 import SSD1306_I2C
from shared_obj import ev, fsm

# Configuración de pines UART
uart = machine.UART(0, baudrate=9600, tx=machine.Pin(12), rx=machine.Pin(13))
fsm_actions.init_fsm(fsm, ev)
i2c = I2C(0, sda=Pin(16), scl=Pin(17), freq=400000)
oled = SSD1306_I2C(128,64,i2c)
oled.fill(0)
oled.show()

state = 0

if __name__ == '__main__':
    while(True):
        print(state)
        comando = 'd'
        if uart.any():
            comando = uart.read(1).decode()
        if state == 0:
             if comando == 'K':
                while uart.any() == 0:
                    continue
                opcion_teclado = uart.read(1).decode()
                if(opcion_teclado == 'D'): # encender
                    print(opcion_teclado)
        elif state == 1:
            if comando == 'K':
                while uart.any() == 0:
                    continue
                opcion_teclado = uart.read(1).decode()
                if(opcion_teclado == 'D'): # encender
                    print(opcion_teclado)
        elif state == 2:
            if comando == 'K':
                while uart.any() == 0:
                    continue
                opcion_teclado = uart.read(1).decode()
                if(opcion_teclado == 'D'): # encender
                    print(opcion_teclado)
        elif state == 3:
            if comando == 'K':
                while uart.any() == 0:
                    continue
                opcion_teclado = uart.read(1).decode()
                if(opcion_teclado == 'D'): # encender
                    print(opcion_teclado)
        elif state == 4:
            if comando == 'K':
                while uart.any() == 0:
                    continue
                opcion_teclado = uart.read(1).decode()
                if(opcion_teclado == 'D'): # encender
                    print(opcion_teclado)
                    
        elif state == 5:
            if comando == 'K':
                while uart.any() == 0:
                    continue
                opcion_teclado = uart.read(1).decode()
                if(opcion_teclado == 'D'): # encender
                    print(opcion_teclado)