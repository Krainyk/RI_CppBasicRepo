#include "Functions.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    char line[256];
    cout << "Enter string: ";
    cin.getline(line, 256);

    int result = countWords(line);

    cout << "Number of words with the same first and last character: " << result << endl;
    return 0;
}
