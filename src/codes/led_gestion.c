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

static Led ledMatrix[NB_LED_COLUMN+1][NB_LED_PER_COLUMN];

void init_GPIO(){
    printf("GPIO initialisation ... \r\n");
    const uint gpioToInit[]={GPIO_TO_INIT};
    int nbLedInit=0;
    uint16_t tab_of_value[NB_LED_COLUMN];
    for (uint8_t i=0 ; i<NB_LED_COLUMN ; ++i)
    {
        tab_of_value[i]=0;
    }
    // Initialisation of the leds 
    for(uint8_t i=0 ; i<(NB_LED_COLUMN+1) ; ++i)
    {
        for(uint8_t j=0; j<NB_LED_PER_COLUMN ; ++j)
        {
            Led currentLed;
            if(nbLedInit<NB_GPIO_TO_INIT)
            {
                currentLed.gpio=gpioToInit[nbLedInit];
                gpio_init(currentLed.gpio);
                gpio_set_dir(currentLed.gpio,GPIO_OUT);
                gpio_put(currentLed.gpio,false);
                sleep_ms(500);
                gpio_put(currentLed.gpio,true);
            }
            else
            {
                currentLed.gpio=0;
            }
            currentLed.state=true;
            ledMatrix[i][j]=currentLed;
            nbLedInit++;
        }
    }
    // Do a refresh ones to initialize the static tab in it
    refresh_led_from_amplitude(tab_of_value);

    printf("GPIO initialisation : Done \r\n");
}

void refresh_led_from_amplitude(uint16_t* tabOfValue){
// map on 5 for all the values, uses NB_AMPLITUDE_VALUE to map
    for(uint8_t i =0 ; i<NB_LED_COLUMN ; ++i){
        uint8_t futureValue = (uint8_t)(((float)tabOfValue[i])/NB_AMPLITUDE_VALUES*(NB_LED_PER_COLUMN+1));
        if(futureValue==NB_LED_PER_COLUMN+1)
        {
            tabOfValue[i]=NB_LED_PER_COLUMN;
        }
        else{
            tabOfValue[i]=futureValue;
        }
    }

    refresh_led(tabOfValue);
}

void refresh_led(uint16_t* tabOfValue){
//case to look at changes + finaly changes  
    static uint oldColumnValues[NB_LED_COLUMN];
    static bool firstRound = true;

    //init of the static tab, needs to be done only one time
    if (firstRound){
        firstRound=!firstRound;
        for(uint8_t i = 0; i<NB_LED_COLUMN ; ++i){
            oldColumnValues[i]=0;
        }
        printf("First init of oldColumnValues : done\r\n");
    }

    int8_t difference = 0;
    int8_t sign=0;
    for(uint8_t i=0; i<NB_LED_COLUMN; ++i)
    {
        difference = tabOfValue[i]-oldColumnValues[i];
        if(difference)
        {
            sign=difference/abs(difference);
            uint8_t led;
            for (uint8_t j = oldColumnValues[i]; j!=tabOfValue[i]; j+=sign)
            {
                if(sign==-1){
                    led=j-1;
                }
                else{
                    led=j;
                }
                ledMatrix[i][led].state=!ledMatrix[i][led].state;
                gpio_put(ledMatrix[i][led].gpio,ledMatrix[i][led].state);
            }
            oldColumnValues[i]=tabOfValue[i];
        }
    }
    

}