#define _CRT_SECURE_NO_WARNINGS 1
#include"vector.h"
//int main() {
//    string s;
//    getline(cin, s);
//    string::reverse_iterator rit = s.rbegin();
//    int ans = 0;
//    while (rit != s.rend())
//    {
//        if (*rit == ' ')
//            break;
//        ans++;
//        ++rit;
//    }
//    cout << ans;
//}
//
//bool is_ok(char& ch)
//{
//    if (ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9')
//        return true;
//    return false;
//}
//
//bool isPalindrome(string s) {
//    for (char& ch : s)
//        if (ch >= 'A' && ch <= 'Z')
//            ch += 32;
//
//    int begin = 0;
//    int end = s.size() - 1;
//    while (begin <= end)
//    {
//        if (is_ok(s[begin]) && is_ok(s[end]))
//        {
//            if (s[begin] != s[end])
//                return false;
//        }
//        else if (!is_ok(s[begin]))
//        {
//            begin++;
//            continue;
//        }
//        else if (!is_ok(s[end]))
//        {
//            end--;
//            continue;
//        }
//
//        begin++;
//        end--;
//    }
//    return true;
//}

//int main()
//{
//    string s;
//    getline(cin, s);
//    cout << isPalindrome(s);
//
//    return 0;
//}


//int main()
//{
	//Qin::vector<int> v;
	//v.push_back(1);
	//v.push_back(2);
	//v.push_back(3);
	//v.push_back(4);

	//for (auto a : v)
	//	cout << a << ' ';
	//cout << endl;
	////print_vector(v);
	////v.insert(v.begin() + 2, 30);
	////print_vector(v);

	//int x;
	//cin >> x;
	//auto pos = find(v.begin(), v.end(),x);
	//if (pos != v.end())
	//	pos = v.insert(pos, 40);// insert后pos指向旧空间，迭代器失效 
	//*(pos + 1) *= 10;// 位置意义已经变了
	//Qin::print_vector(v);
	//v.erase(v.begin() + 2);
	//Qin::print_vector(v);
	//Qin::vector<int> v;
	//v.push_back(1);
	//v.push_back(2);
	//v.push_back(3);
	//v.push_back(4);
	//v.push_back(5);


	//auto it = v.begin();

	//while(it != v.end())
	//{
	//	if (*it % 2 == 0)
	//		v.erase(it);
	//	else
	//		it++;
	//}
	//Qin::print_container(v);
	//v.resize(2, 1);
	//Qin::print_vector(v);

	//Qin::vector<int> v2 = v;
	//Qin::print_container(v2);

	//Qin::vector<int> v3;
	//v3 = v2;
	//Qin::print_container(v3);

	//Qin::vector<int> v4(v2.begin()+2, v2.end());
	//Qin::print_container(v4);

	//list<int> lt;
	//lt.push_back(1);
	//lt.push_back(1);
	//lt.push_back(1);
	//lt.push_back(1);
	//Qin::print_container(lt);

	//list<int> lt2(v.begin(), v.end());
	//Qin::print_container(lt2);
	//Qin::vector<string> v1;
	//v1.push_back("xxxxxxxxx");
	//v1.push_back("xxxxxxxxx");
	//v1.push_back("xxxxxxxxx");
	//v1.push_back("xxxxxxxxx");
	//v1.push_back("xxxxxxxxx");

	//Qin::print_container(v1);
	//return 0;
//}
#include<vector>
void TestVectorExpand();
int main()
{
	//vector<int> v;
	//v.push_back(1);
	//v.push_back(2);
	//v.push_back(3);
	//v.push_back(4);
	//v.push_back(5);


	//cout << v.at(1) << endl;
	//cout << v[1] << endl;
	//int ar[] = { 1,2,3,4,5,6,7,8,9,10 };

	//int n = sizeof(ar) / sizeof(int);

	//vector<int> v(ar, ar + n);

	//cout << v.size() << ":" << v.capacity() << endl;
	TestVectorExpand();
	return 0;
}

// 测试vector的默认扩容机制
void TestVectorExpand()
{
	size_t sz;
	vector<int> v;
	sz = v.capacity();
	cout << "making v grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}