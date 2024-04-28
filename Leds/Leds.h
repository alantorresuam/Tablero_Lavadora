#define PIN_CARGA_LIVIANA 10			// Carga liviana
#define PIN_CARGA_MEDIANA 11			// Carga mediana
#define PIN_CARGA_PESADA 12			    // Carga pesada
#define PIN_TEMPERATURA_FRIA 13		    // Temperatura fría
#define PIN_TEMPERATURA_TIBIA 14		// Temperatura tibia
#define PIN_TEMPERATURA_CALIENTE 15	    // Temperatura caliente
#define PIN_ENJUAGAR 16				    // Enjuagar
#define PIN_LAVAR 17					// Lavar
#define PIN_ENCENDIDO_APAGADO 18		// Encendido/Apagado
#define PIN_LAVADO_DELICADO 19		    // Lavado delicado
#define PIN_LAVADO_NORMAL 20			// Lavado normal
#define PIN_LAVADO_FUERTE 21			// Lavado fuerte
#define PIN_CENTRIFUGAR 22			    // Centrifugar
#define PIN_PAUSA_PLAY 23				// Pausa/Play

// INICIO ENCENDER_APAGAR
/**
 * @brief This function turns on the washing machine and indicates that the washing machine is on.
 * @return true if the washing machine is successfully turned on, false otherwise.
 */
bool encender_apagar(bool encendido);

/**
 * @brief Turns off the washing machine.
 */
void apagar();

/**
 * @brief Turns on the washing machine.
 */
void encender();
// FIN ENCENDER_APAGAR


//  INICIO Temperatura (Agua caliente/tibia/fría)
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
//  FIN Temperatura (Agua caliente/tibia/fría)


//  INICIO LAVAR
void lavar();
//  FIN LAVAR


//  INICIO ENJUAGAR
void enjuagar();
//  FIN ENJUAGAR


// INICIO CENTRIFUGADO
void centrifugado();
// FIN CENTRIFUGADO


// INICIO PAUSA_PLAY
bool pausa_play(bool encendido);

/**
 * @brief Turns in play the washing machine.
 */
void play();

/**
 * @brief Turns in pausa the washing machine.
 */
void pausa();
// FIN PAUSA_PLAY


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