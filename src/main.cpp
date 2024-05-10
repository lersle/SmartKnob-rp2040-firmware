#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>
#include "pico/stdlib.h"
#include "WS2812.hpp"

#define LED_PIN     SMARTKNOB_LED_DATA_PIN
#define LED_LENGTH  SMARTKNOB_NUMLEDS


void led_task()
{   
    gpio_init(SMARTKNOB_LCD_BACKLIGHT);
    gpio_set_dir(SMARTKNOB_LCD_BACKLIGHT, GPIO_OUT);
    while (true) {
        gpio_put(SMARTKNOB_LCD_BACKLIGHT, 1);
        vTaskDelay(10000);
        gpio_put(SMARTKNOB_LCD_BACKLIGHT, 0);
        vTaskDelay(10000);
    }
}

int main()
{
    stdio_init_all();

    // 0. Initialize LED strip
    printf("0. Initialize LED strip");
    WS2812 ledStrip(
        LED_PIN,            // Data line is connected to pin 0. (GP0)
        LED_LENGTH,         // Strip is 6 LEDs long.
        pio0,               // Use PIO 0 for creating the state machine.
        0,                  // Index of the state machine that will be created for controlling the LED strip
                            // You can have 4 state machines per PIO-Block up to 8 overall.
                            // See Chapter 3 in: https://datasheets.raspberrypi.org/rp2040/rp2040-datasheet.pdf
        WS2812::FORMAT_GRB  // Pixel format used by the LED strip
    );

    //xTaskCreate(led_task, "LED_Task", 256, NULL, 1, NULL);
    //vTaskStartScheduler();

    while(1){
        // 1. Set all LEDs to red!
        printf("1. Set all LEDs to red!");
        ledStrip.fill( WS2812::RGB(25, 0, 0) );
        ledStrip.show();
        sleep_ms(1000);

        // 2. Set all LEDs to green!
        printf("2. Set all LEDs to green!");
        ledStrip.fill( WS2812::RGB(0, 25, 0) );
        ledStrip.show();
        sleep_ms(1000);

        // 3. Set all LEDs to blue!
        printf("3. Set all LEDs to blue!");
        ledStrip.fill( WS2812::RGB(0, 0, 25) );
        ledStrip.show();
        sleep_ms(1000);
    };
}