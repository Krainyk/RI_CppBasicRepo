#include "IterativeFunctions.h"
#include <iostream>
using namespace std;

int Sum(int* a, const int size)
{
	int s = 0;
	for (int i = 0; i < size; i++)
	{
		if (a[i] % 2 != 0) {
			s += a[i];
		}
	}
	return s;
}