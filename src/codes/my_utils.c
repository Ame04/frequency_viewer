/**
 * \file utils.c
 * \brief Describes util functions and structures 
 * \author Armand CAMUS
 * \version 1.0
 * \date 5 november 2021
 *
 * This file contains the implementation of some util functions.
 *
 */

#include "../headers/my_utils.h"

void initCircularBuffer(circularBuffer* c){
    for(int i=0 ; i<CIRCULAR_BUFFER_SIZE ; i++){
        c->buffer[i]=0;
    }  
    c->begining=0;
}

void addDataToCircularBuffer(circularBuffer* c, int16_t newData){
    c->buffer[c->begining]= newData;
    c->begining=(c->begining+1) & CIRCULAR_BUFFER_SIZE;
}