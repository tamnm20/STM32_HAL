#ifndef RingBuffer_h
#define RingBuffer_h

#include <Arduino.h>

class RingBuffer {
public:
  RingBuffer(int size);
  ~RingBuffer();
  void write(char data);
  char read();
  bool isFull();
  bool isEmpty();
  int available();
  
private:
  int capacity;
  char *buffer;
  int readIndex;
  int writeIndex;
};

RingBuffer::RingBuffer(int size) {
  capacity = size;
  buffer = new char[size];
  readIndex = 0;
  writeIndex = 0;
}

RingBuffer::~RingBuffer() {
  delete[] buffer;
}

void RingBuffer::write(char data) {
  if (!isFull()) {
    buffer[writeIndex] = data;
    writeIndex = (writeIndex + 1) % capacity;
  }
}

char RingBuffer::read() {
  if (!isEmpty()) {
    char data = buffer[readIndex];
    readIndex = (readIndex + 1) % capacity;
    return data;
  }
  return '\0'; // Return null character if buffer is empty
}

bool RingBuffer::isFull() {
  return ((writeIndex + 1) % capacity) == readIndex;
}

bool RingBuffer::isEmpty() {
  return readIndex == writeIndex;
}

int RingBuffer::available() {
  if (writeIndex >= readIndex) {
    return writeIndex - readIndex;
  } else {
    return (capacity - readIndex) + writeIndex;
  }
}

#endif
