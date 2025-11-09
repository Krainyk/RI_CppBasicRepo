#include "IterativeFunctions.h"
#include <iostream>
using namespace std;

void printArray(const vector<int>& arr) {
	cout << "Array: ";
	for (int elements : arr) {
		cout << elements << " ";
	}
	cout << endl;
}

int calculateSumOddIndices(const vector<int>& arr) {
	int sum = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] % 2 != 0) {
			sum += i;
		}
	}
	return sum;
}