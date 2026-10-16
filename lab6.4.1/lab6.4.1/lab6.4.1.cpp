#include <iostream>
#include <cmath>
using namespace std;

int main()
{   
	int n;
	cout << "Enter number of elements: ";
	cin >> n;

	double* p = new double[n];

	for (int i = 0; i < n; i++) {
		cout << "p[" << i << "] = ";
		cin >> p[i];
	}

	double maxAbs = abs(p[0]);   // спочатку беремо перший елемент €к найб≥льший за модулем
	for (int i = 1; i < n; i++) {
		if (abs(p[i]) > maxAbs) {
			maxAbs = abs(p[i]);  // €кщо знайшли б≥льший за модулем Ч запам'€товуЇмо
		}
	}
	cout << "The biggest element in abs: " << maxAbs << endl;

	int firstPos = -1, secondPos = -1;

	for (int i = 0; i < n; i++) {
		if (p[i] > 0) {
			if (firstPos == -1)
				firstPos = i;
			else {
				secondPos = i;
				break;
			}
		}
	}

	double sum = 0;
	if (firstPos != -1 && secondPos != -1 && secondPos - firstPos > 1) {
		for (int i = firstPos + 1; i < secondPos; i++) {
			sum += p[i];
		}
		cout << "Sum between first and second positive elements: " << sum << endl;
	}
	else {
		cout << "There are no two positive elements or there is nothing between them." << endl;
	}

	int index = 0;
	double* result = new double[n];
	for (int i = 0; i < n; i++) {
		if (p[i] != 0) {
			result[index] = p[i];
			index++;
		}
	}
		
	for (int i = index; i < n; i++) {
		result[i] = 0;
	}
	
	cout << "Transformed Array: ";
	for (int i = 0; i < n; i++) {
		cout << result[i] << " ";
	}
	cout << endl;

	delete[]p;
	delete[]result;
}
