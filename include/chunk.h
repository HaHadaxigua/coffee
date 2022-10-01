//
// Created by Miku on 2022/9/25.
//

#ifndef COFFEE_CHUNK_H
#define COFFEE_CHUNK_H

#include "common.h"
#include "value.h"

// In our bytecode format, each instruction has one-byte operation-code.
// That number controls what kind of instruction we're dealing with.
typedef enum {
    OP_CONSTANT, // produce a particular constant
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
    OP_NEGATE,
    OP_RETURN, // means "return from the current function"
} OpCode;


// Bytecode is a series of instructions. Eventually, we'll store some other
// data along with the instructions.
typedef struct {
    // how many of those allocated entries are actually in use.
    int count;
    // the number of elements int the array we have allocated.
    int capacity;
    // for now, it's just a wrapper around an array of bytes.
    uint8_t *code;
    // growable arrays of values to store the chunk’s constants.
    ValueArray constants;
    // Each number in the array is the line number for the corresponding byte in the bytecode
    int *lines;
} Chunk;

// constructor of chunk
void initChunk(Chunk *chunk);

// append a byte to the end of the chunk
void writeChunk(
        Chunk *chunk,
        uint8_t byte,
        // when we write a byte of code, we need to know what source line it.
        int line);

int addConstant(Chunk *chunk, Value value);

// we need to free memory ourselves.
void freeChunk(Chunk *chunk);

#endif //COFFEE_CHUNK_H
