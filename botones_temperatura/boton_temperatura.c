#include "pico/stdlib.h"
#include "boton_temperatura.h"


 
# define LED_PIN12 12
# define LED_PIN13 13
# define LED_PIN14 14

void fria(){
    gpio_put(LED_PIN12, 1); // Encender el LED
    gpio_put(LED_PIN13, 0);\
    gpio_put(LED_PIN14, 0);
}

void tibia(){
    gpio_put(LED_PIN13, 1); // Encender el LED
    gpio_put(LED_PIN12, 0);
    gpio_put(LED_PIN14, 0);
}

void caliente(){
    gpio_put(LED_PIN14, 1); // Encender el LED  
    gpio_put(LED_PIN12, 0);
    gpio_put(LED_PIN13, 0);  
}