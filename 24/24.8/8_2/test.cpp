#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <vector>

//int main()
//{
//	vector<int> v{ 1,2,3,4,5,6 };
//	auto it = v.begin();
//	// ����ЧԪ�ظ������ӵ�100���������λ��ʹ��8��䣬�����ڼ�ײ������
//	// v.resize(100, 8);
//
//	// reserve�����þ��Ǹı����ݴ�С�����ı���ЧԪ�ظ����������ڼ���ܻ�����ײ������ı�
//	// v.reserve(100);
//		
//	// ����Ԫ���ڼ䣬���ܻ��������ݣ�������ԭ�ռ䱻�ͷ�
//	// v.insert(v.begin(), 0);
//	// v.push_back(8);
//	
//	// ��vector���¸�ֵ�����ܻ�����ײ������ı�
//		v.assign(100, 8);
//	/*
//	����ԭ�����ϲ��������п��ܻᵼ��vector���ݣ�Ҳ����˵vector�ײ�ԭ��ɿռ䱻��
//	�ŵ������ڴ�ӡʱ��it��ʹ�õ����ͷ�֮��ľɿռ䣬�ڶ�it����������ʱ��ʵ�ʲ�������һ��
//	�Ѿ����ͷŵĿռ䣬�������������ʱ������
//	�����ʽ�������ϲ������֮�������Ҫ����ͨ������������vector�е�Ԫ�أ�ֻ���
//	it���¸�ֵ���ɡ�
//	*/
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	return 0;
//}
//
//int main()
//{
//	int a[] = { 1, 2, 3, 4 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));//��������ʼ��
//	// ʹ��find����3����λ�õ�iterator
//	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
//	// ɾ��posλ�õ����ݣ�����pos������ʧЧ��
//	v.erase(pos);
//	cout << *pos << endl; // �˴��ᵼ�·Ƿ�����
//	return 0;
//}

//// 1. ����֮�󣬵������Ѿ�ʧЧ�ˣ�������Ȼ�������У��������н���Ѿ�������
//int main()
//{
//	vector<int> v{ 1,2,3,4,5 };
//	for (size_t i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//	cout << endl;
//	auto it = v.begin();
//	cout << "����֮ǰ��vector������Ϊ: " << v.capacity() << endl;
//	// ͨ��reserve���ײ�ռ�����Ϊ100��Ŀ����Ϊ����vector�ĵ�����ʧЧ
//	v.reserve(100);
//	cout << "����֮��vector������Ϊ: " << v.capacity() << endl;
//	// ��������reserve֮��it�������϶���ʧЧ����vs�³����ֱ�ӱ����ˣ�����linux�²���
//	// ��Ȼ�������У���������Ľ���ǲ��Ե�
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	return 0;
//}
////�����������Linux��
////1 2 3 4 5
////����֮ǰ��vector������Ϊ: 5
////����֮��vector������Ϊ: 100
////0 2 3 4 5 409 1 2 3 4 5

//
// //2. eraseɾ������λ�ô����linux�µ�������û��ʧЧ
// //��Ϊ�ռ仹��ԭ���Ŀռ䣬����Ԫ����ǰ�����ˣ�it��λ�û�����Ч��
//#include <vector>
//#include <algorithm>
//int main()
//{
//	vector<int> v{ 1,2,3,4,5 };
//	vector<int>::iterator it = find(v.begin(), v.end(), 3);
//	v.erase(it);
//	cout << *it << endl;
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	return 0;
//}
//��������������У�����ӡ��
//4
//4 5 


//// 3: eraseɾ���ĵ�������������һ��Ԫ�أ�ɾ��֮��it�Ѿ�����end
//// ��ʱ����������Ч�ģ�++it���³������
//int main()
//{
//	vector<int> v{ 1,2,3,4,5 };
//	// vector<int> v{1,2,3,4,5,6};
//	auto it = v.begin();
//	while (it != v.end())
//	{
//		if (*it % 2 == 0)
//			v.erase(it);
//		++it;
//	}
//	for (auto e : v)
//		cout << e << " ";
//	cout << endl;
//	return 0;
//}
////========================================================
//// ʹ�õ�һ������ʱ�������������
////[sly@VM - 0 - 3 - centos 20220114]$ g++ testVector.cpp - std = c++11
////[sly@VM - 0 - 3 - centos 20220114]$ . / a.out
////1 3 5
////======================================================== =
////// ʹ�õڶ�������ʱ���������ջ����
////[sly@VM - 0 - 3 - centos 20220114]$ vim testVector.cpp
////[sly@VM - 0 - 3 - centos 20220114]$ g++ testVector.cpp - std = c++11
////[sly@VM - 0 - 3 - centos 20220114]$ . / a.out
////Segmentation fault

//
//#include <string>
//void TestString()
//{
//	string s("hello");
//	auto it = s.begin();
//	// �ſ�ע��֮�������������Ϊresize��20��string���������
//	// ����֮��itָ��֮ǰ�ɿռ��Ѿ����ͷ��ˣ��õ�������ʧЧ��
//	// �����ӡʱ���ٷ���itָ��Ŀռ����ͻ����
//	//s.resize(20, '!');
//	while (it != s.end())
//	{
//		cout << *it;
//		++it;
//	}
//	cout << endl;
//	it = s.begin();
//	while (it != s.end())
//	{
//		it = s.erase(it);
//		// �������淽ʽд������ʱ������������Ϊerase(it)֮��
//		// itλ�õĵ�������ʧЧ��
//		// s.erase(it);
//		++it;
//	}
//}
void reserve(size_t n)
{
	if (n > capacity())
	{
		T* tmp = new T[n];
		//memcpy(tmp, _start, size() * sizeof(T));
		for (size_t i = 0; i < size(); i++)
		{
			tmp[i] = _start[i]// ���victor������string�������ֵ���õ���string�ĸ�ֵ���أ������Լ����¿ռ�
		}
		delete[] _start;

		_finish = size() + tmp;// һ��Ҫ�ȸ�finish����start����size()�����finishʧЧ������
		_start = tmp;
		_end_of_shorage = tmp + n;
	}
}