add_executable(buzzer-com-timer
        main.c
)

target_link_libraries(buzzer-com-timer
                     hardware_adc
                     pico_stdlib )
pico_add_extra_outputs(buzzer-com-timer)
