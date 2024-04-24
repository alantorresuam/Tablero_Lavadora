#include "pico/stdlib.h"
#include "Enjuagar.h"

# define PIN_ENJUAGAR 16

void enjuagar(){
    gpio_put(PIN_ENJUAGAR, 16); // Encender el LED
}