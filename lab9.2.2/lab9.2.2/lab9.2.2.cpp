#include <iostream>
#include "macros.h"

using namespace std;

// #define CHECK_EVEN
#define CHECK_POSITIVE

int main()
{
    double a, b, c;

    cout << "Enter a: ";
    cin >> a;

    cout << "Enter b: ";
    cin >> b;

    cout << "Enter c: ";
    cin >> c;

#ifdef CHECK_EVEN
    INFO("EVEN NUMBER CHECK ENABLED");

    if (IS_EVEN(a)) INFO("a is even");
    else INFO("a is NOT even");

    if (IS_EVEN(b)) INFO("b is even");
    else INFO("b is NOT even");

    if (IS_EVEN(c)) INFO("c is even");
    else INFO("c is NOT even");
#endif


#ifdef CHECK_POSITIVE
    INFO("POSITIVE NUMBER CHECK ENABLED");

    if (IS_POSITIVE(a)) INFO("a is positive");
    else INFO("a is NOT positive");

    if (IS_POSITIVE(b)) INFO("b is positive");
    else INFO("b is NOT positive");

    if (IS_POSITIVE(c)) INFO("c is positive");
    else INFO("c is NOT positive");
#endif

    return 0;
}
