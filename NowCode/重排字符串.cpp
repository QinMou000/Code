#include <ios>
#include <iostream>
using namespace std;

int n;
char s[100005];
char ans[100005];
int hash_map[26] = {0}; // 哈希表 记录每个字符出现多少次
char maxChar = 0; // 出现次数最多的字符
int maxCount = 0; // 出现次数最多的字符出现的次数


int main() {
    cin >> n;
    cin >> s;
    // 填完 hash 表 + 统计
    for (int i = 0; i < n; i++) {
        int index = s[i] - 'a'; // hash 下标
        if (++hash_map[index] > maxCount) {
            maxChar = s[i];
            maxCount = hash_map[index]; // 同时算出 maxChar 和 maxCount
        }
    }
    if (maxCount > (n + 1) / 2)
        cout << "no" << endl;
    else {
        cout << "yes" << endl;
        // 填结果
        // 先填出现次数最多的
        int x = 0; // 下标
        while (maxCount--) {
            ans[x] = maxChar;
            x += 2;
        }
        // 之后再填其他的
        for (int i = 0; i < 26; i++) { // 遍历 hash 表
            if (hash_map[i] && i + 'a' != maxChar) {
                while (hash_map[i]--) {
                    if (x >= n) x = 1;
                    ans[x] = i + 'a';
                    x += 2;
                }
            }
        }
        for (int i = 0; i < n; i++)
            cout << ans[i];
        cout << endl;
    }

    return 0;
}
// 64 位输出请用 printf("%lld")

// link : https://www.nowcoder.com/practice/6c3a5604cf274b2287fbe27c5dc74743?tpId=382&tqId=44787&rp=1&sourceUrl=%2Fexam%2Foj%3FquestionJobId%3D10%26subTabName%3Donline_coding_page&difficulty=undefined&judgeStatus=undefined&tags=&title=%E9%87%8D%E6%8E%92%E5%AD%97%E7%AC%A6%E4%B8%B2