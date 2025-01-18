#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"

int main() {
    Date d1;
    cin >> d1;
    Date d2(d1.Get(), 1, 1);
    cout << d1 - d2 << endl;
}