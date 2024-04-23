#include <stdbool.h>
#include "Pausa_play.h"
#include "pico/stdlib.h"

# define LED_PIN22  22
# define BUTTON_PIN1 1

bool pausa_play(bool pausado){
    if(!gpio_get(BUTTON_PIN1)){
        sleep_ms(1500);
        if (!gpio_get(BUTTON_PIN1) && pausado){
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
    gpio_put(LED_PIN22, 1); // Pausar el LED
}

void play(){
    gpio_put(LED_PIN22, 0); // Play de el LED
}