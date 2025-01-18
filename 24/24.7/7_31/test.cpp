#define _CRT_SECURE_NO_WARNINGS 1
#include<vector>
#include<stack>
#include<iostream>

using namespace std;

bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
    stack<int> _st;
    for (int i = 0, j = 0; i < pushV.size() || j < popV.size(); i++, j++)
    {
        while (_st.empty() || _st.top() != popV[j++])
        {
            _st.push(pushV[i++]);
        }
        while (_st.top() == popV[j])
        {
            _st.pop();
            j++;
        }
    }
    if (_st.empty())
        return true;
    return false;
}

int main()
{

     
    return 0;
}