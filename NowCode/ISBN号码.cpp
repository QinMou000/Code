#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;

string str;

int main() {
    // 理解 + 模拟
    cin >> str;
    LL n = str.size();
    vector<LL> arr;
    char com;
    for (LL i = 0; i < n ; i++) {
        if (i < n - 1 && str[i] >= '0' && str[i] <= '9')
            arr.push_back(str[i] - '0');
        if (i == n - 1)
            com = str[i];
    }

    LL num = 0;
    for (LL i = 0; i < arr.size(); i++) {
        num += arr[i] * (i + 1);
        num %= 11;
    }
    if (num == com - '0' || (num == 10 && com == 'X')) cout << "Right" << endl;
    else {
        str[n - 1] = (num == 10 ? 'X' : '0' + num);
        cout << str << endl;
    }

}