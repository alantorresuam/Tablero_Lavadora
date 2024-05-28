from sonidos_zumbador import sonar_encendido, sonar_apagado, sonar_final, sonar_botón, sonar_cancion_1, sonar_cancion_2, sonar_cancion_3
import time

if __name__ == "__main__":
    print("Probando sonidos del zumbador...")

    print("Sonido para encendido...")
    sonar_encendido()
    time.sleep(1)

    print("Sonido para apagado...")
    sonar_apagado()
    time.sleep(1)

    print("Sonido para fin...")
    sonar_final()
    time.sleep(1)

    print("Sonido para boton presionado...")
    sonar_botón()
    time.sleep(1)

#    print("Sonando cancion 1...")
#    sonar_cancion_1()
#    time.sleep(1)

#    print("Sonando cancion 2...")
#    sonar_cancion_2()
#    time.sleep(1)

    print("Sonando cancion 3...")
    sonar_cancion_3()
    time.sleep(1)
