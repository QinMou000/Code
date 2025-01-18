#define _CRT_SECURE_NO_WARNINGS 1
#include<string>

bool isPrefix(const char* str1, const char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len2 < len1) return false;
    for (int i = 0; i < len1; i++) {
        if (str1[i] != str2[i]) return false;
    }
    return true;
}