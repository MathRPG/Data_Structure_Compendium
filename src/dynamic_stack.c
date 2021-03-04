#include <stdbool.h>
#include <stdlib.h>

#include "dynamic_stack.h"

struct DynamicStack_s
{
	unsigned item_count;
};

DynamicStack_t* dyn_stack_new(const size_t item_size)
{
	DynamicStack_t * new_stack = malloc(sizeof(struct DynamicStack_s));
	new_stack->item_count = 0u;
	return new_stack;
}

void dyn_stack_delete(DynamicStack_t* const stack)
{
	free(stack);
}

bool dyn_stack_is_empty(const DynamicStack_t* const stack)
{
	return stack->item_count == 0u;
}

void dyn_stack_push(DynamicStack_t* const stack, const void* const p)
{
	stack->item_count++;
}

void dyn_stack_pop(DynamicStack_t* const stack)
{
	stack->item_count--;
}

const unsigned DYN_STACK_UNDERFLOW = 1;

unsigned dyn_stack_status(void)
{
	return 1;
}

const void* dyn_stack_peek(const DynamicStack_t* const stack)
{
	return NULL;
}
