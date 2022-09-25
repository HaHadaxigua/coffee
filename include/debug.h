//
// Created by Miku on 2022/9/25.
//

#ifndef COFFEE_DEBUG_H
#define COFFEE_DEBUG_H

#include "chunk.h"

// disassemble all the instructions in the entire chunk
void disassembleChunk(Chunk *chunk, const char *name);

int disassembleInstruction(Chunk *chunk, int offset);

#endif //COFFEE_DEBUG_H
