#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>
#include "pico/stdlib.h"
#include "interface_task.h"
#include "WS2812.hpp"


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
    extern "C" {
    xTaskCreate(led_task, "LED_Task", 256, NULL, 1, NULL);
    vTaskStartScheduler();
    };
    
    stdio_init_all();

    WS2812 myLedStrip = LEDInit(SMARTKNOB_LED_DATA_PIN, SMARTKNOB_NUMLEDS);

    while(1) {
        LEDTest(myLedStrip);
    };
}

