/**
 ********************************************************************************
 * @file    interface_task.cpp
 * @author  lars erni
 * @date    10.05.2024
 * @brief   
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include "interface_task.h"
#include "pico/stdlib.h"

/************************************
 * EXTERN VARIABLES
 ************************************/

/************************************
 * PRIVATE MACROS AND DEFINES
 ************************************/

/************************************
 * PRIVATE TYPEDEFS
 ************************************/

/************************************
 * STATIC VARIABLES
 ************************************/

/************************************
 * GLOBAL VARIABLES
 ************************************/

/************************************
 * STATIC FUNCTION PROTOTYPES
 ************************************/

/************************************
 * STATIC FUNCTIONS
 ************************************/

/************************************
 * GLOBAL FUNCTIONS
 ************************************/
WS2812 LEDInit(uint8_t ledPin, uint8_t numLEDs) {
    WS2812 ledStrip(
        ledPin,            // Data line is connected to pin 0. (GP0)
        numLEDs,         // Strip is 6 LEDs long.
        pio0,               // Use PIO 0 for creating the state machine.
        0,                  // Index of the state machine that will be created for controlling the LED strip
                            // You can have 4 state machines per PIO-Block up to 8 overall.
                            // See Chapter 3 in: https://datasheets.raspberrypi.org/rp2040/rp2040-datasheet.pdf
        WS2812::FORMAT_GRB  // Pixel format used by the LED strip
    );
    return ledStrip;
}



void LEDTest(WS2812 myLedStrip) {
    // 1. Set all LEDs to red!
        // printf("1. Set all LEDs to red!");
        myLedStrip.fill( WS2812::RGB(25, 0, 0) );
        myLedStrip.show();
        sleep_ms(1000);

        // 2. Set all LEDs to green!
        // printf("2. Set all LEDs to green!");
        myLedStrip.fill( WS2812::RGB(0, 25, 0) );
        myLedStrip.show();
        sleep_ms(1000);

        // 3. Set all LEDs to blue!
        // 7printf("3. Set all LEDs to blue!");
        myLedStrip.fill( WS2812::RGB(0, 0, 25) );
        myLedStrip.show();
        sleep_ms(1000);
}