#include "IterativeFunctions.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

int Count(char* str)
{
    size_t len = strlen(str);
    if (len < 4)
        return 0;

    int k = 0;                         // лічильник груп
    int count = 1;                    // лічильник однакових символів підряд

    for (size_t i = 1; i < len; i++)
    {
        if (str[i] == str[i - 1])
        {
            count++;
            if (count == 4)
                k++;
        }
        else
        {
            count = 1;
        }
    }

    return k;
}

char* Change(char* str)
{
    size_t len = strlen(str);
    if (len < 4)
        return str;

    char* tmp = new char[len + 1];
    char* t = tmp;
    tmp[0] = '\0';

    size_t i = 0;

    while (i < len)
    {
        size_t j = i + 1;
        while (j < len && str[j] == str[i])
            j++;

        size_t groupLen = j - i;

        if (groupLen >= 4)
        {
            size_t groups = groupLen / 4;
            for (int g = 0; g < groups; g++)
            {
                strcat(t, "**");
                t += 2;
            }

            int rem = groupLen % 4;
            for (int r = 0; r < rem; r++)
                *t++ = str[i];

            *t = '\0';
        }
        else
        {
            for (int r = 0; r < groupLen; r++)
                *t++ = str[i];
            *t = '\0';
        }

        i = j;
    }

    strcpy(str, tmp);
    return tmp;
}