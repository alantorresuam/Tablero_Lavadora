#include <stdbool.h>
#include "Pausa_Play.h"
#include "pico/stdlib.h"

# define LED_PIN  8
# define BUTTON_PIN 9

bool pausa_Play(bool pausado){
    if(!gpio_get(BUTTON_PIN)){
        sleep_ms(1500);
        if (!gpio_get(BUTTON_PIN) && pausado){
            play();
            return false;
        } else if(!pausado){
            pausa();
            return true;
        }
    }
    return pausado;
}

void pausa(){
    gpio_put(LED_PIN, 1); // Cuando da pausa se enciende el LED
}

void play(){
    gpio_put(LED_PIN, 0); // Cuando da play se apaga el LED
}