from sonidos_zumbador import sonar_encendido, sonar_apagado, sonar_final, sonar_botón, sonar_cancion_1, sonar_cancion_2, sonar_cancion_3
import time

if __name__ == "__main__":
    print("Testing buzzer sounds...")

    print("Sound for power on...")
    sonar_encendido()
    time.sleep(1)

    print("Sound for power off...")
    sonar_apagado()
    time.sleep(1)

    print("Sound for final notification...")
    sonar_final()
    time.sleep(1)

    print("Sound for button press...")
    sonar_botón()
    time.sleep(1)

#    print("Playing song 1...")
#    sonar_cancion_1()
#    time.sleep(1)

#    print("Playing song 2...")
#    sonar_cancion_2()
#    time.sleep(1)

    print("Playing song 3...")
    sonar_cancion_3()
    time.sleep(1)
