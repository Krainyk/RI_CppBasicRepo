#include <iostream>
#include <cmath>
using namespace std;

double h(double const x, double const y);

int main() {
	double s, t;

	cout << "s = ";
	cin >> s;
	cout << "t = ";
	cin >> t;

	double c = h(1, s + t) + h(s, s - t) - h(t, sqrt(s * s + t * t));
		cout << "c = " << c << endl;
		return 0;
}
double h(double const x, double const y)
{
	return  (x * x + y * y) / (1 + x * x + x * x * y * y);
}
