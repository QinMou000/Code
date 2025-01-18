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
// ��λnew/replacement new
int main()
{
	// p1����ָ���ֻ��������A������ͬ��С��һ�οռ䣬����������һ��������Ϊ���캯��û��ִ��
	A* p1 = (A*)malloc(sizeof(A));
	new(p1)A; // ע�⣺���A��Ĺ��캯���в���ʱ���˴���Ҫ����
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
//operator new���ú���ʵ��ͨ��malloc������ռ䣬��malloc����ռ�ɹ�ʱֱ�ӷ��أ�����ռ�
//ʧ�ܣ�����ִ�п� �䲻��Ӧ�Դ�ʩ�������Ӧ�Դ�ʩ�û������ˣ���������룬��
//�����쳣��
//*/
//void* __CRTDECL operator new(size_t size) _THROW1(_STD bad_alloc)
//{
//	// try to allocate size bytes
//	void* p;
//	while ((p = malloc(size)) == 0)
//		if (_callnewh(size) == 0)
//		{
//			// report no memory
//			// ��������ڴ�ʧ���ˣ�������׳�bad_alloc �����쳣
//			static const std::bad_alloc nomem;
//			_RAISE(nomem);
//		}
//	return (p);
//}
///*
//operator delete: �ú���������ͨ��free���ͷſռ��
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
//free��ʵ��
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
	// new/delete �� malloc/free��������� new/delete���ڡ��Զ������͡����˿��ռ�
	//������ù��캯������������
	A* p1 = (A*)malloc(sizeof(A));
	A* p2 = new A(1);
	free(p1);
	delete p2;

	// ���������Ǽ�����һ����
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
	int* ptr1 = new int;//��̬����һ��int���͵Ŀռ�
	int* ptr2 = new int(2);//��̬����һ��int���͵Ŀռ䣬 ����ʼ��Ϊ2
	int* ptr3 = new int[10];//��̬����10��int���͵Ŀռ�
	int* ptr4 = new int[5] {1, 2, 3, 4, 5};//��̬����5��int���͵Ŀռ䲢��ʼ��

	delete ptr1;
	delete ptr2;
	delete[] ptr3;
	delete[] ptr4;//ע��Ҫƥ�䷽����


	return 0;
}
#endif