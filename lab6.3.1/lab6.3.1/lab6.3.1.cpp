#include "IterativeFunctions.h"
#include <iostream>
using namespace std;


int main()
{
	const int n = 10;

	int a[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int s1 = Sum(a, n);
	cout << "Sum(a, n) = " << s1 << endl;

}

