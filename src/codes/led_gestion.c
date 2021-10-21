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
   
    
}

void refresh_led_from_amplitude(uint nbColumnToModify, uint* tabOfValue){
// map on 5 for both values
    for(int i =0 ; i<nbColumnToModify ; ++i){
        tabOfValue[i] = (int)(tabOfValue[i]/NB_AMPLITUDE_VALUES*NB_LED_PER_COLUMN);
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

    for(i =0;i<NB_LED_COLUMN;++i){}
    int difference = 0;





}