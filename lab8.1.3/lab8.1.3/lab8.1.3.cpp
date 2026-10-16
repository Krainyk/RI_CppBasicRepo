#include "Functionschar.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main()
{
    char str[201];

    cout << "Enter string: ";
    cin.getline(str, 200);

    int cnt = CountStd(str);
    cout << "Number of quadruples: " << cnt << endl;

    char* modified = ChangeStd(str);
    cout << "Modified string: " << modified << endl;

    delete[] modified;

    return 0;
}
