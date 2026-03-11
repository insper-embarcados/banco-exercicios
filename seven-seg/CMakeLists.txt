add_executable(seven-seg
        main.c
)

target_link_libraries(seven-seg pico_stdlib hardware_adc freertos)
pico_add_extra_outputs(seven-seg)
