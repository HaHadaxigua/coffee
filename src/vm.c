//
// Created by Miku on 2022/9/25.
//

#include <stdio.h>
#include "../include/common.h"
#include "../include/vm.h"
#include "../include/debug.h"


void initVM(VM *vm) {

}

void freeVM(VM *vm) {

}

static InterpretResult run(VM *vm) {
#define READ_BYTE() (*vm->ip++)
#define READ_CONSTANT() (vm->chunk->constants.values[READ_BYTE()])

    for (;;) {
#ifdef DEBUG_TRACE_EXECUTION
        disassembleInstruction(vm->chunk, (int) (vm->ip - vm->chunk->code));
#endif
        uint8_t instruction = READ_BYTE();
        switch (instruction) {
            case OP_CONSTANT: {
                Value constant = READ_CONSTANT();
                printValue(constant);
                printf("\n");
                break;
            }
            case OP_RETURN:
                return INTERPRET_OK;
        }
    }

#undef READ_BYTE     // end the marco scope earlier
#undef READ_CONSTANT // end the marco scope earlier
}

InterpretResult interpret(VM *vm, Chunk *chunk) {
    vm->chunk = chunk;
    vm->ip = vm->chunk->code;
    return run(vm);
}
