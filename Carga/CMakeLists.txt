add_executable(carga
        carga.c
        #../common/sdk_inclines.S
        )

# pull in common dependencies
target_link_libraries(carga pico_stdlib)

# enable usb output, disable uart output
pico_enable_stdio_usb(carga 1)
pico_enable_stdio_uart(carga 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(carga)

