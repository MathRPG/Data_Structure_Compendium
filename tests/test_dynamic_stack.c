#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "dynamic_stack.h"

int test_status_flag;
int TEST_FAILURE = 0;
int TEST_SUCCESS = 1;

int COLOR_RED_BOLD = 0;
int COLOR_GREEN_BOLD = 1;
int COLOR_RESET = 2;

void set_color(FILE* out, int color)
{
	if (color == COLOR_RED_BOLD)
		fprintf(out, "\033[1;31m");
	else if (color == COLOR_GREEN_BOLD)
		fprintf(out, "\033[1;32m");
	else
		fprintf(out, "\033[0m");
}

void show_test_status()
{
	if (test_status_flag == TEST_FAILURE)
	{
		set_color(stdout, COLOR_RED_BOLD);
		printf("❌ Tests failed!");
	}
	else
	{
		set_color(stdout, COLOR_GREEN_BOLD);
		printf("✔ Tests passed!");
	}
	set_color(stdout, COLOR_RESET);
}

void set_up_tests()
{
	test_status_flag = TEST_FAILURE;
	atexit(show_test_status);
}

void test_new_stack_properties()
{
	struct DynamicStack_s* new_stack = dyn_stack_new(sizeof(int));

	assert(new_stack != NULL);
	assert(dyn_stack_is_empty(new_stack));

	dyn_stack_delete(new_stack);
}

void test_one_element_stack_is_not_empty()
{
	DynamicStack_t* one_element_stack = dyn_stack_new(sizeof(int));
	dyn_stack_push(one_element_stack, &(int[]){ 5 });

	assert(dyn_stack_is_empty(one_element_stack) == false);

	dyn_stack_delete(one_element_stack);
}

void test_zero_element_stack_is_empty()
{
	DynamicStack_t* zero_element_stack = dyn_stack_new(sizeof(int));

	dyn_stack_push(zero_element_stack, &(int[]){ 0 });
	dyn_stack_pop(zero_element_stack);

	assert(dyn_stack_is_empty(zero_element_stack));

	dyn_stack_delete(zero_element_stack);
}

void run_tests()
{
	test_new_stack_properties();
	test_one_element_stack_is_not_empty();
	test_zero_element_stack_is_empty();

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
