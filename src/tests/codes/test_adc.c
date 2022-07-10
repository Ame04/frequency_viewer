#include "../headers/test_adc.h"

void test_adc(void){
    uint16_t current_adc_val = 4096;
    uint16_t last_adc_val = 0;
    uint64_t start_time = 0;
    uint64_t time = 0;
    uint32_t nb_tick = 0;
    uint32_t mean_freq = 0;

    printf("Test adc value ...\r\n");
    sleep_ms(2000);
    adc_fifo_drain();
    new_val = 0;
    start_time = to_ms_since_boot(get_absolute_time());
    time= start_time;
    while(time - start_time < 10000){
        time = to_ms_since_boot(get_absolute_time());
        if(new_val){
            new_val = 0;
            current_adc_val=ADC_val;
            nb_tick ++ ;
            printf("ADC val = %d  and it is the %ldth value\r\n", current_adc_val, nb_tick);
        }
    }
    printf("Test adc value : done \r\n");
    sleep_ms(2000);
    printf("Test adc frequency ... \r\n");
    sleep_ms(2000);
    adc_fifo_drain();
    new_val = 0;
    for(uint8_t i = 0 ; i < 5 ; ++i){
        start_time = to_ms_since_boot(get_absolute_time());
        time= start_time;
        while(time - start_time < 30000){
            time = to_ms_since_boot(get_absolute_time());
            if(new_val){
                new_val = 0;
                current_adc_val=ADC_val;
                nb_tick ++ ;
            }
        }

        printf("ADC frequency %d is : %d\r\n", i, (nb_tick/30));
        mean_freq += (nb_tick/30);
        nb_tick = 0;
    }

    printf("Mean ADC frequency is : %d\r\n", (mean_freq/5));
    printf("Test adc frequency : done \r\n");
    sleep_ms(5000);
}
