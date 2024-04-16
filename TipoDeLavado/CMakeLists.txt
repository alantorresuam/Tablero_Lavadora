cmake_minimum_required(VERSION 3.13)

add_executable(TipoDeLavado
        Tipo_lavado.c
)

target_link_libraries(TipoDeLavado pico_stdlib)

# enable usb output, disable uart output
pico_enable_stdio_usb(TipoDeLavado 1)
pico_enable_stdio_uart(TipoDeLavado 0)

pico_add_extra_outputs(TipoDeLavado)
