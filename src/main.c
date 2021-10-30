
#include "pico/stdlib.h"
#include <stdio.h>
#include "headers/ADC_gestion.h"
#include "headers/led_gestion.h"

int main() {

    
    // Initialize chosen serial port
    stdio_init_all();

    //Initialize the ADC
    

    // Initialize LED pin
    init_GPIO();

    while (true) {
        
    }
}