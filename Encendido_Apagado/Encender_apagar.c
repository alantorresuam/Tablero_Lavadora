#include <stdbool.h>
#include "Encender_Apagar.h"
#include "pico/stdlib.h"

# define LED_PIN17  17
# define BUTTON_PIN1 1

bool encender_apagar(bool encendido){
    if(!gpio_get(BUTTON_PIN1)){
        sleep_ms(1500);
        if (!gpio_get(BUTTON_PIN1) && encendido){
            apagar();
            return false;
        } else if(!encendido){
            encender();
            return true;
        }
    }
    return encendido;
}

void encender(){
    gpio_put(LED_PIN17, 1); // Encender el LED
}

void apagar(){
    gpio_put(LED_PIN17, 0); // Apagar el LED
}