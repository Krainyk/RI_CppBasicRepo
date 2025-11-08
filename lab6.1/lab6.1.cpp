#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "ArrayFunctions.h" // Include our .h file

using namespace std;

int main()
{
	srand(time(0));
	const int N = 23;
	int b[N];

	// Iterative approach
	cout << "=== Iterative approach ===" << endl;
	createArray(b, N, -25, 80);

	cout << "Initial array:" << endl;
	printArray(b, N);

	int count = countPositive(b, N);
	int sum = sumPositive(b, N);

	replaceWithzero(b, N);

	cout << "Number of positive odd elements:" << count << endl;
	cout << "Sum of positive odd elements:" << sum << endl;

	cout << "Modified array:" << endl;
	printArray(b, N);

	// Recursive approach
	cout << "\n=== Recursive approach ===" << endl;
	createArrayRec(b, N, 0, -25, 80);
	cout << "Initial array:" << endl;
	printArrayRec(b, N, 0);

	int countR = countPositiveRec(b, N, 0);
	int sumR = sumPositiveRec(b, N, 0);

	replaceWithzeroRec(b, N, 0);

	cout << "Number of positive odd elements:" << countR << endl;
	cout << "Sum of positive odd elements:" << sumR << endl;

	cout << "Modified array:" << endl;
	printArrayRec(b, N, 0);

	return 0;
}