from machine import Pin, PWM
import time

# Definir el pin del buzzer
buzzer_pin = Pin(11, Pin.OUT)
buzzer = PWM(buzzer_pin)

# Definir las notas y duraciones
CL = [0, 131, 147, 165, 175, 196, 211, 248]
CM = [0, 262, 294, 330, 350, 393, 441, 495]
CH = [0, 525, 589, 661, 700, 786, 882, 990]

song_1 = [CM[3], CM[5], CM[6], CM[3], CM[2], CM[3], CM[5], CM[6],
          CH[1], CM[6], CM[5], CM[1], CM[3], CM[2], CM[2], CM[3],
          CM[5], CM[2], CM[3], CM[3], CL[6], CL[6], CL[6], CM[1],
          CM[2], CM[3], CM[2], CL[7], CL[6], CM[1], CL[5]]

beat_1 = [1, 1, 3, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 3, 1,
          1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 3]

song_2 = [CM[1], CM[1], CM[1], CL[5], CM[3], CM[3], CM[3], CM[1],
          CM[1], CM[3], CM[5], CM[5], CM[4], CM[3], CM[2], CM[2],
          CM[3], CM[4], CM[4], CM[3], CM[2], CM[3], CM[1], CM[1],
          CM[3], CM[2], CL[5], CL[7], CM[2], CM[1]]

beat_2 = [1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 3, 1, 1, 2,
          2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 3]

song_3 = [CM[6], CM[7], CH[1], CH[3], CH[1], CH[1], CH[2], CM[7],
          CM[7], CH[1], CM[6], CM[6], CM[7], CH[3], CH[1], CH[1],
          CH[2], CM[7], CM[7], CH[1], CM[6], CM[6], CM[7], CH[3], 
          CH[1], CH[1], CH[2], CM[7], CM[7], CH[1], CM[6], CM[6], 
          CM[7], CH[3], CH[2], CH[1], CH[3], CH[2], CH[1],
          CM[7], CM[7], CM[6]]

beat_3 = [0.6, 0.6, 0.6, 1.5, 0.6, 0.6, 1, 0.6, 0.6, 1, 0.6, 0.6, 1.5, 1, 0.6, 0.6, 1, 0.6,
          0.6, 1, 0.6, 0.6, 1.5, 1, 0.6, 0.6, 1, 0.6, 0.6, 1, 0.6, 0.6, 2, 0.6, 0.6, 0.6, 
          0.6, 0.6, 0.7, 1, 0.3, 1.5]

def beep(frequency, duration):
    if frequency == 0:
        time.sleep(duration)
    else:
        buzzer.freq(frequency)
        buzzer.duty_u16(32768)  # Duty cycle al 50% en un rango de 16 bits
        time.sleep(duration)
        buzzer.duty_u16(0)      # Apagar el buzzer
        time.sleep(0.05)

def sonar_encendido():
    for _ in range(3):
        beep(262, 0.1)
        time.sleep(0.1)

def sonar_apagado():
    for _ in range(2):
        beep(330, 0.2)
        time.sleep(0.2)

def sonar_final():
    for _ in range(5):
        beep(262, 0.05)
        time.sleep(0.05)

def sonar_botón():
    beep(330, 0.1)

def sonar_cancion(song, beat):
    for note, duration in zip(song, beat):
        beep(note, duration * 0.5)

def sonar_cancion_1():
    sonar_cancion(song_1, beat_1)

def sonar_cancion_2():
    sonar_cancion(song_2, beat_2)

def sonar_cancion_3():
    sonar_cancion(song_3, beat_3)