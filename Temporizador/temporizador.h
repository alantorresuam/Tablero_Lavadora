#include <stdint.h>
#include <stdio.h>

#define PINS_SIZE_TIME 9
#define DIGIT_SIZE 10


/*@brief Pines para el display */
static uint32_t pins[PINS_SIZE_TIME];

/*@brief Digitos del display*/
static uint32_t digits[DIGIT_SIZE];

static uint32_t mask;

static uint32_t const time_delay = 10;

static uint32_t digito_unidades;

static uint32_t digito_decenas;

static uint32_t digito1;

static  uint32_t digito2;

void time_construct(int a[]);

void time_init();

/*@brief Metodo para decrementar en uno el temporizador*/
int decrementar();

/*@brief Metodo para actualizar el display*/
void actualizar(int decenas, int unidades);
