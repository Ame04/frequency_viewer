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
    #include <stdlib.h>

    /**
    * \def NB_AMPLITUDE_VALUES
    * \brief The number of value that can be returned by the adc
    */
    #define NB_AMPLITUDE_VALUES 4096 //for a 12bits ADC

    /**
    * \def NB_LED_PER_COLUMN
    * \brief The max number of led per column
    */
    #define NB_LED_PER_COLUMN 5

    /**
    * \def NB_LED_COLUMN
    * \brief The number of led column in the matrix
    */
    #define NB_LED_COLUMN 2

    /**
    * \def GPIO_TO_INIT
    * \brief All the Gpio to init, they have to be separated by comas as they will be transfered dirrectly in a tab. You can not use the GPIO 0.
    */
    #define GPIO_TO_INIT 1,2,3,4,5,6,7,8,9,10,11

    /**
    * \def NB_GPIO_TO_INIT
    * \brief The number of Gpio to init
    */
    #define NB_GPIO_TO_INIT 11

    /**
    * \struct Led
    * \brief Represent a led in the system
    */
    typedef struct Led
    {
        uint gpio;
        bool state;
    }Led;
    
    Led ledMatix[NB_LED_COLUMN+1][NB_LED_PER_COLUMN]; /*!< The matrix that hold the leds structure */

    /**
     * \fn void init_GPIO()
     * \brief Initialyses the GPIO for the leds and fill the ledMatrix.
     * 
     *  The ledMatrix will be initialised column by column with the gpios given in GPIO_TO_INIT. It will take them in the natural order utile it's full.
     * If there is not enough places in the matrix the left leds will be ignored. If there is not enough leds to fill the matrix, 
     * it will fill the end with led on the gpio 0 wich can't be chosen as part of the GPIO_TO_INIT.
     */ 
    void init_GPIO();

    /**
     * \fn void refresh_led_from_amplitude(uint* tabOfValue)
     * \brief Maps the amplitude value to give it to refresh_led
     * 
     * \param nbColumnToModify the size of the given tab
     * \param tabOfValue A tab with the value to map on each column of LED
     */ 
    void refresh_led_from_amplitude(uint* tabOfValue);

    /**
     * \fn void refresh_led(uint* tabOfValue)
     * \brief Change the led displayed
     * 
     * \param nbColumnToModify the size of the given tab
     * \param tabOfValue A tap with the value to map on each column of LED
     */ 
    void refresh_led(uint* tabOfValue);

#endif