#include <stdint.h>

#define ROWS 4
#define COLS 4

/*@brief Pines para las filas del teclado matricial*/
static uint32_t ROWS_PINS[ROWS];

/*@brief Pines para las columnas del teclado matricial*/
static uint32_t COLS_PINS[COLS];

/*@brief El tiempo que el teclado matricial retrasa la lectura de la entrada*/
static uint32_t const tm_delay = 50;

/*@brief Llaves del teclado matricial*/
static char KEYS[ROWS][COLS];

/*@brief Inicializa los pines y las llaves que utilizara el teclado matricial*/
void keypad_construct(const int a[]);

/*@brief Inicializa los pines que utilizara el teclado matricial*/
void keypad_init();

/*@brief Lee el valor de salida de un teclado matricial*/
char read_keypad();