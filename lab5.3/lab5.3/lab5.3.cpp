#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double p(const double x);

int main() {
	double qp, qk, z;
	int n;

	cout << "qp = ";
	cin >> qp;
	cout << "qk = ";
	cin >> qk;
	cout << "n = ";
	cin >> n;

	double dq = (qk - qp) / n;
	double q = qp;

	cout << "\n+----------------+------------------+" << endl;
	cout << "|       q        |        z         |" << endl;
	cout << "+----------------+------------------+" << endl;
	cout << fixed << setprecision(7);

	while (q <= qk) {
		z = p(2 * q + 1) + pow(p(q * q - 1), 2) + sqrt(p(1));
		cout << "| " << setw(14) << q << " | "
			<< setw(16) << z << " |" << endl;
		
		
		q += dq;
	}
	cout << "+----------------+------------------+" << endl;
	return 0;
}

double p(const double x) {
	if (abs(x) >= 1)
		return (sin(x) + cos(x)) / (pow(sin(x), 2) + exp(x));
	else {
		double S = 0;
		int j = 0;
		double a = 1;
		S = 1;
		do {
			j++;
			double R = -x * x / ((2 * j - 1) * 2 * j);
				a *= R;
			S += a;
		} while (j < 4);
		return (1.0 / cos(x)) * S;
	}
}