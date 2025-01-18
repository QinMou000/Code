#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
class A
{
public:
	virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
	virtual void test() { func(); }
};
class B : public A
{
public:
	void func(int val = 0) { std::cout << "B->" << val << std::endl; }
};
int main(int argc, char* argv[])
{
	B* p = new B;
	p->test();
	return 0;
}

#if 0
class B1
{
public:
	virtual void fun1()
	{
		cout << "B1::fun1()";
	}
};
class B2
{
public:
	virtual void fun2()
	{
		cout << "B2::fun2()";
	}
};
class D:public B1,B2
{
public:
	virtual void fun1()
	{
		cout << "D::fun1()";
	}
	virtual void fun2()
	{
		cout << "D::fun2()";
	}
	virtual void fun3()
	{
		cout << "D::fun3()";
	}
};
int main()
{
	B1 b1;
	B2 b2;

	D d;
	return 0;
}


class A
{
public:
	virtual void fun()
	{
		cout << "A::fun()";
	}
};

class B
{
public:
	virtual void fun()
	{
		cout << "B::fun()";
	}
};

class C :public A ,public B
{
public:
	virtual void fun()
	{
		cout << "C::fun()";
	}
	virtual void cur()
	{
		cout << "C::cur()";
	}
};
class D:public C
{
public:
	virtual void fun()
	{
		cout << "D::fun()";
	}
	virtual void cur()
	{
		cout << "D::cur()";
	}
};

int main()
{
	A a;
	B b;
	C c;
	D d;


	A* pa = &a;
	B* pb = &b;
	C* pc = &c;
	D* pd = &d;

	C* p = &d;
	p->cur();
	return 0;
}

class A
{
public:
  A() 
	  :m_iVal(0) 
  { 
	  test(); 
  }
  virtual void func() 
  {
	  std::cout << m_iVal << ' ';
  }
  void test()
  { 
	  func();
  }
public:
  int m_iVal;
};
class B : public A
{
public:
	B() 
	{ 
		test(); 
	}
	virtual void func()
	{
		++m_iVal;
		std::cout << m_iVal << ' ';
	}
};
int main()
{
	A* p = new B;
	p->test();
	return 0;
}

class A
{
public:
	virtual void f()
	{
		cout << "A::f()" << endl;
	}
};

class B : public A
{
public:
	virtual void f()
	{
		cout << "B::f()" << endl;
	}
};
int main()
{
	A a;
	B b;
	
	b.A::f();
	return 0;
}

class A 
{
public:
	void f1() { cout << "A::f1()" << endl; }
	virtual void f2() { cout << "A::f2()" << endl; }
	virtual void f3() { cout << "A::f3()" << endl; }
};

class B : public A
{
public:
	virtual void f1() { cout << "B::f1()" << endl; }
	virtual void f2() { cout << "B::f2()" << endl; }
	void f3() { cout << "B::f3()" << endl; }
};

vector<int>& BubbleSort(vector<int>& v)
{
	for (int i = v.size(); i > 0; i--)
	{
		bool flag = 0;
		for (int j = 0; j < i - 1; j++)
		{
			if (v[j] > v[j + 1])
			{
				swap(v[j], v[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
	return v;
}

int main()
{
	srand(time(nullptr));
	vector<int> v{ 1,5,9,8,6,4,7,3,2 };
	for (auto e : BubbleSort(v))
	{
		cout << e;
	}
	cout << endl;

	return 0;
}

class A 
{ 
public: 
	void test(float a) 
	{ 
		cout << a;
	}
};
				
class B :public A 
{ 
public: 
	void test(int b)
	{ 
		cout << b; 
	} 
}; 
int main()
{ 
	A* a = new A;
	B* b = new B;
	a = b; 
	a->test(1.1f); 
	return 0;

}
#endif
