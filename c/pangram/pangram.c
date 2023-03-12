#include "pangram.h"
#include <ctype.h>
#include <stdio.h>

bool is_pangram(const char *sentence) {
    if (sentence == NULL) return false;

    int count[26];
    for (int i = 0; i < 26; i++)
        count[i] = 0;

    for (const char *c = sentence; *c != '\0'; c++)
        if (isalpha(*c))
            // printf("%d\n", tolower(*c) - 97);
            count[tolower(*c) - 97]++;

    for (int i = 0; i < 26; i++)
        if (count[i] == 0) return false;

    return true;
}