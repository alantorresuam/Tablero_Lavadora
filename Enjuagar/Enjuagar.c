#include "pico/stdlib.h"
#include "Enjuagar.h"

# define LED_PIN15 15

void enjuagar(){
    gpio_put(LED_PIN15, 1); // Encender el LED
}