#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "dynamic_stack.h"

struct DynamicStack_s
{
};

DynamicStack_t* dyn_stack_new(size_t item_size)
{
	return malloc(sizeof(struct DynamicStack_s));
}

void dyn_stack_delete(DynamicStack_t* stack)
{
	free(stack);
}

bool dyn_stack_is_empty(DynamicStack_t* pS)
{
	return true;
}
