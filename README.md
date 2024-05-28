# Conexión de Dos Raspberry Pi Usando UART para la Implementación de una Lavadora
## Introducción
Este proyecto tiene como objetivo conectar dos Raspberry Pi mediante UART para controlar una lavadora. Se utiliza una máquina de estados finitos (FSM) para gestionar las diferentes fases del ciclo de lavado, enjuague y centrifugado. Además, se implementa un teclado matricial para la entrada de comandos y una pantalla OLED para mostrar información al usuario.

## Hardware Utilizado
2 Raspberry Pi
Módulo UART
Pantalla OLED SSD1306
Teclado matricial
Coneccion de taclado matrcial desde el otro lado de la comunicacion
Pines GPIO para conexiones
## Conexiones
- UART
- TX (Transmisión): GPIO 12
- RX (Recepción): GPIO 13
- I2C
- SDA: GPIO 16
- SCL: GPIO 17
- Máquina de Estados Finita (FSM)
- La FSM gestiona los diferentes estados y transiciones del ciclo de lavado. Los estados incluyen encendido, selección de opciones, lavado, enjuague, centrifugado, pausa y apagado.

## Eventos
Los eventos que desencadenan transiciones en la FSM son:

- encender: Inicia la lavadora
- apagar: Apaga la lavadora
- enjuagar: Inicia el proceso de enjuague
- centrifugar: Inicia el proceso de centrifugado
- lavado fin: Finaliza el proceso de lavado
- lavar y enjuagar: Transición de lavado a enjuague
- lavar y centrifugar: Transición de lavado a  centrifugado
- pausar: Pausa el proceso actual
- enjuagado fin: Finaliza el proceso de enjuague
- centrifugado fin: Finaliza el proceso de  centrifugado
- lavando: Estado de lavado
- enjuagando: Estado de enjuague
- centrifugando: Estado de centrifugado
- lavar: Inicia el proceso de lavado
- Transiciones
- Las reglas de transición definen cómo la FSM  cambia de un estado a otro en respuesta a los  eventos. Las transiciones principales incluyen:

Del estado apagado al estado encendido y viceversa.
Del estado selección de opciones a los estados lavado, enjuague y centrifugado.
Del estado lavado a lavado fin, enjuague o centrifugado.
Del estado enjuague a enjuagado fin o centrifugado.
Del estado centrifugado a centrifugado fin.
Pausar y reanudar los estados lavado, enjuague y centrifugado.
Operación
Encendido
Al encender la lavadora, la FSM muestra un mensaje de bienvenida en la pantalla OLED y espera la selección de una opción mediante el teclado matricial.

## Selección de Opciones
El usuario puede seleccionar entre las opciones de lavar, enjuagar o centrifugar. Además, puede elegir el tipo de lavado (delicado, normal, fuerte), la carga (ligera, mediana, pesada) y la temperatura del agua (fría, tibia, caliente).

Ciclo de Lavado
Durante el ciclo de lavado, la pantalla OLED muestra el estado actual del proceso, incluyendo el tipo de lavado, la carga y la temperatura seleccionados. El proceso puede pausarse y reanudarse según sea necesario.

Enjuague y Centrifugado
Similar al ciclo de lavado, la FSM gestiona los procesos de enjuague y centrifugado, actualizando la pantalla OLED con la información relevante y permitiendo pausar y reanudar los procesos.

Apagado
El usuario puede apagar la lavadora en cualquier momento, lo que reinicia todos los parámetros a sus valores predeterminados.

Notas Adicionales
La comunicación UART se utiliza para recibir comandos del teclado matricial y enviar respuestas desde la FSM.

La pantalla OLED proporciona retroalimentación visual al usuario, mostrando el estado actual de la lavadora y las opciones seleccionadas.

Conclusión
Este proyecto demuestra cómo utilizar dos Raspberry Pi conectadas mediante UART para implementar un sistema de control de lavadora basado en una máquina de estados finitos. El uso de un teclado matricial y una pantalla OLED proporciona una interfaz de usuario eficaz y fácil de usar.