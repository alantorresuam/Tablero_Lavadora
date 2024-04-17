add_executable(carga_ropa
        carga.c
        #../common/sdk_inclines.S
        )

# pull in common dependencies
target_link_libraries(carga_ropa pico_stdlib)

# enable usb output, disable uart output
pico_enable_stdio_usb(carga_ropa 1)
pico_enable_stdio_uart(carga_ropa 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(carga_ropa)

