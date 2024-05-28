from machine import Pin
import time

# Set up the pin
buzzer_pin = Pin(16, Pin.OUT)

def single_beep():
    for pulse in range(60):
        buzzer_pin.on()
        time.sleep(0.001)
        buzzer_pin.off()
        time.sleep(0.001)
    time.sleep(0.02)

# Example main script calling the single_beep function
if __name__ == "__main__":
    print("Beeping once...")
    single_beep()
