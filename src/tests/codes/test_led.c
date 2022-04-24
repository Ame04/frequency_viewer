#include "../headers/test_led.h"

void test_led(void){
    uint tab_of_value[NB_LED_COLUMN];
    
    for (int i=0 ; i<NB_LED_COLUMN ; ++i)
    {
        tab_of_value[i]=0;
    }

    for (int i=0 ; i<NB_AMPLITUDE_VALUES ; ++i)
    {
        for(int j=0 ; j<NB_LED_COLUMN ; ++j){
            tab_of_value[j]=i;
        }
        refresh_led_from_amplitude(tab_of_value);
    }
    for (int i=NB_AMPLITUDE_VALUES-1 ; i>=0 ; --i)
    {
        for(int j=0 ; j<NB_LED_COLUMN ; ++j){
            tab_of_value[j]=i;
        }
        refresh_led_from_amplitude(tab_of_value);
    }
}