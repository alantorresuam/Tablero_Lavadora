#include "pico/stdlib.h"
#include "Lavar.h"

# define LED_PIN16 16

void lavar(){
    gpio_put(LED_PIN16, 1); // Encender el LED
}