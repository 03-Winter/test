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

//�̳и���person�Ķ����������һ����
class student :public Person
{
public:
	void f()
	{
		//���е�˽�кͱ���������û�в��
		//�������У�private��Ա���ɼ�
		//cout << _age << endl;

		cout << _name << endl;
		cout << _age << endl;
	}
protected:
	//int _stuid;

	//�������Ա�͸�����ͬ����Աʱ�������ظ����Ա���ض��壩
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


//���������student�࣬��Ԫ�������Ҳ����ģ��ᱨ��
//class student;
//class Person
//{
//public:
//	//��Ԫ�������ܱ��̳У���Ҫʹ�þ�������Ԫ����
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

	//~student()			//����������ʱ�򣬸�������������ᱻ���أ���Ϊ���Ƕ��ᱻ����������Ϊdestructtor
	//{
	//	//Ӧ�ò��û�����������
	//	//Person::~Person();
	//	cout << "~student" << endl;
	//}
	//��Ϊ�������ʱ���Զ��������������������Ϳ������������࣬����������
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

	////����������ֵ����Ĭ��ʹ��s4��s2�����캯��
	////student s4=s2;

	//student s4("jack", 12);
	// s4 = s2;

	//Person p;
	//student s;
	//displayer(p, s);



	//v v1;
	//v1.print();
	////��Ҫʹ��a������ĵ�printʱ����Ҫ��������
	//v1.a::print();
	//Person p;
	//student s;

	//s.f();

	//���������Ը�ֵ���������/ָ��/����
	//p = s;
	//Person* ptr = &s;
	//Person& ref = s;

	//���Ǹ��������ȴ����

//	return 0;
//}


//���ඨ����static��̬��Ա���������̳���ϵ��ֻ��һ��ֻ�еĳ�Ա


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
	cout << person::_num << endl;		//�����3
	cout << student::_num << endl;			//�����3

	return 0;
}