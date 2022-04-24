#include "pico/stdlib.h"
#include <stdio.h>
#include "../headers/ADC_gestion.h"
#include "../headers/led_gestion.h"
#include "../headers/my_utils.h"
#include "headers/test_led.h"

int main() {

    
    // Initialize chosen serial port
    stdio_init_all();

    //Initialize the ADC
    //init_ADC();

    // Initialize LED pin
    init_GPIO();

    //launch the conversions and the programme
    //adc_run(true);                      

    while (true) {
        test_led();
    }
}