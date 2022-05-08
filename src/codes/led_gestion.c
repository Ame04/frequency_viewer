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
    for(int i=0 ; i<(NB_LED_COLUMN+1) ; ++i)
    {
        for(int j=0; j<NB_LED_PER_COLUMN ; ++j)
        {
            Led currentLed;
            if(nbLedInit<NB_GPIO_TO_INIT)
            {
                currentLed.gpio=gpioToInit[nbLedInit];
                gpio_init(currentLed.gpio);
                gpio_set_dir(currentLed.gpio,GPIO_OUT);
                gpio_put(currentLed.gpio,false);
                sleep_ms(1000);
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
    printf("GPIO initialisation : Done \r\n");
}

void refresh_led_from_amplitude(uint* tabOfValue){
// map on 5 for all the values, uses NB_AMPLITUDE_VALUE to map
    for(int i =0 ; i<NB_LED_COLUMN ; ++i){
        int futureValue = (int)(((float)tabOfValue[i])/NB_AMPLITUDE_VALUES*(NB_LED_PER_COLUMN+1));
        if(futureValue==NB_LED_PER_COLUMN+1)
        {
            tabOfValue[i]=NB_LED_PER_COLUMN;
        }
        else{
            tabOfValue[i]=futureValue;
        }
        printf("Future value = %d\r\n", futureValue);
    }

    refresh_led(tabOfValue);
}

void refresh_led(uint* tabOfValue){
//case to look at changes + finaly changes  
    static uint oldColumnValues[NB_LED_COLUMN];
    static bool firstRound = true;

    //init of the static tab, needs to be done only one time
    if (firstRound){
        firstRound=!firstRound;
        for(int i = 0; i<NB_LED_COLUMN ; ++i){
            oldColumnValues[i]=0;
        }
        printf("First init of oldColumnValues : done\r\n");
    }

    int difference = 0;
    int sign=0;
    for(int i=0; i<NB_LED_COLUMN; ++i)
    {
        printf("Old column value = %d at the begining of the changing\r\n", oldColumnValues[i]);
        difference = tabOfValue[i]-oldColumnValues[i];
        printf("Difference = %d\r\n", difference);
        if(difference)
        {
            sign=difference/abs(difference);
            int led;
            for (int j = oldColumnValues[i]; j!=tabOfValue[i]; j+=sign)
            {
                if(sign==-1){
                    led=j-1;
                }
                else{
                    led=j;
                }
                ledMatrix[i][led].state=!ledMatrix[i][led].state;
                gpio_put(ledMatrix[i][led].gpio,ledMatrix[i][led].state);
                printf("Gpio %d as been changed\r\n", ledMatrix[i][led].gpio);
            }
            oldColumnValues[i]=tabOfValue[i];
            printf("Old column value = %d at the end of the changing\r\n", oldColumnValues[i]);
        }
    }
    

}