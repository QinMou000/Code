#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;


class A
{
public:
	A(int a = 0)
		: _a(a)
	{
		cout << "A():" << this << endl;
	}
	~A()
	{
		cout << "~A():" << this << endl;
	}
private:
	int _a;
};
// 定位new/replacement new
int main()
{
	// p1现在指向的只不过是与A对象相同大小的一段空间，还不能算是一个对象，因为构造函数没有执行
	A* p1 = (A*)malloc(sizeof(A));
	new(p1)A; // 注意：如果A类的构造函数有参数时，此处需要传参
	p1->~A();
	free(p1);

	A* p2 = (A*)operator new(sizeof(A));
	new(p2)A(10);
	p2->~A();
	operator delete(p2);

	return 0;
}

//
///*
//operator new：该函数实际通过malloc来申请空间，当malloc申请空间成功时直接返回；申请空间
//失败，尝试执行空 间不足应对措施，如果改应对措施用户设置了，则继续申请，否
//则抛异常。
//*/
//void* __CRTDECL operator new(size_t size) _THROW1(_STD bad_alloc)
//{
//	// try to allocate size bytes
//	void* p;
//	while ((p = malloc(size)) == 0)
//		if (_callnewh(size) == 0)
//		{
//			// report no memory
//			// 如果申请内存失败了，这里会抛出bad_alloc 类型异常
//			static const std::bad_alloc nomem;
//			_RAISE(nomem);
//		}
//	return (p);
//}
///*
//operator delete: 该函数最终是通过free来释放空间的
//*/
//void operator delete(void* pUserData)
//{
//	_CrtMemBlockHeader* pHead;
//	RTCCALLBACK(_RTC_Free_hook, (pUserData, 0));
//	if (pUserData == NULL)
//		return;
//	_mlock(_HEAP_LOCK); /* block other threads */
//	__TRY
//		/* get a pointer to memory block header */
//		pHead = pHdr(pUserData);
//	/* verify block type */
//	_ASSERTE(_BLOCK_TYPE_IS_VALID(pHead->nBlockUse));
//
//	_free_dbg(pUserData, pHead->nBlockUse);
//
//	__FINALLY
//		_munlock(_HEAP_LOCK); /* release other threads */
//	__END_TRY_FINALLY
//	return;
//}
///*
//free的实现
//*/
//#define free(p) _free_dbg(p, _NORMAL_BLOCK)
#if 0
class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a = 0)" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};
int main()
{
	// new/delete 和 malloc/free最大区别是 new/delete对于【自定义类型】除了开空间
	//还会调用构造函数和析构函数
	A* p1 = (A*)malloc(sizeof(A));
	A* p2 = new A(1);
	free(p1);
	delete p2;

	// 内置类型是几乎是一样的
	int* p3 = (int*)malloc(sizeof(int)); // C
	int* p4 = new int;
	free(p3);
	delete p4;

	A* p5 = (A*)malloc(sizeof(A) * 10);
	A* p6 = new A[10];
	free(p5);
	delete[] p6;

	return 0;
}

int main()
{
	int* ptr1 = new int;//动态申请一个int类型的空间
	int* ptr2 = new int(2);//动态申请一个int类型的空间， 并初始化为2
	int* ptr3 = new int[10];//动态申请10个int类型的空间
	int* ptr4 = new int[5] {1, 2, 3, 4, 5};//动态申请5个int类型的空间并初始化

	delete ptr1;
	delete ptr2;
	delete[] ptr3;
	delete[] ptr4;//注意要匹配方括号


	return 0;
}
#endif