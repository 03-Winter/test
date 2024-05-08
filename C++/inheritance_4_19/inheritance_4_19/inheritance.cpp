#define _CRT_SECURE_NO_WARNINGS  1
#include<iostream>
using namespace std;
#include<string>

/// <summary>
/// 菱形继承：在继承中尽量避免
/// 缺点：出现数据的冗余性和二义性	
/// </summary>
//class person
//{
//public:
//	string _name;
//};
//
//class student :public person
//{
//protected: 
//	int stuid;
//};
//
//class teacher :public person
//{
//protected: 
//	int  jobid;
//};
//
//class assitance : public student, public teacher
//{
//protected:
//	string majorcourse;
//};
//
//int main()
//{
//	//二义性，不知道name谁的
//	assitance a;
//	//	a._name = "perter";
//
//	//需要申明作用域
//	a.student::_name = "asd";
//	a.teacher::_name = "dsa";
//
//
//	return 0;
//}


//多态的俩个条件
//1.虚函数的重写
//2.父类对象的指针或者引用去调用虚函数

//满足多态：跟调用的对象类型无关，跟指向的对象有关，指向哪个
//对象调用就是它的虚函数

//不满足多态：跟调用对象的类型有关，类型是什么调用的就是谁的虚函数


//class person
//{
//public:
//	virtual void Buyticket() { cout << "person::全票" << endl; }
//};
//
//class student:public person
//{
//public:
//	virtual void Buyticket() { cout << "student::半票" << endl; }
//};
//
////如果不是引用和指针，则不是多态
////void fenc(person* p)//指针要传地址
//void fenc(person& p)
//{
//	p.Buyticket();
//}
//
//int main()
//{
//	person p;
//	student s;
//	fenc(p);
//	fenc(s);
//
//	return 0;
//}

//class Base
//{
//public:
//	virtual void func1()
//	{
//		cout << "base::func1()" << endl;
//	}
//	virtual void func2()
//	{
//		cout << "base::func2()" << endl;
//	}
//protected:
//	int _b;
//};
//
//class derive :public Base
//{
//public:
//	virtual void func1()
//	{
//		cout << "base::func1()" << endl;
//	}
//protected:
//	int _d;
//};

//void test1()
//{
//	base b1;
//	derive d1;
//}
//
//void test2()
//{
//	base b2;
//	derive d2;
//}

//以上俩个测试，证明了类的同一对象，用同一虚表指针


//说明虚函数存在于代码段
//void get_address()
//{
//	Base b;
//	printf("vftptr::%p\n", *(int*)&b);
//
//	int i = 3;
//	int* p1 = &i;
//	int* p2 = new int;
//	const char* p3 = "polymorphic";
//	printf("栈变量：%p\n", p1);
//	printf("堆变量：%p\n", p2);
//	printf("数据段（常量段）变量：%p\n", p3);
//	printf("代码段函数地址量：%p\n", &Base::func2);
//}

class Base1
{
public:
	virtual void func1(){cout << "base1::func1()" << endl;}
	virtual void func2(){cout << "base1::func2()" << endl;}
protected:
	int _b1;
};
class Base2
{
public:
	virtual void func1(){cout << "base2::func1()" << endl;}
	virtual void func2(){cout << "base2::func2()" << endl;}
protected:
	int _b2;
};
class derive :public Base1,public Base2{
public:
	virtual void func1(){cout << "derive::func1()" << endl;}
	virtual void func3(){cout << "derive::func3()" << endl;}
protected:
	int _d;
};

//typedef void(*VF_PTR)();
//
//void printVFtable(VF_PTR* table)
//{
//	for (size_t i = 0; table[i] != 0; ++i)
//	{
//		printf("vtftable[%d]:%p->", i, table[i]);
//		VF_PTR f =table[i];
//		//将虚拟函数表（table）中索引为 i 的函数指针赋值给局部变量 f。
//		//类型 VF_PTR 是一个指向函数的指针类型，用于存储虚函数的地址。
//		f();
//		// 调用通过指针 f 引用的函数。由于 f 是从虚拟函数表中获取的，
//		//它实际上指向了当前对象应该调用的某个虚函数实现。
//	}
//	cout << endl;
//}
int main()
{
	//test1();
	//test2();
	//get_address();
	Base1 b1;
	Base2 b2;
	derive d1;

	//printVFtable((VF_PTR*)(*(int*)&b1));
	//printVFtable((VF_PTR*)(*(int*)&d1));
	return 0;
}