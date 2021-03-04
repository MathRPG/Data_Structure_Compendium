#ifndef DATA_STRUCTURES_DYNAMIC_STACK_H
#define DATA_STRUCTURES_DYNAMIC_STACK_H

typedef struct DynamicStack_s DynamicStack_t;

DynamicStack_t* dyn_stack_new(size_t item_size);
void dyn_stack_delete(DynamicStack_t* stack);

#include <stdlib.h>
#endif //DATA_STRUCTURES_DYNAMIC_STACK_H
