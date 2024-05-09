#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>
#include "pico/stdlib.h"


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

    xTaskCreate(led_task, "LED_Task", 256, NULL, 1, NULL);
    vTaskStartScheduler();

    while(1){};
}