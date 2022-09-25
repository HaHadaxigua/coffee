//
// Created by Miku on 2022/9/25.
//

#include <stdlib.h>
#include "memory.h"
#include "chunk.h"

void initChunk(Chunk *chunk) {
    chunk->count = 0;
    chunk->capacity = 0;
    chunk->code = NULL;
}

void writeChunk(Chunk *chunk, uint8_t byte) {
    if (chunk->capacity < chunk->count + 1) {
        int oldCapacity = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(oldCapacity);
        chunk->code = GROW_ARRAY(uint8_t,
                                 chunk->code,
                                 oldCapacity,
                                 chunk->capacity);
    }

    chunk->code[chunk->count] = byte;
    chunk->count++;
}

// we deallocate all the memory
// and then call initChunk() to zero out the fields,
// leaving the chunk in a well-defined empty state.
void freeChunk(Chunk *chunk) {
    FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
    initChunk(chunk);
}