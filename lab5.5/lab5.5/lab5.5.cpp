#include <iostream>
using namespace std;

int f(int n) {
	if (n % 10 > 0) {
		return n % 10;
	}
	else {
		if (n == 0) {
			return 0;
		}
		else {
			return f(n / 10);
		}
	}
}

int main()
{
	int n;
	cout << "n = ";
	cin >> n;
	cout << f(n) << endl;

	int p, q, S=0;
	cout << "p = ";
	cin >> p;
	cout << "q = ";
	cin >> q;
	for (int i = p; i <= q; i++) {
		S += f(i);
	}
	cout << "S = " << S << endl;
}