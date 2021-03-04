//
// Created by Usuario on 03/04/21.
//

#ifndef DATA_STRUCTURES_TESTING_H
#define DATA_STRUCTURES_TESTING_H

#include <stdio.h>

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

#endif //DATA_STRUCTURES_TESTING_H
