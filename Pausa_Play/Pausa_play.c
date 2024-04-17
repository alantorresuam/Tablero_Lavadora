#include "pico/stdlib.h"
#include "Pausa_play.h"


# define LED_PIN22 22

void pausa(){
    gpio_put(LED_PIN22, 1); // Encender el LED
}