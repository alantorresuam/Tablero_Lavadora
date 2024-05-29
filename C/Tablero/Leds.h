#include <stdint.h>
#include <stdio.h>

#define PINS_SIZE_LEDS 5

static uint32_t leds[PINS_SIZE_LEDS];

void construct_leds();

void leds_init();

// INICIO ENCENDER_APAGAR
/**
 * @brief Turns off the washing machine.
 */
void apagar();

/**
 * @brief Turns on the washing machine.
 */
void encender();
// FIN ENCENDER_APAGAR


// INICIO PAUSA_PLAY
/**
 * @brief Turns in play the washing machine.
 */
void play();

/**
 * @brief Turns in pausa the washing machine.
 */
void pausa();
// FIN PAUSA_PLAY


//  INICIO LAVAR
void lavar();
//  FIN LAVAR


//  INICIO ENJUAGAR
void enjuagar();
//  FIN ENJUAGAR


// INICIO CENTRIFUGADO
void centrifugado();
// FIN CENTRIFUGADO


//  INICIO TEMPERATURA (Agua caliente/tibia/fría)
/**
 * @brief ENCENDER LED DE AGUA FRIA.
 */
void fria();

/**
 * @brief ENCENDER LED DE AGUA TIBIA.
 */
void tibia();

/**
 * @brief ENCENDER LED DE AGUA CALIENTE.
 */
void caliente();
//  FIN TEMPERATURA (Agua caliente/tibia/fría)


// INICIO TIPO_LAVADO (normal/fuerte/ropa delicada)
/**
 * @brief Turns on the delicate washing mode LED.
 */
void delicado();

/**
 * @brief Turns on the normal washing mode LED.
 */
void normal();

/**
 * @brief Turns on the strong washing mode LED.
 */
void fuerte();
// FIN TIPO_LAVADO (normal/fuerte/ropa delicada)


// INCIO CARGA (liviana/media/pesada)
/**
 * @brief Turns on the light load LED.
 */
void liviana();

/**
 * @brief Turns on the medium load LED.
 */
void media();

/**
 * @brief Turns on the heavy load LED.
 */
void pesada();
// FIN CARGA (liviana/media/pesada)

void apagar_todos_los_leds();

void apagar_procesos();
