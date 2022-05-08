#include "pico/stdlib.h"
#include <stdio.h>
#include "../headers/ADC_gestion.h"
#include "../headers/led_gestion.h"
#include "../headers/my_utils.h"
#include "headers/test_led.h"

int main() {

    // Initialize chosen serial port
    stdio_init_all();
    sleep_ms(10000);
    printf("Begining initialisations\r\n");
    //Initialize the ADC
    //init_ADC();

    // Initialize LED pin
    init_GPIO();

    //launch the conversions and the programme
    //adc_run(true);

    printf("Begining of the tests ... \r\n");                    
    sleep_ms(2000);
    while (true) {
        printf("Test led ...");
        test_led();
        printf("Test led : done");
        sleep_ms(1000);
        return 1;
    }
}