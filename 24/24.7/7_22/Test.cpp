#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

//template<class T>
//T Swap(T x, T y){
//	T tmp = x;
//	x = y;
//	y = tmp;
//}
//int main()
//{
//	int a = 2;
//	int b = 3;
//	int ret1 = Swap(a, b);
//
//	double m = 1.0;
//	double n = 2.0;
//	double ret1 = Swap(m, n);
//
//	char p = '3';
//	char q = '4';
//	char ret1 = Swap(p, q);
//
//	return 0;
//}
//
//int& Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//double& Swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
//char& Swap(char& left, char& right)
//{
//	char temp = left;
//	left = right;
//	right = temp;
//}


//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.0, d2 = 20.0;
//	Add(a1, a2);
//	Add(d1, d2);
//	/*
//	����䲻��ͨ�����룬��Ϊ�ڱ����ڼ䣬��������������ʵ����ʱ����Ҫ������ʵ������
//	ͨ��ʵ��a1��T����Ϊint��ͨ��ʵ��d1��T����Ϊdouble���ͣ���ģ������б���ֻ��
//	һ��T���������޷�ȷ���˴����׸ý�Tȷ��Ϊint ���� double���Ͷ�����
//	ע�⣺��ģ���У�������һ�㲻���������ת����������Ϊһ��ת�������⣬����������Ҫ���ڹ�
//	Add(a1, d1);
//	*/
//	// ��ʱ�����ִ���ʽ��1. �û��Լ���ǿ��ת�� 2. ʹ����ʽʵ����
//	Add(a1, (int)d1);
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	double b = 20.0;
//	// ��ʽʵ����
//	Add<int>(a, b);
//	return 0;
//}

//// ר�Ŵ���int�ļӷ�����
//int Add(int left, int right)
//{
//	return left + right;
//}
//// ͨ�üӷ�����
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // ���ģ�庯��ƥ�䣬����������Ҫ�ػ�
//	Add<int>(1, 2); // ���ñ������ػ���Add�汾
//}

//// ר�Ŵ���int�ļӷ�����
//int Add(int left, int right)
//{
//	return left + right;
//}
//// ͨ�üӷ�����
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // ��Ǻ���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ����
//	Add(1, 2.0); // ģ�庯���������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���Add����
//}

//template<class T1, class T2, ����, class Tn>
//class ��ģ����
//{
//	// ���ڳ�Ա����
//};
//#include<iostream>
//using namespace std;
//// ��ģ��
//template<typename T>
//class Stack
//{
//public:
//	Stack(size_t capacity = 4)
//	{
//		_array = new T[capacity];
//		_capacity = capacity;
//		_size = 0;
//	}
//	void Push(const T& data);
//private:
//	T* _array;
//	size_t _capacity;
//	size_t _size;
//};
//// ģ�治���������Ͷ�����뵽�����ļ�.h ��.cpp��������Ӵ���
//template<class T>
//void Stack<T>::Push(const T& data)
//{
//	// ����
//	_array[_size] = data;
//	++_size;
//}
//int main()
//{
//	Stack<int> st1; // int
//	Stack<double> st2; // double
//	return 0;
//}

//// Stack��������Stack<int>��������
//Stack<int> st1; // int
//Stack<double> st2; // double

int main()
{
	string a = "hello world";
	string b = a;
	if (a.c_str() == b.c_str())
	{
		cout << "true" << endl;
	}
	else cout << "false" << endl;
	string c = b;
	c = "";
	if (a.c_str() == b.c_str())
	{
		cout << "true" << endl;
	}
	else cout << "false" << endl;
	a = "";
	if (a.c_str() == b.c_str())
	{
		cout << "true" << endl;
	}
	else cout << "false" << endl;
	return 0;

}