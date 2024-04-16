#include <stidio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define FIRST_GPIO 2
#define BUTTON_GPIO (FIRST_GPIO+7)

int bits[10] = {
    0x3f, // 0
    0x06, // 1
    0x5b, // 2
    0x4f, // 3
    0x66, // 4
    0x6d, // 5
    0x7d, // 6
    0x07, // 7
    0x7f, // 8
    0x67  // 9
};

void obtenerDigitosTiempo(int tiempo, int *digitos) {
    digitos[0] = tiempo / 1000;
    digitos[1] = (tiempo / 100) % 10;
    digitos[2] = (tiempo / 10) % 10;
    digitos[3] = tiempo / 10;
}

int main() {
    // Por escribir
}