#include "pico/stdlib.h"
#include "carga.h"


# define LED_PIN10 10
# define LED_PIN11 11
# define LED_PIN12 12

void liviana(){
    gpio_put(LED_PIN11, 0); // Apagar el LED
    gpio_put(LED_PIN12, 0); // Apagar el LED
    gpio_put(LED_PIN10, 1); // Encender el LED
}

void media(){
    gpio_put(LED_PIN10, 0); // Apagar el LED
    gpio_put(LED_PIN12, 0); // Apagar el LED
    gpio_put(LED_PIN11, 1); // Encender el LED
}

void pesada(){
    gpio_put(LED_PIN10, 0); // Apagar el LED
    gpio_put(LED_PIN11, 0); // Apagar el LED
    gpio_put(LED_PIN12, 1); // Encender el LED 
}