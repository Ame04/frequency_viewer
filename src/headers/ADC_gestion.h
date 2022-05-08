/**
 * \file ADC_gestion.h
 * \brief Describes the gestion of the ADC
 * \author Armand CAMUS
 * \version 1.0
 * \date 30 October 2021
 *
 * This file contains the signature of the needed fonctions to control the ADC.
 *
 */

#ifndef ADC_GESTION_H
#define ADC_GESTION_H

    #include "hardware/adc.h"
    #include "hardware/irq.h"

    /**
    * \def ADC_GPIO
    * \brief The GPIO used for the ADC
    */
    #define ADC_GPIO 26

    /**
    * \def CONVERSION_FREQUENCY
    * \brief It is (48 000 000/(the frequency you want to achive))-1
    */
    #define CONVERSION_FREQUENCY_RATIO 999

/************ FONCTIONS ******************/

    /**
     * \fn void adc_irq_handler()
     * \brief The handler function for the adc's irq.
     * 
     */
    void adc_irq_handler();

    /**
     * \fn void init_ADC()
     * \brief Initialyses the ADC.
     * 
     */ 
    void init_ADC();


#endif 