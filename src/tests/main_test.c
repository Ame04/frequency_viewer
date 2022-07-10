#include "pico/stdlib.h"
#include <stdio.h>
#include "../headers/ADC_gestion.h"
#include "../headers/led_gestion.h"
#include "../headers/my_utils.h"
#include "headers/test_led.h"
#include "headers/test_adc.h"

int main() {

    // Initialize chosen serial port
    stdio_init_all();
    sleep_ms(10000);
    printf("Begining initialisations\r\n");

    // Initialize LED pin
    init_GPIO();

    //Initialize the ADC
    init_ADC();

    printf("Begining of the tests ... \r\n");                    
    sleep_ms(2000);

    printf("Test led ... \r\n");
    test_led();
    printf("Test led : done \r\n");
    sleep_ms(2000);

    printf("Test ADC ... \r\n");
    //launch ADC conversions
    adc_run(true);
    test_adc();

    printf("Test ADC : done \r\n");

    
    printf("Test ADC+led ... \r\n");

    uint16_t tab_of_value[NB_LED_COLUMN];
    
    for (uint8_t i=0 ; i<NB_LED_COLUMN ; ++i)
    {
        tab_of_value[i]=0;
    }

    while (true) {
        if(new_val){
            new_val = 0;
            for(int j=0 ; j<NB_LED_COLUMN ; ++j){
                tab_of_value[j] = ADC_val;
            }
            refresh_led_from_amplitude(tab_of_value);
        }
    }
}