#include "pico/stdlib.h"
#include "Tipo_lavado.h"


# define LED_PIN11 11 
# define LED_PIN12 12
# define LED_PIN13 13

void delicado(){
    gpio_put(LED_PIN11, 1); // Encender el LED
}

void normal(){
    gpio_put(LED_PIN12, 1); // Encender el LED
}

void fuerte(){
    gpio_put(LED_PIN13, 1); // Encender el LED    
}

