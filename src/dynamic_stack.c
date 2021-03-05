#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "dynamic_stack.h"

typedef struct Node_s Node_t;

struct Node_s
{
	void* data;
};

struct DynamicStack_s
{
	unsigned item_count;
	size_t item_size;
	Node_t* element;
};

Node_t* node_new(const void* data, size_t size);

void node_delete(Node_t* pS);
DynamicStack_t* dyn_stack_new(const size_t item_size)
{
	DynamicStack_t* new_stack = malloc(sizeof(*new_stack));
	new_stack->item_count = 0u;
	new_stack->item_size = item_size;
	new_stack->element = NULL;
	return new_stack;
}

void dyn_stack_delete(DynamicStack_t* const stack)
{
	if (stack->element != NULL)
		node_delete(stack->element);
	free(stack);
}

void node_delete(Node_t* pS)
{
	free(pS->data);
	free(pS);
}

bool dyn_stack_is_empty(const DynamicStack_t* const stack)
{
	return stack->item_count == 0u;
}

void dyn_stack_push(DynamicStack_t* const stack, const void* const p)
{
	stack->item_count++;
	if (stack->element != NULL)
		node_delete(stack->element);
	stack->element = node_new(p, stack->item_size);
}

Node_t* node_new(const void* data, size_t size)
{
	Node_t * new_node = malloc(sizeof(*new_node));
	new_node->data = malloc(size);
	memcpy(new_node->data, data, size);
	return new_node;
}

unsigned DYN_STATUS_FLAG = 0;

const unsigned DYN_STACK_UNDERFLOW = 1;

void dyn_stack_pop(DynamicStack_t* const stack)
{
	DYN_STATUS_FLAG &= ~DYN_STACK_UNDERFLOW;
	if (dyn_stack_is_empty(stack))
		DYN_STATUS_FLAG |= DYN_STACK_UNDERFLOW;
	else
		stack->item_count--;
}

unsigned dyn_stack_status(void)
{
	return DYN_STATUS_FLAG;
}

const void* dyn_stack_peek(const DynamicStack_t* const stack)
{
	if (stack->element == NULL)
		return NULL;
	return stack->element->data;
}
