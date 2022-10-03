//
// Created by Miku on 2022/10/1.
//

#ifndef COFFEE_COMPILER_H
#define COFFEE_COMPILER_H

#include "chunk.h"
#include "scanner.h"



bool compile(const char *source, Chunk *chunk);

#endif //COFFEE_COMPILER_H
