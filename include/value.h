//
// Created by Miku on 2022/9/25.
//

#ifndef COFFEE_VALUE_H
#define COFFEE_VALUE_H

#include "common.h"

typedef double Value;


/**The constant pool is an array of values.
 * The instruction to load a constant looks up the value
 * by index in that array.
 *
 */
typedef struct {
    int capacity;
    int count;
    Value *values;
} ValueArray;


void initValueArray(ValueArray *array);

void writeValueArray(ValueArray *array, Value value);

void freeValueArray(ValueArray *array);

void printValue(Value value);

#endif //COFFEE_VALUE_H
