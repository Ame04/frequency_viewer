/**
 * \file led_gestion.c
 * \brief Describes the gestion of the leds
 * \author Armand CAMUS
 * \version 1.0
 * \date 20 March 2021
 *
 * This file contains the implementation of the needed fonctions to control the leds.
 *
 */

#include "../headers/led_gestion.h"

void init_GPIO(const uint tabSize,const  uint* GpioToInit){
    for(int i =0; i<tabSize; ++i){
        uint gpio =GpioToInit[i];
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
        gpio_put(gpio,false);
    }
    
}