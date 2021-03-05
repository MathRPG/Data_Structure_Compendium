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

unsigned DYN_STATUS_FLAG = 0;

const unsigned DYN_STACK_UNDERFLOW = 1;

void dyn_stack_pop(DynamicStack_t* const stack)
{
	DYN_STATUS_FLAG &= ~DYN_STACK_UNDERFLOW;
	if (dyn_stack_is_empty(stack))
		DYN_STATUS_FLAG |= DYN_STACK_UNDERFLOW;
	stack->item_count--;
}

unsigned dyn_stack_status(void)
{
	return DYN_STATUS_FLAG;
}

const void* dyn_stack_peek(const DynamicStack_t* const stack)
{
	return NULL;
}
