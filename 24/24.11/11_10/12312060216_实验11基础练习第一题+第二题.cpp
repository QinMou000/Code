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
    cout << "������һ��������";
    cin >> n;
    cout << n << " �Ľ׳��ǣ�" << factorial(n) << endl;
    cout << "������쳲��������е�������";
    cin >> n;
    cout << "쳲��������еĵ� " << n << " ���ǣ�" << fibonacci(n) << endl;

    return 0;
}