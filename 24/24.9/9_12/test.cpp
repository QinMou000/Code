#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#if 0
class person
{
public:
	// 进⼊校园/图书馆/实验室刷⼆维码等⾝份认证
	void identity()
	{
		cout << "void identity()" << _name << endl;
	}
protected:
	string _name = "张三"; // 姓名
	int _age = 18; // 年龄
	string _address; // 地址
	string _tel; // 电话
};

class Student :public person
{
public:
	// 学习
	void study()
	{
		// ...
	}
protected:
	int _stuid; // 学号
};
class Teacher :public person
{
public:
	// 授课
	void teaching()
	{
		//...
	}
protected:
	string _title; // 职称
};
//int main()
//{
//	Student s;
//	Teacher t;
//	s.identity();
//	t.identity();
//
//	return 0;
//}

// stack和vector的关系，既符合is-a，也符合has-a
template<class T>
class stack : public std::vector<T>
{
public:
	void push(const T& x)
	{
		// 基类是类模板时，需要指定⼀下类域，
		// 否则编译报错:error C3861: “push_back”: 找不到标识符

		// 因为stack<int>实例化时，也实例化vector<int>了
		// 但是模版是按需实例化，push_back等成员函数未实例化，所以找不到
		vector<T>::push_back(x);
		//push_back(x);
	}
};

class Person
{
protected:
	string _name; // 姓名
	string _sex; // 性别
	int _age; // 年龄
};
class Student : public Person
{
public:
	int _No; // 学号
};
int main()
{
	Student sobj;
	// 1.派⽣类对象可以赋值给基类的指针/引⽤
	Person* pp = &sobj;
	Person& rp = sobj;
	// ⽣类对象可以赋值给基类的对象是通过调⽤后⾯会讲解的基类的拷⻉构造完成的
	Person pobj = sobj;
	//2.基类对象不能赋值给派⽣类对象，这⾥会编译报错
	sobj = pobj;
	return 0;
}

// Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是⾮常容易混淆
class Person
{
protected:
	string _name = "⼩李⼦"; // 姓名
	int _num = 111; // ⾝份证号
};
class Student : public Person
{
public:
	void Print()
	{
		cout << " 姓名:" << _name << endl;
		cout << " ⾝份证号:" << Person::_num << endl;
		cout << " 学号:" << _num << endl;
	}
protected:
	int _num = 999; // 学号
};
int main()
{
	Student s1;
	s1.Print();
	return 0;
};

class A
{
public:
	void fun()
	{
		cout << "func()" << endl;
	}
};
class B : public A
{
public:
	void fun(int i)
	{
		cout << "func(int i)" << i << endl;
	}
};
int main()
{
	B b;
	b.fun(10);
	b.fun();
	return 0;
};

class Person
{
public:
	Person(const char* name = "peter")
		: _name(name)
	{
		cout << "Person()" << endl;
	}
	Person(const Person& p)
		: _name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}
	Person& operator=(const Person& p)
	{
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
			_name = p._name;
		return *this;
	}
	~Person()
	{
		cout << "~Person()" << endl;
	}
protected:
	string _name; // 姓名
};
class Student : public Person
{
public:
	Student(const char* name, int num)
		: Person(name)
		, _num(num)
	{
		cout << "Student()" << endl;
	}
	Student(const Student& s)
		: Person(s)
		, _num(s._num)
	{
		cout << "Student(const Student& s)" << endl;
	}
	Student& operator = (const Student& s)
	{
		cout << "Student& operator= (const Student& s)" << endl;
		if (this != &s)
		{
			// 构成隐藏，所以需要显⽰调⽤
			Person::operator =(s);
			_num = s._num;
		}
		return *this;
	}
	~Student()
	{
		cout << "~Student()" << endl;
	}
protected:
	int _num; //学号
};
int main()
{
	Student s1("jack", 18);
	Student s2(s1);
	Student s3("rose", 17);
	s1 = s3;
	return 0;
}

// C++11的⽅法
class Base final
{
public:
	void func5() { cout << "Base::func5" << endl; }
protected:
	int a = 1;
private:
	// C++98的⽅法
	/*Base()
	{}*/
};

class Derive :public Base
{
	void func4() { cout << "Derive::func4" << endl; }
protected:
	int b = 2;
};
int main()
{
	Base b;
	Derive d;
	return 0;
}


class Student;
class Person
{
public:
	friend void Display(const Person& p, const Student& s);
protected:
	string _name; // 姓名
};
class Student : public Person
{
protected:
	int _stuNum; // 学号
};
void Display(const Person& p, const Student& s)
{
	cout << p._name << endl;
	cout << s._stuNum << endl;
}
int main()
{
	Person p;
	Student s;
	// 编译报错：error C2248: “Student::_stuNum”: ⽆法访问 protected 成员
	// 解决⽅案：Display也变成Student 的友元即可
	Display(p, s);
	return 0;
}


class Person
{
public:
	string _name;
	static int _count;
};
int Person::_count = 0;
class Student : public Person
{
protected:
	int _stuNum;
};
int main()
{
	Person p;
	Student s;
	// 这⾥的运⾏结果可以看到⾮静态成员_name的地址是不⼀样的
	// 说明派⽣类继承下来了，⽗派⽣类对象各有⼀份
	cout << &p._name << endl;
	cout << &s._name << endl;
	// 这⾥的运⾏结果可以看到静态成员_count的地址是⼀样的
	// 说明派⽣类和基类共⽤同⼀份静态成员
	cout << &p._count << endl;
	cout << &s._count << endl;
	// 公有的情况下，⽗派⽣类指定类域都可以访问静态成员
	cout << Person::_count << endl;
	cout << Student::_count << endl;
	return 0;
}

#endif
//class Person
//{
//public:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//protected:
//	int _num; //学号
//};
//class Teacher : public Person
//{
//protected:
//	int _id; // 职⼯编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//int main()
//{
//	// 编译报错：error C2385: 对“_name”的访问不明确
//	Assistant a;
//	a._name = "peter";
//	// 需要显⽰指定访问哪个基类的成员可以解决⼆义性问题，但是数据冗余问题⽆法解决
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//	return 0;
//}

//class Person
//{
//public:
//	string _name; // 姓名
//	/*int _tel;
//	 int _age;
//	string _gender;
//	string _address;*/
//	// ...
//};
//// 使⽤虚继承Person类
//class Student : virtual public Person
//{
//protected:
//	int _num; //学号
//};
//// 使⽤虚继承Person类
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // 职⼯编号
//};
//// 教授助理
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//int main()
//{
//	// 使⽤虚继承，可以解决数据冗余和⼆义性
//	Assistant a;
//	a._name = "peter";
//	return 0;
//}

//class Person
//{
//public:
//	Person(const char* name)
//		:_name(name)
//{}
//string _name; // 姓名
//};
//class Student : virtual public Person
//{
//public:
//	Student(const char* name, int num)
//		:Person(name)
//		, _num(num)
//	{}
//protected:
//	int _num; //学号
//};
//class Teacher : virtual public Person
//{
//public:
//	Teacher(const char* name, int id) 
//		:Person(name)
//		, _id(id)
//	{}
//protected:
//	int _id; // 职⼯编号
//};
//// 不要去玩菱形继承
//class Assistant : public Student, public Teacher
//{
//public:
//	Assistant(const char* name1, const char* name2, const char* name3)
//		:Person(name3)
//		, Student(name1, 1)
//		, Teacher(name2, 2)
//	{}
//protected:
//	string _majorCourse; // 主修课程
//};
//int main()
//{
//	// 思考⼀下这⾥a对象中_name是"张三", "李四", "王五"中的哪⼀个？
//	Assistant a("张三", "李四", "王五");
//	return 0;
//}
// Tire(轮胎)和Car(⻋)更符合has-a的关系
class Tire {
protected:
	string _brand = "Michelin"; // 品牌
	size_t _size = 17; // 尺⼨
};
class Car {
protected:
	string _colour = "⽩⾊"; // 颜⾊
	string _num = "陕ABIT00"; // ⻋牌号
	Tire _t1; // 轮胎
	Tire _t2; // 轮胎
	Tire _t3; // 轮胎
	Tire _t4; // 轮胎
};
class BMW : public Car {
public:
	void Drive() { cout << "好开-操控" << endl; }
};
// Car和BMW/Benz更符合is-a的关系
class Benz : public Car {
public:
	void Drive() { cout << "好坐-舒适" << endl; }
};
template<class T>
class vector
{};
// stack和vector的关系，既符合is-a，也符合has-a
template<class T>
class stack : public vector<T>
{};
template<class T>
class stack
{
public:
	vector<T> _v;
};
int main()
{
	return 0;
}
