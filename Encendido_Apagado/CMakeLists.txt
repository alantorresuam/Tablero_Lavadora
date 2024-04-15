cmake_minimum_required(VERSION 3.13)

add_executable(Encendido_Apagado
            Encender_apagar.c
)

target_link_libraries(Encendido_Apagado pico_stdlib)

# enable usb output, disable uart output
pico_enable_stdio_usb(Encendido_Apagado 1)
pico_enable_stdio_uart(Encendido_Apagado 0)

pico_add_extra_outputs(Encendido_Apagado)
