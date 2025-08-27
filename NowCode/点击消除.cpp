#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str,st;
    cin >> str;
    for (auto ch : str) {
        if (st.size() && st.back() == ch) st.pop_back(); // 栈不为空 并且栈顶元素和当前元素相等 消除
        else st += ch; // 栈为空 或者 栈顶元素和当前元素不想等 补到栈后面
    }
    cout << (st.size() == 0 ? "0" : st) << endl;
}
// 64 位输出请用 printf("%lld")