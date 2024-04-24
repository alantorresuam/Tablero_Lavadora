#include "pico/stdlib.h"
#include "centrifugado.h"

# define LED_PIN23 23

void centrifugado(){
    gpio_put(LED_PIN23, 1); // Encender el LED
}