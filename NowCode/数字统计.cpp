#include <iostream>
using namespace std;

int l, r;

int check(int i) {
    int ret = 0;
    while (i) {
        if (i % 10 == 2)
            ret++;
        i /= 10;
    }
    return ret;
}

int main() {
    cin >> l >> r;
    int ans = 0;
    for (int i = l; i <= r; i++)
        ans += check(i);
    cout << ans << endl;
}