#include "Functions.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main()
{
    char str[201];

    cout << "Enter string: ";
    cin.getline(str, 200);

    ChangeStr(str);

    cout << "Modified string: " << str << endl;

    return 0;
}
