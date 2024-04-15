#include <stdbool.h>
#include "Encender_Apagar.h"
#include "pico/stdlib.h"

# define LED_PIN  10 
# define BUTTON_PIN 15

bool encender_apagar(bool encendido){
    if(!gpio_get(BUTTON_PIN)){
        sleep_ms(1500);
        if (!gpio_get(BUTTON_PIN) && encendido){
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
    gpio_put(LED_PIN, 1); // Encender el LED
}

void apagar(){
    gpio_put(LED_PIN, 0); // Apagar el LED
}