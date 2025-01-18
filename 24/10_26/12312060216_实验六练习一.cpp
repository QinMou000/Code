#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
void moveNonZeroToFront(int R[], int n) {
    int i = 0;
    for (int j = 0; j < n; j++) {
        if (R[j] != 0) {
            if (i != j) {
                std::swap(R[i], R[j]);
            }
            i++;
        }
    }
}