
#include "pico/stdlib.h"
#include <stdio.h>
#include "headers/led_gestion.h"

int main() {

    const uint GPIO_TO_INIT[]={0,1,2,3,4,5,6,7,8,9,10};
    const uint NB_GPIO_TO_INIT=11;
    // Initialize chosen serial port
    stdio_init_all();


    // Initialize LED pin
    init_GPIO(NB_GPIO_TO_INIT,GPIO_TO_INIT);

    while (true) {
        
    }
}