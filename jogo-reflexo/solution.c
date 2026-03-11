#include <stdio.h>

#include "hardware/gpio.h"
#include "pico/stdlib.h"

#define FIRST_GPIO 2
#define BUTTON_GPIO (FIRST_GPIO + 7)

const int BTN_PIN_G = 28;
const int BTN_PIN_Y = 26;
const int BTN_PIN_R = 20;

const int LED_PIN_G = 5;
const int LED_PIN_Y = 9;
const int LED_PIN_R = 13;

volatile int btn_f = 0;

int seq[] = {1, 0, 2, 1, 0, 1, 2, 1, 0, 1};

int led_pin[] = {LED_PIN_G, LED_PIN_Y, LED_PIN_R};
int btn_pin[] = {BTN_PIN_G, BTN_PIN_Y, BTN_PIN_R};

void btn_callback(uint gpio, uint32_t events) {
    if (events == 0x4) {  // fall edge
        btn_f = gpio;
    } else if (events == 0x8) {  // rise edge
    }
}

int main() {
    stdio_init_all();

    gpio_init(BTN_PIN_G);
    gpio_set_dir(BTN_PIN_G, GPIO_IN);
    gpio_pull_up(BTN_PIN_G);
    gpio_set_irq_enabled_with_callback(BTN_PIN_G, GPIO_IRQ_EDGE_FALL, true,
                                       &btn_callback);

    gpio_init(BTN_PIN_Y);
    gpio_set_dir(BTN_PIN_Y, GPIO_IN);
    gpio_pull_up(BTN_PIN_Y);
    gpio_set_irq_enabled_with_callback(BTN_PIN_Y, GPIO_IRQ_EDGE_FALL, true,
                                       &btn_callback);

    gpio_init(BTN_PIN_R);
    gpio_set_dir(BTN_PIN_R, GPIO_IN);
    gpio_pull_up(BTN_PIN_R);
    gpio_set_irq_enabled_with_callback(BTN_PIN_R, GPIO_IRQ_EDGE_FALL, true,
                                       &btn_callback);

    gpio_init(LED_PIN_G);
    gpio_set_dir(LED_PIN_G, GPIO_OUT);

    gpio_init(LED_PIN_Y);
    gpio_set_dir(LED_PIN_Y, GPIO_OUT);

    gpio_init(LED_PIN_R);
    gpio_set_dir(LED_PIN_R, GPIO_OUT);

    int pnts = 0;
    int level = 1;
    int acertou = 1;
    int led = -1;
    while (true) {
        while (true) {
            if (btn_f == btn_pin[0]) break;
        }

        pnts = 0;
        btn_f = 0;
        acertou = 1;
        level = 0;
        while (acertou == 1) {
            level++;

            sleep_ms(300);
            for (int i = 0; i < level; i++) {
                gpio_put(led_pin[seq[i]], 1);
                sleep_ms(300);
                gpio_put(led_pin[seq[i]], 0);
                sleep_ms(300);
            }
            btn_f = 0;
            for (int i = 0; i < level; i++) {
                while (btn_f == 0) {
                }

                if (btn_f == BTN_PIN_G)
                    led = 0;
                else if (btn_f == BTN_PIN_Y)
                    led = 1;
                else if (btn_f == BTN_PIN_R)
                    led = 2;
                else
                    led = -1;

                gpio_put(led_pin[led], 1);
                if (btn_f != btn_pin[seq[i]]) {
                    acertou = 0;
                    break;
                }
                sleep_ms(300);
                gpio_put(led_pin[led], 0);

                btn_f = 0;
            }
            btn_f = 0;
        }
        printf("Points: %d\n", level);
        gpio_put(led_pin[0], 0);
        gpio_put(led_pin[1], 0);
        gpio_put(led_pin[2], 0);
    }
}
