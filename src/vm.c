//
// Created by Miku on 2022/9/25.
//

#include <stdio.h>
#include "../include/common.h"
#include "../include/vm.h"
#include "../include/debug.h"
#include "../include/compiler.h"

static void resetStack(VM *vm) {
    vm->stackTop = vm->stack;
}

void initVM(VM *vm) {
    resetStack(vm);
}

void freeVM(VM *vm) {

}

void push(VM *vm, Value value) {
    *vm->stackTop = value;
    vm->stackTop++;
}

Value pop(VM *vm) {
    vm->stackTop--;
    return *vm->stackTop;
}

static InterpretResult run(VM *vm) {
#define READ_BYTE() (*vm->ip++)
#define READ_CONSTANT() (vm->chunk->constants.values[READ_BYTE()])
#define BINARY_OP(op)\
    do {\
        double b = pop(vm); \
        double a = pop(vm); \
        push(vm, a op b); \
    } while(false)


    for (;;) {
#ifdef DEBUG_TRACE_EXECUTION
        // print the value in the stack
        printf("\n");
        for (Value *slot = vm->stack; slot < vm->stackTop; slot++) {
            printf("Stack: [ ");
            printValue(*slot);
            printf("  ]");
        }
        printf("\n");
        disassembleInstruction(vm->chunk, (int) (vm->ip - vm->chunk->code));
#endif
        uint8_t instruction = READ_BYTE();
        switch (instruction) {
            case OP_CONSTANT: {
                Value constant = READ_CONSTANT();
                push(vm, constant); // push value to stack
                printValue(constant);
                printf("\n");
                break;
            }
            case OP_ADD: {
                BINARY_OP(+);
                break;
            }
            case OP_SUBTRACT: {
                BINARY_OP(-);
                break;
            }
            case OP_MULTIPLY: {
                BINARY_OP(*);
                break;
            }
            case OP_DIVIDE: {
                BINARY_OP(/);
                break;
            }
            case OP_NEGATE: {
                push(vm, -pop(vm));
                break;
            }
            case OP_RETURN:
                // print the top value of the Stack
                printValue(pop(vm));
                printf("\n");
                return INTERPRET_OK;
        }
    }

#undef READ_BYTE     // end the marco scope earlier
#undef READ_CONSTANT // end the marco scope earlier
#undef BINARY_OP     // end the marco scope earlier
}

InterpretResult interpret(VM *vm, const char *source) {
    compile(source);
    return INTERPRET_OK;
}
