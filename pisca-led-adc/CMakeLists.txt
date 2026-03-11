add_executable(pisca-led-adc
        main.c
)

target_link_libraries(pisca-led-adc
                     hardware_adc
                     pico_stdlib )
pico_add_extra_outputs(pisca-led-adc)
