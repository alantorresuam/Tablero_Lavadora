#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/gpio.h"

#define FIRST_GPIO_LED 10
#define LAST_GPIO_LED 22

int main() {
    stdio_init_all(); 
    sleep_ms(1000); 

    
    keypad_init();
    
    // We could use gpio_set_dir_out_masked() here
    for (int gpio = FIRST_GPIO_LED; gpio <= LAST_GPIO_LED; gpio++) {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
    }

    while (1) {
        // Leer el estado del teclado
        char opcion = read_keypad();

        switch (opcion) {
        case '1':
            printf("Lavado Delicado.\n");
            break;
        case '2':
            printf("Lavado normal.\n");
            break;
        case '3':
            printf("Lavado Fuerte\n"); 
            break;
        case '4':
            printf("Carga Ligera.\n");
            break;
        case '5':
            printf("Carga Mediana.\n");
            break;
        case '6':
            printf("Carga Pesada.\n"); 
            break;
        case '7':
            printf("Lavar.\n");
            break;
        case '8':
            printf("Enjuagar.\n");
            break;
        case '9':
            printf("Centrifugar.\n");
            break;
        case 'A':
            printf("Agua Fria.\n");
            fria();
            break;
        case 'B':
            printf("Agua Tibia.\n");
            tibia();
            break;
        case 'C':
            printf("Agua Caliente.\n");
            caliente();
            break;
        case 'D':
            printf("EncenderApagar.\n");
            break;
        case '*':
            printf("Pausa/play.\n");
            break;
        default:
            break;
    }

       
        sleep_ms(50);
    }

    return 0;
}