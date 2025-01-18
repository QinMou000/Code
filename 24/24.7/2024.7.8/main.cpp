
#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//
//int main()
//{
//	printf("hello world\n");
//
//	return 0;
//}


//#include<iostream>
////using namespace std;
//
//int main()
//{
//	std::cout << "hello world\n" << std::endl;
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//int rand = 10;
//
//int main()
//{
//	printf("%d\n",rand);
//	// 编译报错：error C2365: “rand”: 重定义；以前的定义是“函数”
//	return 0;
//}


//#include<stdio.h>
//#include<stdlib.h>
//namespace Qinmou
//{
//	int rand = 0;
//	int Add(int a, int b)
//	{
//		return a + b;
//	}
//	struct Node {
//		int a;
//		struct Node* next;
//	};
//}
//
//int main()
//{
//	// 这⾥默认是访问的是全局的rand函数指针
//	printf("%p\n", rand);
//	// 这⾥指定Qinmou命名空间中的rand
//	printf("%d\n", Qinmou::rand);
//
//	return 0;
//}
//
//#include<stdio.h>
//#include<stdlib.h>
//namespace Qinmou
//{
//	namespace Qin {
//		int a = 0;
//		int Add(int a, int b)
//		{
//			return a + b;
//		}
//	}
//	namespace Wang {
//		int a = 1;
//		int Add(int a, int b)
//		{
//			return (a + b) * 10;
//		}
//	}
//}
//int main()
//{
//	printf("%d\n", Qinmou::Qin::a);
//	printf("%d\n", Qinmou::Wang::a);
//
//	printf("%d\n", Qinmou::Qin::Add(1, 2));
//	printf("%d\n", Qinmou::Wang::Add(1, 2));
//
//	return 0;
//}

//#include<stdio.h>
//namespace bit
//{
//	int a = 0;
//	int b = 1;
//} 
//int main()
//{
//	// 编译报错：error C2065: “a”: 未声明的标识符
//	printf("%d\n", a);
//	return 0;
//}

//using namespace Qin;
//int main()
//{
//	printf("%d\n", a);
//	printf("%d\n", b);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int a;
//	double b;
//	char c;
//	cin >> a >> b >> c;//可以自动识别变量的类型
//	cout << a << " " << b << " " << c << endl;
//	return 0;
//}
//
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	// 在io需求比较高的地方，如部分大量输入的竞赛题中
//	// 加上以下三行代码可以提高C++IO效率
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	return 0;
//}



//#include<iostream>
//using namespace std;
//
////void fun(int a = 10, int b = 20, int c = 30)//全缺省
////{
////	cout << a << " " << b << " " << c << endl;
////}
//
//void fun(int a, int b = 20, int c = 30)//半缺省
//{
//	cout << a << " " << b << " " << c << endl;
//}
//
//int main()
//{
//	fun();
//	return 0;
//}

//int Add(int a, int b)
//{
//	return a + b;
//}
//double Add(double a, double b)
//{
//	return a + b;
//}
//
//void fun()
//{
//	cout << "fun()" << endl;
//}
//void fun(int a)
//{
//	cout << "fun(int a)" << endl;
//}
//
//void fun(int a, char b)
//{
//	cout << "fun(int a,char b)" << endl;
//}
//void fun(char a, int b)
//{
//	cout << "fun(char a,int b)" << endl;
//}
// 
//void f()
//{
//	cout << "f()" << endl;
//}
//
//void f(int a = 10)
//{
//	cout << "f(int a = 10)" << endl;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int a = 0;
//
//	int& b = a;
//	int& c = a;
//	int& d = b;
//
//	++d;
//
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &c << endl;
//	cout << &d << endl;//地址是一样的，因为没有新变量
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int a = 0;
//
//	int& b = a;
//
//	int c = 20;
//
//	b = c;//这里不是让b引用c，C++的引用不能改变指向
//	      //这里是将c的值赋值给a（b是别名！！！）
//	return 0;
//}

//int Swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}

//void ListPushBack(LTNode** phead, int x);
//void ListPushBack(LTNode*& phead, int x);

//void STInit(St* ps, int n = 4);