#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
bool isSaddlePoint(int A[][20], int m, int n, int row, int col) {
    int value = A[row][col];
    // 检查是否是该行最小
    for (int j = 0; j < n; j++) {
        if (A[row][j] < value) {
            return false;
        }
    }
    // 检查是否是该列最大
    for (int i = 0; i < m; i++) {
        if (A[i][col] > value) {
            return false;
        }
    }
    return true;
}
void findSaddlePoints(int A[][20], int m, int n) {
    for (int i = 0; i < m; i++) {
        int minIndex = 0;
        for (int j = 1; j < n; j++) {
            if (A[i][j] < A[i][minIndex]) {
                minIndex = j;
            }
        }
        if (isSaddlePoint(A, m, n, i, minIndex)) {
            std::cout << "Saddle point at (" << i << ", " << minIndex << "): " << A[i][minIndex] << std::endl;
        }
    }
}