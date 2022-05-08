#include "../headers/test_led.h"

void test_led(void){
    uint tab_of_value[NB_LED_COLUMN];
    
    for (int i=0 ; i<NB_LED_COLUMN ; ++i)
    {
        tab_of_value[i]=0;
    }

    for (int i=0 ; i<NB_AMPLITUDE_VALUES ; i+=256)
    {
        printf("\r\nAmplitude = %d\r\n", i);
        for(int j=0 ; j<NB_LED_COLUMN ; ++j){
            tab_of_value[j]=i;
        }
        refresh_led_from_amplitude(tab_of_value);
        sleep_ms(200);
    }

    for (int i=NB_AMPLITUDE_VALUES-1 ; i>=0 ; i-=256)
    {
        printf("\r\nAmplitude = %d\r\n", i);
        for(int j=0 ; j<NB_LED_COLUMN ; ++j){
            tab_of_value[j]=i;
        }
        refresh_led_from_amplitude(tab_of_value);
        sleep_ms(200);
    }

    for (int i=0 ; i<NB_LED_COLUMN ; ++i)
    {
        tab_of_value[i]=4096;
    }
    refresh_led_from_amplitude(tab_of_value);
    sleep_ms(1000);

    for (int i=0 ; i<NB_LED_COLUMN ; ++i)
    {
        tab_of_value[i]=0;
    }
    refresh_led_from_amplitude(tab_of_value);
}