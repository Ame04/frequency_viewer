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

void init_GPIO(){
   const uint gpioToInit[]={GPIO_TO_INIT};
   int nbLedInit=0;
   for(int i=0 ; i<(NB_LED_COLUMN+1) ; ++i)
   {
       for(int j=0; j<NB_LED_PER_COLUMN ; ++j)
       {
           Led currentLed=ledMatix[i][j]; //retreive the current led in the matrix
           if(nbLedInit<NB_GPIO_TO_INIT)
           {
               currentLed.gpio=gpioToInit[nbLedInit];
               gpio_init(currentLed.gpio);
               gpio_set_dir(currentLed.gpio,GPIO_OUT);
               gpio_put(currentLed.gpio,false);
           }
           else
           {
               currentLed.gpio=0;
           }
           currentLed.state=false;
           nbLedInit++;
       }
   }
    
}

void refresh_led_from_amplitude(uint nbColumnToModify, uint* tabOfValue){
// map on 5 for all the values, uses NB_AMPLITUDE_VALUE to map
    for(int i =0 ; i<nbColumnToModify ; ++i){
        int futureValue = (int)(tabOfValue[i]/NB_AMPLITUDE_VALUES*NB_LED_PER_COLUMN);
        if(futureValue==5)
        {
            tabOfValue[i]=4;
        }
        else{
            tabOfValue[i]=futureValue;
        }
    }

    refresh_led(nbColumnToModify, tabOfValue);
}

void refresh_led(uint nbColumnToModify, uint* tabOfValue){
//case to look at changes + finaly changes  
    static uint oldColumnValues[NB_LED_COLUMN];
    static bool firstRound = true;
    int i =0;

    //init of the static tab, needs to be done only one time
    if (firstRound){
        firstRound=!firstRound;
        for( i = 0; i<NB_LED_COLUMN ; ++i){
            oldColumnValues[i]=0;
        }
    }

    int difference = 0;
    int sign=0;
    for(i =0;i<NB_LED_COLUMN;++i)
    {
        difference = tabOfValue[i]-oldColumnValues[i];
        if(difference)
        {
            sign=difference/abs(difference);
            for (int j = oldColumnValues[i]; i!=tabOfValue[i]; i+=sign)
            {
                ledMatix[i][j].state=!ledMatix[i][j].state;
                gpio_put(ledMatix[i][j].gpio,ledMatix[i][j].state);
            }
            
            
        }
    }
    

}