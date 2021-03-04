#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "dynamic_stack.h"
#include "testing.h"

typedef void (* stack_test_function)(DynamicStack_t*);

void set_up_tests()
{
	test_status_flag = TEST_FAILURE;
	atexit(show_test_status);
}

void test_new_stack_properties(struct DynamicStack_s* new_stack)
{
	assert(new_stack != NULL);
	assert(dyn_stack_is_empty(new_stack));
}

#define TEMP_PTR(Type, Value) &(Type[]){Value}

void test_stack_pushed_once_is_not_empty(DynamicStack_t* new_stack)
{
	dyn_stack_push(new_stack, TEMP_PTR(int, 0));

	assert(dyn_stack_is_empty(new_stack) == false);

}

void test_stack_pushed_and_popped_once_is_empty(DynamicStack_t* new_stack)
{
	dyn_stack_push(new_stack, TEMP_PTR(int, 0));
	dyn_stack_pop(new_stack);

	assert(dyn_stack_is_empty(new_stack));
}

void test_stack_pushed_twice_and_popped_once_is_not_empty(DynamicStack_t* new_stack)
{
	dyn_stack_push(new_stack, TEMP_PTR(int, 0));
	dyn_stack_push(new_stack, TEMP_PTR(int, 0));
	dyn_stack_pop(new_stack);

	assert(dyn_stack_is_empty(new_stack) == false);
}

void run_tests()
{
	DynamicStack_t* stack = NULL;

	stack_test_function test_functions[] = {
			test_new_stack_properties,
			test_stack_pushed_once_is_not_empty,
			test_stack_pushed_and_popped_once_is_empty,
			test_stack_pushed_twice_and_popped_once_is_not_empty,
	};

	for (int i = 0; i < sizeof test_functions / sizeof *test_functions; ++i)
	{
		stack = dyn_stack_new(sizeof(int));

		test_functions[i](stack);

		dyn_stack_delete(stack);
	}
}

void run_tests_and_query_results()
{
	run_tests();
	test_status_flag = TEST_SUCCESS;
}

int main(void)
{
	printf("Hello, world!\n");

	set_up_tests();
	run_tests_and_query_results();

	return EXIT_SUCCESS;
}
