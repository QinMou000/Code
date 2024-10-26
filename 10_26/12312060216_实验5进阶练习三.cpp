#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>

// 假设定长顺序存储结构的最大长度
const int MAX_LENGTH = 100;
// 删除串 s1 中所有 s2 子串
void deleteSubstring(char* s1, const char* s2) {
    char result[MAX_LENGTH];
    int i = 0, j = 0;
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    while (i < len1) {
        if (strncmp(&s1[i], s2, len2) != 0) {
            result[j++] = s1[i++];
        }
        else {
            i += len2;
        }
    }
    result[j] = '\0';
    strcpy(s1, result);
}