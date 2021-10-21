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

    #define NB_AMPLITUDE_VALUES 4096 //for a 12bits ADC
    #define NB_LED_PER_COLUMN 5
    #define NB_LED_COLUMN 2

    const uint GPIO_TO_INIT[]={0,1,2,3,4,5,6,7,8,9,10};
    const uint NB_GPIO_TO_INIT=11;

    /**
     * \fn void init_GPIO()
     * \brief initialyses the GPIO for the leds
     */ 
    void init_GPIO();

    /**
     * \fn void refresh_led_from_amplitude(uint nbColumnToModify, uint* tabOfValue)
     * \brief maps the amplitude value to give it to refresh_led
     * 
     * \param nbColumnToModify the size of the given tab
     * \param tabOfValue A tap with the value to map on each column of LED
     */ 
    void refresh_led_from_amplitude(uint nbColumnToModify, uint* tabOfValue);

    /**
     * \fn void refresh_led(uint nbColumnToModify, uint* tabOfValue)
     * \brief change the led display
     * 
     * \param nbColumnToModify the size of the given tab
     * \param tabOfValue A tap with the value to map on each column of LED
     */ 
    void refresh_led(uint nbColumnToModify, uint* tabOfValue);

#endif