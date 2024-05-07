#define _CRT_SECURE_NO_WARNINGS  1
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	void print()
	{
		cout << _name << endl;
		cout << _age << endl;
	}
protected:
	string _name = "peter";
	int _age = 23;
};

//继承父类person的都会变成子类的一部分
class student :public Person
{
public:
	void f()
	{
		//类中的私有和保护在类中没有差别
		//在子类中，private成员不可见
		//cout << _age << endl;

		cout << _name << endl;
		cout << _age << endl;
	}
protected:
	//int _stuid;

	//当子类成员和父类有同名成员时，会隐藏父类成员（重定义）
	int _age = 19;
};	

class teacher :public Person
{
protected:
	int _jobid;
};

class a
{
public:
	void print()
	{
		cout << "print()" << endl;
	}

protected:

};

class v :public a
{
public:
	void print(int i)
	{
		cout << "print(int i )" << endl;
	}
};


//如果不申明student类，友元函数是找不到的，会报错
//class student;
//class Person
//{
//public:
//	//友元函数不能被继承，若要使用就申明友元函数
//	friend void displayer(const Person& p, const student& s);
	//	
	//Person(const char* name = "peter")
	//	:_name(name)
	//{
	//	cout << "Person()" << endl;
	//}

	//Person(const Person& p)
	//	:_name(p._name)
	//{
	//	cout << "Person(const Person& p)" << endl;
	//}

	//Person& operator=(const Person& p)
	//{
	//	cout << "Person& operator=(const Person& p)" << endl;
	//	if (this != &p)
	//		_name = p._name;
	//	return *this;
	//}

	//~Person()
	//{
	//	cout << "~person()" << endl;
	//}
//protected:
//	string _name="peter";
//};
//
//class student :public Person
//{
//public:
//	friend void displayer(const Person& p, const student& s);
//
//	//student()
	//{}

	//student(const char* name, int stuid)
	//	:Person(name)
	//	,_stuid(stuid)
	//{
	//	cout << "student()" << endl;
	//}

	//student(const student& s)
	//	:Person(s)
	//	,_stuid(s._stuid)
	//{
	//	cout << "student(const student& s)" << endl;
	//}

	//student& operator=(const student& s)
	//{
	//	if (this != &s)
	//	{
	//		Person::operator=(s);
	//		_stuid = s._stuid;
	//		cout << "student& operator=(const student& s)" << endl;

	//	}

	//	return *this;
	//}

	//~student()			//子类析构的时候，父类的析构函数会被隐藏，因为他们都会被解释器翻译为destructtor
	//{
	//	//应该不用基类析构函数
	//	//Person::~Person();
	//	cout << "~student" << endl;
	//}
	//因为程序结束时会自动调用析构函数，这样就可以先析构子类，后析构父类
//protected:
//	int _stuid=12345; 
//};
//
//
//void displayer(const Person& p, const student& s)
//{
//	cout << p._name << endl;
//	cout << s._stuid << endl;
//
//}
//int main()
//{
	//student s2("matial",45);
	//student s3(s2);

	////不能这样赋值，会默认使用s4（s2）构造函数
	////student s4=s2;

	//student s4("jack", 12);
	// s4 = s2;

	//Person p;
	//student s;
	//displayer(p, s);



	//v v1;
	//v1.print();
	////当要使用a类里面的的print时，就要申明类域
	//v1.a::print();
	//Person p;
	//student s;

	//s.f();

	//子类对象可以赋值给父类对象/指针/引用
	//p = s;
	//Person* ptr = &s;
	//Person& ref = s;

	//但是父类给子类却不行

//	return 0;
//}


//基类定义了static静态成员，则整个继承体系里只有一个只有的成员


class person
{
public:
	person() { ++_num; }

//protected:
	string _name;
	static int _num;
};

int person::_num = 0;
class student :public person
{
protected:
	int _stuid;
};


int main()
{
	person p;
	student s;

	p._num = 1;
	s._num = 2;

	person::_num++;
	cout << person::_num << endl;		//结果：3
	cout << student::_num << endl;			//结果：3

	return 0;
}