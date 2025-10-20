#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
	double xp, xk, x, dx, eps, a = 0, R = 0, S = 0;

	int n = 0;

	cout << left;

	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "eps = "; cin >> eps;
	cout << fixed;
	cout << "-----------------------------------------" << endl;
	cout << "|" << setw(7) << "x" << " |"
		<< setw(10) << "atan(x)" << " |"
		<< setw(10) << "S" << " |"
		<< setw(5) << "n" << " |"
		<< endl;
	cout << "-----------------------------------------" << endl;
	x = xp;
	while (x <= xk) {
		n = 0;
		a = x;
		S = a;
		do {
			n++;
			R = -x * x * (2.0 * n - 1) / (2.0 * n + 1);
			a *= R;
			S += a;
		} while (abs(a) >= eps);

		cout << right;
		cout << "|" << setw(7) << setprecision(2) << x << " |"
			<< setw(10) << setprecision(5) << atan(x) << " |"
			<< setw(10) << setprecision(5) << S << " |"
			<< setw(5) << n << " |"
			<< endl;
		x += dx;
	}
	cout << "-----------------------------------------" << endl;
	return 0;
}