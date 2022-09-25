//
// Created by Miku on 2022/9/25.
//

#ifndef COFFEE_MEMORY_H
#define COFFEE_MEMORY_H

#include "common.h"

// This macro calculates a new capacity based on a given current capacity.
#define GROW_CAPACITY(capacity) \
((capacity) < 8 ? 8 : (capacity) * 2)

// This macro pretties up a function call to reallocate() where the real work happens.
// The macro itself take care of getting the size of the array's element type
// and casting the resulting void* back to a pointer of the right type.
#define GROW_ARRAY(type, pointer, oldCount, newCount) \
    (type*)reallocate(pointer, sizeof(type) * (oldCount),\
    sizeof(type) * (newCount))

// reallocate is the single function we'll use for all dynamic memory management.
// It will make easy when we add a garbage collector to keep track of how much memory
// is used.
//
// The tow size arguments passed to reallocate control which operation to perform:
//
// oldSize	  newSize	                Operation
// 0	      Non‑zero	                Allocate new block.
// Non‑zero	  0	                        Free allocation.
// Non‑zero	  Smaller than oldSize	    Shrink existing allocation.
// Non‑zero	  Larger than oldSize	    Grow existing allocation.
void *reallocate(void *pointer, size_t oldSize, size_t newSize);

#define FREE_ARRAY(type, pointer, oldCount) \
    reallocate(pointer, sizeof(type) * (oldCount), 0)

#endif //COFFEE_MEMORY_H
