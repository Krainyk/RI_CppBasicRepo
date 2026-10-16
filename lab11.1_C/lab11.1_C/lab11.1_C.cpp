#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>

bool has_four_consecutive(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) return false;

    int prev = EOF;
    int count = 0;
    int c;

    while ((c = fgetc(file)) != EOF) {
        if (count == 0) {
            prev = c;
            count = 1;
        }
        else if (c == prev) {
            count++;
            if (count >= 4) {
                fclose(file);
                return true;
            }
        }
        else {
            prev = c;
            count = 1;
        }
    }

    fclose(file);
    return false;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const char* filename = "t.txt";
    if (has_four_consecutive(filename)) {
        printf("У файлі є 4 одинакових символа підряд.\n");
    }
    else {
        printf("У файлі немає 4 одинакових символа підряд.\n");
    }
    return 0;
}
