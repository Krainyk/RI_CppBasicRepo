#include "RecursiveFunctions.h"
#include <iostream>

int Sum(int* a, const int size) {
	if (size == 0) {
		return 0;
	}

	int sum_of_the_rest = Sum(a + 1, size - 1);

	if (a[0] % 2 != 0) {
		return a[0] + sum_of_the_rest;
	}
	else {
		return sum_of_the_rest;
	}
}