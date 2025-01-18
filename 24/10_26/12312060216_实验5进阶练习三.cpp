#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>

// ���趨��˳��洢�ṹ����󳤶�
const int MAX_LENGTH = 100;
// ɾ���� s1 ������ s2 �Ӵ�
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