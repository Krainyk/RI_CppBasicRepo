#include "IterativeFunctions.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> myArray = { 5, 2, 7, 8, 1, 4, -3 };
	printArray(myArray);

	int result = calculateSumOddIndices(myArray);

	cout << "Sum of indices of odd elements: " << result << endl;
	return 0;
}
