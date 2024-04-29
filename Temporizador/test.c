#include "temporizador.h"
#include "pin_list.h"
#include <stdio.h>
#include "pico/stdlib.h"

int main()
{

    int pinsTime[] = {PIN_A, PIN_B, PIN_C, PIN_D, PIN_E, PIN_F, PIN_G, PIN_DIGITO1, PIN_DIGITO2};
    time_construct(pinsTime);


    keypad_init();

    int tiempo = 99;
    while(true){
        char opcion = read_keypad();
        printf("opcion: %c\n", opcion);
        int decena = tiempo / 10;
        int unidad = tiempo % 10;
        actualizar(decena, unidad);
        tiempo = decrementar();
    }
    return 0;
}