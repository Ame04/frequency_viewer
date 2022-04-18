/**
 * \file utils.h
 * \brief Describes util functions and structures 
 * \author Armand CAMUS
 * \version 1.0
 * \date 5 november 2021
 *
 * This file contains the signature of some util functions.
 *
 */

#include <stdio.h>

#ifndef MY_UTILS_H
#define MY_UTILS_H

    /**
        * \def CIRCULAR_BUFFER_SIZE
        * \brief The GPIO used for the ADC
        */
    #define CIRCULAR_BUFFER_SIZE 512 //as to be a power of 2 for the circular buffer to be efficient

    typedef struct circularBuffer{
        int16_t buffer[CIRCULAR_BUFFER_SIZE];
        int16_t begining;
    }circularBuffer;

    /**
     * \fn void initCircularBuffer(circularBuffer* c)
     * \brief Init the circular buffer.
     * 
     * \param c the circularBuffer to init
     */
    void initCircularBuffer(circularBuffer* c);

    /**
     * \fn void addDataToCircularBuffer(circularBuffer* c, int16_t newData)
     * \brief Add a sample in the buffer.
     * 
     * \param c the circularBuffer where to add the data
     * \param newData the new data to add
     */
    void addDataToCircularBuffer(circularBuffer* c, int16_t newData);

#endif