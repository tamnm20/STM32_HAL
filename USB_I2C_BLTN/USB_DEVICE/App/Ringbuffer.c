/*
 * Ringbuffer.c
 *
 *  Created on: Mar 26, 2025
 *      Author: MCNEX
 */
#include "Ringbuffer.h"

RingBuffer_t USB_RxBuffer = { .head = 0, .tail = 0 };

uint32_t RingBuffer_Available(RingBuffer_t *rb) {
    return (rb->head - rb->tail) & (BUFFER_SIZE - 1);
}

uint8_t RingBuffer_IsFull(RingBuffer_t *rb) {
    return RingBuffer_Available(rb) == (BUFFER_SIZE - 1);
}

uint8_t RingBuffer_IsEmpty(RingBuffer_t *rb) {
    return rb->head == rb->tail;
}

void RingBuffer_Write(RingBuffer_t *rb, uint8_t *data, uint32_t len) {
    for (uint32_t i = 0; i < len; i++) {
        if (!RingBuffer_IsFull(rb)) {
            rb->buffer[rb->head & (BUFFER_SIZE - 1)] = data[i];
            rb->head++;
        }
    }
}

uint8_t RingBuffer_Read(RingBuffer_t *rb) {
    uint8_t data = 0;
    if (!RingBuffer_IsEmpty(rb)) {
        data = rb->buffer[rb->tail & (BUFFER_SIZE - 1)];
        rb->tail++;
    }
    return data;
}
