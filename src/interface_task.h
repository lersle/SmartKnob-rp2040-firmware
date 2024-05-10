/**
 ********************************************************************************
 * @file    interface_task.h
 * @author  lars erni
 * @date    10.05.2024
 * @brief   
 ********************************************************************************
 */

#ifndef INTERFACE_TASK_H
#define INTERFACE_TASK_H

#ifdef __cplusplus
extern "C" {
#endif

/************************************
 * INCLUDES
 ************************************/
#include "WS2812.hpp"

/************************************
 * MACROS AND DEFINES
 ************************************/

/************************************
 * TYPEDEFS
 ************************************/

/************************************
 * EXPORTED VARIABLES
 ************************************/

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/
WS2812 LEDInit(uint8_t ledPin, uint8_t numLEDs);
void LEDTest(WS2812 myLedStrip);

#ifdef __cplusplus
}
#endif

#endif 