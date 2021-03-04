#include <stdbool.h>
#include <stdlib.h>

#include "dynamic_stack.h"

struct DynamicStack_s
{
	unsigned item_count;
};

DynamicStack_t* dyn_stack_new(size_t item_size)
{
	DynamicStack_t * new_stack = malloc(sizeof(struct DynamicStack_s));
	new_stack->item_count = 0u;
	return new_stack;
}

void dyn_stack_delete(DynamicStack_t* stack)
{
	free(stack);
}

bool dyn_stack_is_empty(DynamicStack_t* stack)
{
	return stack->item_count == 0u;
}

void dyn_stack_push(DynamicStack_t* stack, void* p)
{
	stack->item_count++;
}

void dyn_stack_pop(DynamicStack_t* stack)
{
	stack->item_count--;
}
