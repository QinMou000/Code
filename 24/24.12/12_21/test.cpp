#include<iostream>
#include<list>
using namespace std;
int main()
{
    list<int> l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    l.push_back(40);
    cout << l.front() << endl;
    cout << l.back() << endl;
    l.pop_front();
    l.pop_back();
    cout << l.front() << endl;
    cout << l.back() << endl;
    return 0;
    int a = -7%2;
    printf("%d",a);
    return 0;
}