/**
 * \file led_gestion.h
 * \brief Describes the gestion of the leds
 * \author Armand CAMUS
 * \version 1.0
 * \date 20 March 2021
 *
 * This file contains the signature of the needed fonctions to control the leds.
 *
 */


#ifndef LED_GESTION_H
#define LED_GESTION_H

#include "hardware/gpio.h"

/**
 * \fn void init_GPIO(uint tabSize, uint* GpioToInit)
 * \brief initialyses the GPIO for the leds
 * 
 * \param tabSize the size of the given tab
 * \param GpioToInit A tap with the number of each GPIO we have to init
 */ 
void init_GPIO(const uint tabSize, const uint* GpioToInit);

/**
 * \fn void refresh_led(uint nbColumnToModify, uint* tabOfValue)
 * \brief change the led display
 * 
 * \param nbColumnToModify the size of the given tab
 * \param tabOfValue A tap with the value to map on each column of LED
 */ 
void refresh_led(uint nbColumnToModify, uint* tabOfValue);

#endif