#include <iostream>
#include "macros.h"

using namespace std;

#define USE_FORMULA

int main() {
	double x, y, z, w;

    cout << "Enter x: ";
    cin >> x;

    cout << "Enter y: ";
    cin >> y;

    cout << "Enter z: ";
    cin >> z;

#ifdef USE_FORMULA
    if (z > 5) {
        w = POW(MAX(x * POW(y, 3), x + z), 2);
    }
    else {
        w = MIN(x - y * z, x * y + z);
    }

#else
    w = 0;
#endif

    PRINT("Result w = ");
    PRINT(w);
}
