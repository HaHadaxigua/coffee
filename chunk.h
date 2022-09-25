//
// Created by Miku on 2022/9/25.
//

#ifndef COFFEE_CHUNK_H
#define COFFEE_CHUNK_H

#include "common.h"

// In our bytecode format, each instruction has one-byte operation-code.
// That number controls what kind of instruction we're dealing with.
typedef enum {
    OP_RETURN, // means "return from the current function"
} OpCode;


// Bytecode is a series of instructions. Eventually, we'll store some other
// data along with the instructions.
typedef struct {
    int count; // how many of those allocated entries are actually in use.
    int capacity; // the number of elements int the array we have allocated.
    uint8_t *code; // for now, it's just a wrapper around an array of bytes.
} Chunk;

// constructor of chunk
void initChunk(Chunk *chunk);

// append a byte to the end of the chunk
void writeChunk(Chunk *chunk, uint8_t byte);

// we need to free memory ourselves.
void freeChunk(Chunk *chunk);

#endif //COFFEE_CHUNK_H
