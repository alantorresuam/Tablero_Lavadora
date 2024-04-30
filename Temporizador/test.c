#include "temporizador.h"
#include "pin_list.h"
#include <stdio.h>
#include "pico/stdlib.h"

int main()
{
    int pinsTime[] = {PIN_A, PIN_B, PIN_C, PIN_D, PIN_E, PIN_F, PIN_G, PIN_DIGITO1, PIN_DIGITO2};
    time_construct(pinsTime);

    time_init();

    int tiempo = 99;
    int segundo = 0;
    while(true){
        int decena = tiempo / 10;
        int unidad = tiempo % 10;
        actualizar(decena, unidad);
        segundo += 20;
        if (segundo == 1000){
            tiempo = decrementar();
            segundo = 0;
        }
    }
    return 0;
}
