add_executable(centrifugar
        centrifugar.c
        #../common/sdk_inclines.S
        )

# pull in common dependencies
target_link_libraries(centrifugar pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(centrifugar)

# add url via pico_set_program_url
# example_auto_set_url(centrifugar)