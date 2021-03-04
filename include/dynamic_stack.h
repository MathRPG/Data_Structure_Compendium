#ifndef DATA_STRUCTURES_DYNAMIC_STACK_H
#define DATA_STRUCTURES_DYNAMIC_STACK_H

typedef struct DynamicStack_s DynamicStack_t;

DynamicStack_t* dyn_stack_new(size_t item_size);
void dyn_stack_delete(DynamicStack_t* stack);
bool dyn_stack_is_empty(DynamicStack_t* stack);
void dyn_stack_push(DynamicStack_t* stack, void* p);
void dyn_stack_pop(DynamicStack_t* stack);

unsigned dyn_stack_status(void);
const unsigned extern DYN_STACK_UNDERFLOW;

#include <stdlib.h>
#endif //DATA_STRUCTURES_DYNAMIC_STACK_H
