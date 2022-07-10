#include "../headers/test_led.h"

void test_led(void){
    uint16_t tab_of_value[NB_LED_COLUMN];
    
    for (uint8_t i=0 ; i<NB_LED_COLUMN ; ++i)
    {
        tab_of_value[i]=0;
    }

    sleep_ms(1000);
    printf("Ramp up");
    for (int16_t i=0 ; i<NB_AMPLITUDE_VALUES ; i+=256)
    {
        printf("\r\nAmplitude = %d\r\n", i);
        for(uint8_t j=0 ; j<NB_LED_COLUMN ; ++j){
            tab_of_value[j]=i;
        }
        refresh_led_from_amplitude(tab_of_value);
        sleep_ms(200);
    }

    sleep_ms(1000);
    printf("Ramp down");
    for (int16_t i=NB_AMPLITUDE_VALUES-1 ; i>=0 ; i-=256)
    {
        printf("\r\nAmplitude = %d\r\n", i);
        for(uint8_t j=0 ; j<NB_LED_COLUMN ; ++j){
            tab_of_value[j]=i;
        }
        refresh_led_from_amplitude(tab_of_value);
        sleep_ms(200);
    }

    sleep_ms(1000);
    printf("All on at once");
    for (uint8_t i=0 ; i<NB_LED_COLUMN ; ++i)
    {
        tab_of_value[i]=4096;
    }
    refresh_led_from_amplitude(tab_of_value);
    sleep_ms(1000);

    sleep_ms(1000);
    printf("All off at once");
    for (uint8_t i=0 ; i<NB_LED_COLUMN ; ++i)
    {
        tab_of_value[i]=0;
    }
    refresh_led_from_amplitude(tab_of_value);
}