#define _CRT_SECURE_NO_WARNINGS  1
#include<iostream>
using namespace std;
#include<string>

/// <summary>
/// ���μ̳У��ڼ̳��о�������
/// ȱ�㣺�������ݵ������ԺͶ�����	
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
//	//�����ԣ���֪��name˭��
//	assitance a;
//	//	a._name = "perter";
//
//	//��Ҫ����������
//	a.student::_name = "asd";
//	a.teacher::_name = "dsa";
//
//
//	return 0;
//}


//��̬����������
//1.�麯������д
//2.��������ָ���������ȥ�����麯��

//�����̬�������õĶ��������޹أ���ָ��Ķ����йأ�ָ���ĸ�
//������þ��������麯��

//�������̬�������ö���������йأ�������ʲô���õľ���˭���麯��


//class person
//{
//public:
//	virtual void Buyticket() { cout << "person::ȫƱ" << endl; }
//};
//
//class student:public person
//{
//public:
//	virtual void Buyticket() { cout << "student::��Ʊ" << endl; }
//};
//
////����������ú�ָ�룬���Ƕ�̬
////void fenc(person* p)//ָ��Ҫ����ַ
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

//�����������ԣ�֤�������ͬһ������ͬһ���ָ��


//˵���麯�������ڴ����
//void get_address()
//{
//	Base b;
//	printf("vftptr::%p\n", *(int*)&b);
//
//	int i = 3;
//	int* p1 = &i;
//	int* p2 = new int;
//	const char* p3 = "polymorphic";
//	printf("ջ������%p\n", p1);
//	printf("�ѱ�����%p\n", p2);
//	printf("���ݶΣ������Σ�������%p\n", p3);
//	printf("����κ�����ַ����%p\n", &Base::func2);
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
//		//�����⺯����table��������Ϊ i �ĺ���ָ�븳ֵ���ֲ����� f��
//		//���� VF_PTR ��һ��ָ������ָ�����ͣ����ڴ洢�麯���ĵ�ַ��
//		f();
//		// ����ͨ��ָ�� f ���õĺ��������� f �Ǵ����⺯�����л�ȡ�ģ�
//		//��ʵ����ָ���˵�ǰ����Ӧ�õ��õ�ĳ���麯��ʵ�֡�
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