#include "Functions.h"
#include <string>

int countWords(char line[]) {
    int count = 0;
    int len = strlen(line);
    int i = 0;

    while (i < len) {
        while (i < len && line[i] == ' ')
            i++;

        if (i >= len)
            break;

        int start = i;

        while (i < len && line[i] != ' ')
            i++;

        int end = i - 1;

        if (line[start] == line[end])
            count++;
    }

    return count;
}