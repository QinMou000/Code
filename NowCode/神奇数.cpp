#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isOk(int n) {
    if (n < 2) return false;
    // for (int i = 2; i <= sqrt(n);i++) // 其实不用除到 n - 1 除到根号 n 即可
    for (int i = 2; i < n; i++)
        if (n % i == 0) return false ;
    return true;
}

int check(int i) {
    vector<int> arr;
    while (i) {
        arr.push_back(i % 10);
        i /= 10;
    }
    for (int j = 0; j < arr.size(); j++) {
        for (int k = 0; k < arr.size(); k++) {
            if (j != k && arr[j] != 0) { // 注意细节就行了
                if (isOk(arr[j] * 10 + arr[k])) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = a; i <= b; i++) {
        ans += check(i);
    }

    cout << ans << endl;

}
// 64 位输出请用 printf("%lld")

// link : https://www.nowcoder.com/practice/56d818ae68134c12b26e81f41ecafb9e?tpId=382&tqId=43806&rp=1&sourceUrl=%2Fexam%2Foj&difficulty=undefined&judgeStatus=undefined&tags=&title=%E7%A5%9E%E5%A5%87