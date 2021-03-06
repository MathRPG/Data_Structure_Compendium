#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "dynamic_stack.h"
#include "testing.h"

typedef void (* stack_test_function_t)(DynamicStack_t*);

#define TEMP_PTR(Type, Value) &(Type[]){Value}

void test_new_stack(struct DynamicStack_s* new_stack)
{
	assert(new_stack != NULL);

	assert(dyn_stack_is_empty(new_stack));

	const void* peeked = dyn_stack_peek(new_stack);
	assert(peeked == NULL);

	dyn_stack_pop(new_stack);
	assert(dyn_stack_is_empty(new_stack));
	assert(dyn_stack_status() & DYN_STACK_UNDERFLOW);
}

void test_stack_pushed_once(DynamicStack_t* stack)
{
	const int value = 0;
	dyn_stack_push(stack, TEMP_PTR(int, value));

	assert(dyn_stack_is_empty(stack) == false);

	const int* peeked = (int*)dyn_stack_peek(stack);
	assert(*peeked == value);
}

void test_stack_pushed_twice(DynamicStack_t* stack)
{
	const int first_value = 1;
	const int second_value = 2;
	dyn_stack_push(stack, TEMP_PTR(int, first_value));
	dyn_stack_push(stack, TEMP_PTR(int, second_value));

	const int* peeked = (int*)dyn_stack_peek(stack);
	assert(*peeked == second_value);
}

void test_stack_pushed_and_popped_once(DynamicStack_t* stack)
{
	dyn_stack_push(stack, TEMP_PTR(int, 0));
	dyn_stack_pop(stack);

	assert(dyn_stack_is_empty(stack));
	assert((dyn_stack_status() & DYN_STACK_UNDERFLOW) == false);
	assert(dyn_stack_peek(stack) == NULL);
}

void test_stack_pushed_twice_and_popped_once(DynamicStack_t* new_stack)
{
	const int first_value = 1;
	const int second_value = 2;
	dyn_stack_push(new_stack, TEMP_PTR(int, first_value));
	dyn_stack_push(new_stack, TEMP_PTR(int, second_value));
	dyn_stack_pop(new_stack);

	assert(dyn_stack_is_empty(new_stack) == false);
	assert((dyn_stack_status() & DYN_STACK_UNDERFLOW) == false);

	const int* peeked = (int*)dyn_stack_peek(new_stack);
	assert(*peeked == first_value);
}

void run_tests()
{
	DynamicStack_t* stack = NULL;

	stack_test_function_t test_functions[] = {
			test_new_stack,
			test_stack_pushed_once,
			test_stack_pushed_twice,
			test_stack_pushed_and_popped_once,
			test_stack_pushed_twice_and_popped_once,
	};

	for (int i = 0; i < sizeof test_functions / sizeof *test_functions; ++i)
	{
		stack = dyn_stack_new(sizeof(int));
		test_functions[i](stack);
		dyn_stack_delete(stack);
	}

	test_status_flag = TEST_SUCCESS;
}

int main(void)
{
	printf("Hello, world!\n");

	set_up_tests();
	run_tests();

	return EXIT_SUCCESS;
}
