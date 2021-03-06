#include <stdbool.h>
#include <stdlib.h>

#include "dynamic_stack.h"
#include "node.h"

struct DynamicStack_s
{
	struct Node_s* head;
	size_t item_size;
};

DynamicStack_t* dyn_stack_new(const size_t item_size)
{
	DynamicStack_t* new_stack = malloc(sizeof(*new_stack));

	*new_stack = (struct DynamicStack_s){
			.head = NULL,
			.item_size = item_size,
	};

	return new_stack;
}

void dyn_stack_delete(DynamicStack_t* const stack)
{
	for (Node_t* curr = stack->head; curr != NULL;)
	{
		Node_t* next_node = *node_next(curr);
		node_delete(curr);
		curr = next_node;
	}

	free(stack);
}

bool dyn_stack_is_empty(const DynamicStack_t* const stack)
{
	return stack->head == NULL;
}

const void* dyn_stack_peek(const DynamicStack_t* const stack)
{
	return dyn_stack_is_empty(stack) ? NULL : node_data(stack->head);
}

unsigned DYN_STATUS_FLAG = 0;

unsigned dyn_stack_status(void)
{
	return DYN_STATUS_FLAG;
}

const unsigned DYN_STACK_UNDERFLOW = 1;

void dyn_stack_push(DynamicStack_t* const stack, const void* const p)
{
	Node_t* old_head = stack->head;
	stack->head = node_new(p, stack->item_size);
	*node_next(stack->head) = old_head;
}

void dyn_stack_pop(DynamicStack_t* const stack)
{
	DYN_STATUS_FLAG = 0;

	if (dyn_stack_is_empty(stack))
	{
		DYN_STATUS_FLAG = DYN_STACK_UNDERFLOW;
		return;
	}

	Node_t* node_below = *node_next(stack->head);
	node_delete(stack->head);
	stack->head = node_below;
}
