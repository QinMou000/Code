#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<stack>
using namespace std;

class MinStack {
public:
    void push(int val) {
        _st.push(val);
        if (_minst.empty() || val <= _minst.top())
            _minst.push(val);
    }
    void pop() {
        if (_st.top() == _minst.top())
            _minst.pop();
        _st.pop();
    }
    int top() {
        return _st.top();
    }
    int getMin() {
        return _minst.top();
    }
private:
    stack<int> _st;
    stack<int> _minst;
};

class MinStack {
public:
    void push(int val) {
        _st.push(val);
        if (val <= _minst.top() || _minst.empty())
            _minst.push(val);
    }
    void pop() {
        if (_st.top() == _minst.top())
            _minst.pop();
        _st.pop();
    }
    int top() {
        return _st.top();
    }
    int getMin() {
        return _minst.top();
    }
private:
    stack<int> _st;
    stack<int> _minst;
};
