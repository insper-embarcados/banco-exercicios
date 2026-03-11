#include <stdio.h>

#include "hardware/gpio.h"
#include "pico/stdlib.h"

const int LINE_1 = 3;
const int LINE_2 = 8;
const int LINE_3 = 13;

const int COL_1 = 14;
const int COL_2 = 15;


volatile int btn_f = 0;

void btn_callback(uint gpio, uint32_t events) {
    if (events == 0x4) {  // fall edge
        btn_f = gpio;
    } else if (events == 0x8) {  // rise edge
        btn_f = 0;
    }
}

int main() {
    stdio_init_all();

    gpio_init(LINE_1);
    gpio_set_dir(LINE_1, GPIO_IN);
    gpio_pull_up(LINE_1);
    gpio_set_irq_enabled_with_callback(LINE_1, GPIO_IRQ_EDGE_FALL | GPIO_IRQ_EDGE_RISE, true,
                                       &btn_callback);

    gpio_init(LINE_2);
    gpio_set_dir(LINE_2, GPIO_IN);
    gpio_pull_up(LINE_2);
    gpio_set_irq_enabled_with_callback(LINE_2, GPIO_IRQ_EDGE_FALL | GPIO_IRQ_EDGE_RISE, true,
                                       &btn_callback);

    gpio_init(LINE_3);
    gpio_set_dir(LINE_3, GPIO_IN);
    gpio_pull_up(LINE_3);
    gpio_set_irq_enabled_with_callback(LINE_3, GPIO_IRQ_EDGE_FALL | GPIO_IRQ_EDGE_RISE, true,
                                       &btn_callback);

    gpio_init(COL_1);
    gpio_set_dir(COL_1, GPIO_OUT);
    gpio_init(COL_2);
    gpio_set_dir(COL_2, GPIO_OUT);

    while (true) {
        gpio_put(COL_1, 0);
        gpio_put(COL_2, 1);
        sleep_ms(10);
        
        if (btn_f != 0) {
            if (btn_f == 3)
                printf("Btn: 2\n");
            else if (btn_f == 8)
                printf("Btn: 4\n");
            else
                printf("Btn: 6\n");
            while(btn_f != 0){}
        }

        gpio_put(COL_1, 1);
        gpio_put(COL_2, 0);
        sleep_ms(10);
        if (btn_f != 0) {
            if (btn_f == 3)
                printf("Btn: 1\n");
            else if (btn_f == 8)
                printf("Btn: 3\n");
            else
                printf("Btn: 5\n");
            while(btn_f != 0){}
        }


    }
}
