#include "pico/stdlib.h"
#include "Tipo_lavado.h"


# define LED_PIN18 18
# define LED_PIN19 19
# define LED_PIN20 20

void delicado(){
    gpio_put(LED_PIN18, 1); // Encender el LED
}

void normal(){
    gpio_put(LED_PIN19, 1); // Encender el LED
}

void fuerte(){
    gpio_put(LED_PIN20, 1); // Encender el LED    
}

