#include <stdbool.h>
#include <stdlib.h>

#include "dynamic_stack.h"
#include "node.h"

struct DynamicStack_s
{
	struct Node_s* node;
	size_t item_size;
};

DynamicStack_t* dyn_stack_new(const size_t item_size)
{
	DynamicStack_t* new_stack = malloc(sizeof(*new_stack));
	*new_stack = (struct DynamicStack_s){
			.node = NULL,
			.item_size = item_size,
	};
	return new_stack;
}

void dyn_stack_delete(DynamicStack_t* const stack)
{
	// TODO: Can be optimized
	while (!dyn_stack_is_empty(stack))
		dyn_stack_pop(stack);
	free(stack);
}

bool dyn_stack_is_empty(const DynamicStack_t* const stack)
{
	return stack->node == NULL;
}

const void* dyn_stack_peek(const DynamicStack_t* const stack)
{
	return dyn_stack_is_empty(stack) ? NULL : node_data(stack->node);
}

unsigned DYN_STATUS_FLAG = 0;

const unsigned DYN_STACK_UNDERFLOW = 1;

unsigned dyn_stack_status(void)
{
	return DYN_STATUS_FLAG;
}

void dyn_stack_push(DynamicStack_t* const stack, const void* const p)
{
	Node_t* old = stack->node;
	stack->node = node_new(p, stack->item_size);
	*node_next(stack->node) = old;
}

void dyn_stack_pop(DynamicStack_t* const stack)
{
	DYN_STATUS_FLAG = 0;

	if (dyn_stack_is_empty(stack))
		DYN_STATUS_FLAG |= DYN_STACK_UNDERFLOW;
	else
	{
		Node_t* next_node = *node_next(stack->node);
		node_delete(stack->node);
		stack->node = next_node;
	}
}
