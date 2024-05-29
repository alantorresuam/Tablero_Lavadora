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

procesos = ['Lavando', 'Enjuagando', 'Centrifugando']
lavados = ['Lavado delicado', 'Lavado normal', 'Lavado fuerte']
cargas = ["Carga ligera", "Carga mediana", "Carga pesada",]
temperaturas = ["Agua fria", "Agua tibia", "Agua caliente",]

lavar = False
enjuagar = False
centrifugar = False

estado_anterior = 0
Iniciar_temporizador = False


if __name__ == '__main__':
    lavado, carga, temperatura = lavados[1], cargas[1], temperaturas[1]
    print(f"Estado: {state}")
    while(True):
        comando = 'd'
        if uart.any():
            comando = uart.read(1).decode()
        if state == 0:
            if comando == 'K':
                while uart.any() == 0:
                    continue
                opcion_teclado = uart.read(1).decode()
                if(opcion_teclado == 'D'): # encender
                    fsm.compute_next_state(shared_obj.ev['encender'])  
                    state = fsm.get_current_state()
                    print(f"Estado: {state}")
                    inicio = 0;     
                    while inicio < 3:
                        oled.text("bienvenido", 30, 20)
                        oled.show()
                        sleep(1)
                        inicio += 1
                    oled.fill(0)
                    oled.show()
        elif state == 1:
            oled.fill(0)
            oled.text(f"Selecciona", 20, 0)
            oled.text(f"una opcion", 20, 8)
            if(lavar):
                oled.text(f"Lavar", 20, 20)
            if(enjuagar):
                oled.text(f"Enjuagar", 20, 30)
            if(centrifugar):
                oled.text(f"Centrifugar", 20, 40)
            oled.show()                            
            if comando == 'K':
                while uart.any() == 0:
                    continue
                opcion_teclado = uart.read(1).decode()
                if(opcion_teclado == '7'): # lavar
                    lavar = True
                if(opcion_teclado == '8'): # enjuagar
                    enjuagar = True
                if(opcion_teclado == '9'): # centrifugar
                    centrifugar = True
                    
                if lavar or enjuagar:
                    
                    if(opcion_teclado == '1'): # lavado delicado
                        lavado = lavados[0]
                    if(opcion_teclado == '2'): # lavado normal
                        lavado = lavados[1]
                    if(opcion_teclado == '3'): # lavado fuerte
                        lavado = lavados[2]
                        
                    if(opcion_teclado == '4'): # carga ligera
                        carga = cargas[0]
                    if(opcion_teclado == '5'): # carga mediana
                        carga = cargas[1]
                    if(opcion_teclado == '6'): # carga pesada
                        carga = cargas[2]
                        
                    if(opcion_teclado == 'A'): # agua fria
                        temperatura = temperaturas[0]
                    if(opcion_teclado == 'B'): # agua tibia
                        temperatura = temperaturas[1]
                    if(opcion_teclado == 'C'): # agua caliente
                        temperatura = temperaturas[2]
                    
                if opcion_teclado == '*':
                    if lavar:
                        fsm.compute_next_state(shared_obj.ev['lavar'])  # play lavar
                        state = fsm.get_current_state()
                        print(f"Estado: {state}")
                        Iniciar_temporizador = True
                    elif enjuagar:
                        fsm.compute_next_state(shared_obj.ev['enjuagar'])  # play enjuagar
                        state = fsm.get_current_state()
                        print(f"Estado: {state}")
                        Iniciar_temporizador = True
                    elif centrifugar:
                        fsm.compute_next_state(shared_obj.ev['centrifugar'])  # play centrifugar
                        state = fsm.get_current_state()
                        print(f"Estado: {state}")
                        Iniciar_temporizador = True

                    
                if(opcion_teclado == '#'): # apagar
                    fsm.compute_next_state(ev['apagar'])  
                    state = fsm.get_current_state()
                    print(f"Estado: {state}")
                    lavado, carga, temperatura = lavados[1], cargas[1], temperaturas[1]
                    lavar = False
                    enjuagar = False
                    centrifugar = False
                    uart.write("O")
                    oled.fill(0)
                    oled.show()
                    
        elif state == 2:
            if(Iniciar_temporizador):
                uart.write(b'I') # Iniciar temporizador
                Iniciar_temporizador = False
            oled.fill(0)
            oled.text(f"Lavando...", 20, 8)
            oled.text(f"{lavado}", 20, 20)
            oled.text(f"{carga}", 20, 30)
            oled.text(f"{temperatura}", 20, 40)
            oled.show()
            if comando == 'T':
                if not centrifugar and not enjuagar:
                    fsm.compute_next_state(ev['lavado fin'])
                    lavado, carga, temperatura = lavados[1], cargas[1], temperaturas[1]
                    state = fsm.get_current_state()
                    print(f"Estado: {state}")
                    lavar = False
                    enjuagar = False
                    centrifugar = False
                    oled.fill(0)
                    oled.text("Proceso terminado", 0, 8)
                    oled.show()
                    sleep(3)
                elif enjuagar:
                    fsm.compute_next_state(ev['lavar y enjuagar'])
                    state = fsm.get_current_state()
                    print(f"Estado: {state}")
                    Iniciar_temporizador = True
                elif centrifugar:
                    fsm.compute_next_state(ev['lavar y centrifugar'])
                    state = fsm.get_current_state()
                    print(f"Estado: {state}")
                    Iniciar_temporizador = True

                    
            if comando == 'K':
                while uart.any() == 0:
                    continue
                opcion_teclado = uart.read(1).decode()
                if opcion_teclado == '0':
                    estado_anterior = 2
                    fsm.compute_next_state(ev['pausar'])
                    state = fsm.get_current_state()
                    print(f"Estado: {state}")
                if(opcion_teclado == '#'): # apagar
                    fsm.compute_next_state(ev['apagar'])  
                    state = fsm.get_current_state()
                    print(f"Estado: {state}")
                    lavado, carga, temperatura = lavados[1], cargas[1], temperaturas[1]
                    lavar = False
                    enjuagar = False
                    centrifugar = False
                    uart.write("O")
                    oled.fill(0)
                    oled.show()
                    
                
        elif state == 3:
            if(Iniciar_temporizador):
                uart.write(b'I') # Iniciar temporizador
                Iniciar_temporizador = False
            oled.fill(0)
            oled.text(f"Enjuagando...", 20, 8)
            oled.text(f"{carga}", 20, 20)
            oled.text(f"{temperatura}", 20, 30)
            oled.show()
            if comando == 'T':
                if (not centrifugar):
                    fsm.compute_next_state(ev['enjuagado fin'])
                    lavado, carga, temperatura = lavados[1], cargas[1], temperaturas[1]
                    state = fsm.get_current_state()
                    print(f"Estado: {state}")  
                    lavar = False
                    enjuagar = False
                    centrifugar = False
                    oled.fill(0)
                    oled.text(f"Proceso ", 20, 8)
                    oled.text(f"terminado", 20, 20)
                    oled.show()   
                    sleep(3)               
                else:
                    fsm.compute_next_state(ev['centrifugar'])
                    state = fsm.get_current_state()
                    print(f"Estado: {state}")
                    Iniciar_temporizador = True
                    
            if comando == 'K':
                while uart.any() == 0:
                    continue
                opcion_teclado = uart.read(1).decode()
                if opcion_teclado == '0':
                    fsm.compute_next_state(ev['pausar'])
                    estado_anterior = 3
                    state = fsm.get_current_state()
                    print(f"Estado: {state}")
                if(opcion_teclado == '#'): # apagar
                    fsm.compute_next_state(ev['apagar'])  
                    state = fsm.get_current_state()
                    print(f"Estado: {state}")
                    lavado, carga, temperatura = lavados[1], cargas[1], temperaturas[1]
                    lavar = False
                    enjuagar = False
                    centrifugar = False
                    uart.write("O")
                    oled.fill(0)
                    oled.show()
                    
        elif state == 4:
            if(Iniciar_temporizador):
                uart.write(b'I') # Iniciar temporizador
                Iniciar_temporizador = False
            oled.fill(0)
            oled.text(f"Centrifugando...", 8, 8)
            oled.text(f"{carga}", 20, 20)
            oled.show()
            if comando == 'T':
                fsm.compute_next_state(ev['centrifugado fin'])
                lavado, carga, temperatura = lavados[1], cargas[1], temperaturas[1]
                state = fsm.get_current_state()
                print(f"Estado: {state}") 
                lavar = False
                enjuagar = False
                centrifugar = False
                oled.fill(0)
                oled.text(f"Proceso ", 20, 8)
                oled.text(f"terminado", 20, 20)
                oled.show() 
                sleep(3)                               
            if comando == 'K':
                while uart.any() == 0:
                    continue
                opcion_teclado = uart.read(1).decode()
                if opcion_teclado == '0':
                    fsm.compute_next_state(ev['pausar'])
                    estado_anterior = 4
                    state = fsm.get_current_state()
                    print(f"Estado: {state}")
                if(opcion_teclado == '#'): # apagar
                    fsm.compute_next_state(ev['apagar'])  
                    state = fsm.get_current_state()
                    print(f"Estado: {state}")
                    lavado, carga, temperatura = lavados[1], cargas[1], temperaturas[1]
                    lavar = False
                    enjuagar = False
                    centrifugar = False
                    uart.write("O")
                    oled.fill(0)
                    oled.show()
                    
        elif state == 5:
            uart.write(b"P")
            oled.fill(0)
            oled.text(f"Pausa...", 20, 8)
            oled.text(f"Proceso: {procesos[estado_anterior - 2]}", 0, 20)
            oled.show()
            if comando == 'K':
                while uart.any() == 0:
                    continue
                opcion_teclado = uart.read(1).decode()
                if opcion_teclado == '*':
                    if estado_anterior == 2:
                        fsm.compute_next_state(ev['lavando'])
                        state = fsm.get_current_state()
                        print(f"Estado: {state}")
                        uart.write(b"p")
                    if estado_anterior == 3:
                        fsm.compute_next_state(ev['enjuagando'])
                        state = fsm.get_current_state()
                        print(f"Estado: {state}")
                        uart.write(b"p")
                    if estado_anterior == 4:
                        fsm.compute_next_state(ev['centrifugando'])
                        state = fsm.get_current_state()
                        print(f"Estado: {state}")
                        uart.write(b"p")
                if(opcion_teclado == '#'): # apagar
                    fsm.compute_next_state(ev['apagar'])  
                    state = fsm.get_current_state()
                    print(f"Estado: {state}")
                    lavado, carga, temperatura = lavados[1], cargas[1], temperaturas[1]
                    lavar = False
                    enjuagar = False
                    centrifugar = False
                    uart.write("O")
                    oled.fill(0)
                    oled.show()
                        