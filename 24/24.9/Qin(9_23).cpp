#include<iostream>
#include<vector>
#include<set>




using namespace std;
#if 0
string fun(string str)
{
    auto it = str.begin();
    int flag = 1;
    while (it < str.end())
    {
        if (*it == *(it + 1))
        {
            flag = 0;
            str.erase(it + 1);
            str.erase(it);
        }
        it++;
    }
    if (flag == 0)
        return fun(str);
    else
        return str;;
}
#endif

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

    multiset<int> m1;
    multiset<int> m2;

    for (auto e : nums1)
    {
        m1.insert(e);
    }
    for (auto e : nums2)
    {
        m2.insert(e);
    }

    vector<int> v;
    for (auto e1 : m1)
    {
        //for (auto e2 : m2)
        //{
        //    if (e1 == e2)
        //    {
        //        v.push_back(e1);
        //        m1.erase(e1);
        //        m2.erase(e2);
        //    }
        //    if (m1.empty() || m2.empty())
        //        return v;
        //}

        if (m2.find(e1) != m2.end())
        {
            v.push_back(e1);
            m2.erase(e1);
        }
    }
    return v;
}
int main() {

    string str;
    cin >> str;

    multiset<char> m;

    for (auto e : str)
    {
        m.insert(e);
    }
    
    for (auto e : m)
    {
        while (m.count(e) > 1)s
        {
            m.erase(e);
        }
    }

    str.clear();
    for (auto e : m)
    {
        str.push_back(e);
    }
    cout << str;
    //vector<int> v1 = { 1,2,3 };
    //vector<int> v2 = { 8,2,2,3,8 };


    //vector<int> v = intersection(v1, v2);
    //for (auto e : v)
    //{
    //    cout << e;
    //}

    //string str = {"abba"};
    //cin >> str;

    //if (str.empty())
    //    cout << "0";
    //else
    //    cout << fun(str);

    return 0;
}