#include <stdbool.h>
#include "pico/stdlib.h"

#define LIGERA 0
#define MEDIA 1
#define PESADA 2

#define LED_1_PIN 10
#define LED_2_PIN 11
#define BOTON_PIN 15


int estado_carga = LIGERA

void seleccionar_carga() {
    estado_carga = (estado_carga + 1) % 3;
    switch(estado_carga) {
        case LIGERA:
        // Pendiente
        case MEDIA:
        // Pendiente
        case PESADA:
        // Pendiente
    }
}

void encender_led() {
    //Pendiente
}

bool verificar_boton_presionado() {
    //Pendiente
}

int main() {
    //Pendiente
}