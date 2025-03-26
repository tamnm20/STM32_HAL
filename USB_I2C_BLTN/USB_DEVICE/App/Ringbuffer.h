/*
 * Ringbuffer.h
 *
 *  Created on: Mar 26, 2025
 *      Author: MCNEX
 */

#ifndef APP_RINGBUFFER_H_
#define APP_RINGBUFFER_H_

#include <stdint.h>

#define BUFFER_SIZE 1024  // 1KB

typedef struct {
    uint8_t buffer[BUFFER_SIZE];
    volatile uint32_t head;
    volatile uint32_t tail;
} RingBuffer_t;

uint32_t RingBuffer_Available(RingBuffer_t *rb);

uint8_t RingBuffer_IsFull(RingBuffer_t *rb);

uint8_t RingBuffer_IsEmpty(RingBuffer_t *rb);

void RingBuffer_Write(RingBuffer_t *rb, uint8_t *data, uint32_t len);

uint8_t RingBuffer_Read(RingBuffer_t *rb);

#endif /* APP_RINGBUFFER_H_ */
