#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;
    string s;
    int cnt = 0;
    while (n) {
        char ch = (n % 10) + '0';
        s += ch;
        n /= 10;
        cnt++;
        if (cnt == 3) {
            cnt = 0;
            s += ',';
        }
    }
    reverse(s.begin(), s.end());
    if(s[0] == ',')s.erase(0,1);
    cout << s;
}
// 64 位输出请用 printf("%lld")