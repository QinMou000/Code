#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

void moveOddBeforeEven(int A[], int n) {
    int i = 0, j = n - 1;
    while (i < j) {
        while (A[i] % 2 == 1 && i < j) i++;
        while (A[j] % 2 == 0 && i < j) j--;
        if (i < j) {
            std::swap(A[i], A[j]);
        }
    }
}