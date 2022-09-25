//
// Created by Miku on 2022/9/25.
//

#ifndef COFFEE_VM_H
#define COFFEE_VM_H

#include "chunk.h"

typedef struct {
    Chunk *chunk;
    uint8_t *ip; // pointer of instruction which about to be executed.
} VM;

// The VM runs the chunk and then responds with a value from this enum:
typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} InterpretResult;

void initVM(VM *vm);

void freeVM(VM *vm);

// the main entrypoint into the VM
InterpretResult interpret(VM *vm, Chunk *chunk);

#endif //COFFEE_VM_H
