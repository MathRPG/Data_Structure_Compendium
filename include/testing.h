#ifndef DATA_STRUCTURES_TESTING_H
#define DATA_STRUCTURES_TESTING_H

#include <stdio.h>

int test_status_flag;
const int TEST_FAILURE = 0;
const int TEST_SUCCESS = 1;

void show_test_status()
{
	if (test_status_flag == TEST_FAILURE)
	{
		fprintf(stdout, "\033[1;31m");
		printf("❌ Tests failed!");
	}
	else
	{
		fprintf(stdout, "\033[1;32m");
		printf("✔ Tests passed!");
	}
	fprintf(stdout, "\033[0m");
}

void set_up_tests()
{
	test_status_flag = TEST_FAILURE;
	atexit(show_test_status);
}

#endif //DATA_STRUCTURES_TESTING_H
