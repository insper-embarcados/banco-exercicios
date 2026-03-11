add_executable(pisca-led-dois-botoes
        main.c
)

target_link_libraries(pisca-led-dois-botoes
                     hardware_adc
                     pico_stdlib )
pico_add_extra_outputs(pisca-led-dois-botoes)
