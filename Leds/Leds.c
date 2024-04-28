#include <stdbool.h>
#include "Leds.h"
#include "pico/stdlib.h"


// INICIO ENCENDER_APAGAR
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
    gpio_put(PIN_ENCENDIDO_APAGADO, 1); // Encender el LED
}

void apagar(){
    gpio_put(PIN_ENCENDIDO_APAGADO, 0); // Apagar el LED
}
// FIN ENCENDER_APAGAR


// INICIO TEMPERATURA (Agua caliente/tibia/fría)
void fria(){
    gpio_put(PIN_TEMPERATURA_FRIA, 1); // Encender el LED
    gpio_put(PIN_TEMPERATURA_TIBIA, 0);
    gpio_put(PIN_TEMPERATURA_CALIENTE, 0);
}

void tibia(){
    gpio_put(PIN_TEMPERATURA_TIBIA, 1); // Encender el LED
    gpio_put(PIN_TEMPERATURA_FRIA, 0);
    gpio_put(PIN_TEMPERATURA_CALIENTE, 0);
}

void caliente(){
    gpio_put(PIN_TEMPERATURA_CALIENTE, 1); // Encender el LED  
    gpio_put(PIN_TEMPERATURA_FRIA, 0);
    gpio_put(PIN_TEMPERATURA_TIBIA, 0);  
}
// FIN TEMPERATURA (Agua caliente/tibia/fría)


// INICIO LAVAR
void lavar(){
    gpio_put(PIN_LAVAR , 17); // Encender el LED
}
// FIN LAVAR


// INICIO ENJUAGAR
void enjuagar(){
    gpio_put(PIN_ENJUAGAR, 16); // Encender el LED
}
// FIN ENJUAGAR


// INICIO CENTRIFUGADO
void centrifugado(){
    gpio_put(PIN_CENTRIFUGAR, 1); // Encender el LED
}
// FIN CENTRIFUGADO


// INICIO PAUSA_PLAY
# define BUTTON_PIN2 2

bool pausa_play(bool pausado){
    if(!gpio_get(BUTTON_PIN2)){
        sleep_ms(1500);
        if (!gpio_get(BUTTON_PIN2) && pausado){
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
    gpio_put(PIN_PAUSA_PLAY, 1); // Pausar el LED
}

void play(){
    gpio_put(PIN_PAUSA_PLAY, 0); // Play de el LED
}
// FIN PAUSA_PLAY


// INICIO TIPO_LAVADO (normal/fuerte/ropa delicada)
void delicado(){
    gpio_put(PIN_LAVADO_DELICADO, 1); // Encender el LED
}

void normal(){
    gpio_put(PIN_LAVADO_NORMAL, 1); // Encender el LED
}

void fuerte(){
    gpio_put(PIN_LAVADO_FUERTE, 1); // Encender el LED    
}
// FIN TIPO_LAVADO (normal/fuerte/ropa delicada)


// INCIO CARGA (liviana/media/pesada)
void liviana(){
    gpio_put(PIN_CARGA_MEDIANA, 0); // Apagar el LED
    gpio_put(PIN_CARGA_PESADA, 0); // Apagar el LED
    gpio_put(PIN_CARGA_LIVIANA, 1); // Encender el LED
}

void media(){
    gpio_put(PIN_CARGA_LIVIANA, 0); // Apagar el LED
    gpio_put(PIN_CARGA_PESADA, 0); // Apagar el LED
    gpio_put(PIN_CARGA_MEDIANA, 1); // Encender el LED
}

void pesada(){
    gpio_put(PIN_CARGA_LIVIANA, 0); // Apagar el LED
    gpio_put(PIN_CARGA_MEDIANA, 0); // Apagar el LED
    gpio_put(PIN_CARGA_PESADA, 1); // Encender el LED 
}
// FIN CARGA (liviana/media/pesada)