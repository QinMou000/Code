#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
const int MAX_SIZE = 100;
// 三元组结构体
struct Triple {
    int row;
    int col;
    int value;
};
// 稀疏矩阵类
class SparseMatrix {
private:
    Triple data[MAX_SIZE];
    int rows;
    int cols;
    int numNonZero;
public:
    SparseMatrix(int r, int c) : rows(r), cols(c), numNonZero(0) {}

    void setValue(int row, int col, int value) {
        if (value != 0) {
            data[numNonZero].row = row;
            data[numNonZero].col = col;
            data[numNonZero].value = value;
            numNonZero++;
        }
    }
    void displayAsArray() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                bool found = false;
                for (int k = 0; k < numNonZero; k++) {
                    if (data[k].row == i && data[k].col == j) {
                        cout << data[k].value << " ";
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
};