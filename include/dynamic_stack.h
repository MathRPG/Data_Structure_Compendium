#ifndef DATA_STRUCTURES_DYNAMIC_STACK_H
#define DATA_STRUCTURES_DYNAMIC_STACK_H

typedef struct DynamicStack_s DynamicStack_t;

DynamicStack_t* dyn_stack_new(size_t item_size);
void dyn_stack_delete(DynamicStack_t* stack);

bool dyn_stack_is_empty(const DynamicStack_t* stack);
const void* dyn_stack_peek(const DynamicStack_t* stack);

const unsigned extern DYN_STACK_UNDERFLOW;
unsigned dyn_stack_status(void);

void dyn_stack_push(DynamicStack_t* stack, const void* p);
void dyn_stack_pop(DynamicStack_t* stack);

#endif //DATA_STRUCTURES_DYNAMIC_STACK_H
