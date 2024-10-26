#define _CRT_SECURE_NO_WARNINGS 1
#include<string>

int index(const char* s1, const char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if (len2 > len1) return -1;
    for (int i = 0; i <= len1 - len2; i++) {
        int j;
        for (j = 0; j < len2; j++) {
            if (s1[i + j] != s2[j]) break;
        }
        if (j == len2) return i;
    }
    return -1;
}