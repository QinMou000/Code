#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
int main() {
    using namespace std;

    int n;
    cout << "请输入一个整数：";
    cin >> n;
    cout << n << " 的阶乘是：" << factorial(n) << endl;
    cout << "请输入斐波那契数列的项数：";
    cin >> n;
    cout << "斐波那契数列的第 " << n << " 项是：" << fibonacci(n) << endl;

    return 0;
}