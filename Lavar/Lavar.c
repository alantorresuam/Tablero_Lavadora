#include "pico/stdlib.h"
#include "Lavar.h"

# define PIN_LAVAR  17

void lavar(){
    gpio_put(PIN_LAVAR , 17); // Encender el LED
}