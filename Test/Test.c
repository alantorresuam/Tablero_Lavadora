#include "Teclado.h"
#include "pin_list_keypad.h"
#include <stdio.h>
#include "pico/stdlib.h"

int main()
{
    stdio_init_all();
    int pinsTeclado[]= {PIN_L1, PIN_L2, PIN_L3, PIN_L4, PIN_C1, PIN_C2, PIN_C3, PIN_C4};
    keypad_construct(pinsTeclado);
    keypad_init();

    while(true){
        char opcion = read_keypad();
        if(opcion != '\0'){
            printf("opcion: %c\n", opcion);
        }
    }
    return 0;
}
