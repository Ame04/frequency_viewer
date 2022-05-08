/**
 * \file ADC_gestion.c
 * \brief Describes the gestion of the ADC
 * \author Armand CAMUS
 * \version 1.0
 * \date 30 October 2021
 *
 * This file contains the implementation of the needed fonctions to control the ADC.
 *
 */

#include "../headers/ADC_gestion.h"

uint8_t new_val;
uint16_t ADC_val;

void adc_irq_handler(){
    ADC_val=adc_fifo_get();
    new_val=1;
}

void init_ADC(){//To do : add prints

    adc_init();                         //init and reset the adc
    adc_gpio_init(ADC_GPIO);            //init the gpio to be usable for the adc
    adc_set_temp_sensor_enabled(false); //we don't need it
    adc_set_clkdiv(CONVERSION_FREQUENCY_RATIO); //to change the frequency of the conversion
    adc_fifo_setup(true,false,1,false,false);   // enable, enable dma, threshold for irq, bit 15 is error bit, perform bit shift
    adc_irq_set_enabled(true);          // enable but no handler at the moment 
    adc_select_input((ADC_GPIO%26));    //select an input for the adc

    new_val=0;
    ADC_val=0;

    irq_clear (ADC_IRQ_FIFO);
    irq_set_enabled (ADC_IRQ_FIFO, true);
    irq_set_exclusive_handler(ADC_IRQ_FIFO,adc_irq_handler);

}
