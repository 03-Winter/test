#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;
//��ʼ����Ա����������Ҫ����
// 1.���ó�Ա����
// 2.const�ĳ�Ա����
// 3.�Զ������ͣ�û��Ĭ�ϵĹ��캯����
//
//class Se
//{
//public:
//	//Se(int a)
//	//	:_a(10)
//	//{
//
//	//}
//	//Se(int a=9)
//	//{
//
//	//}
//	Se()
//	{
//		n++;
//	}
//	Se(const Se& d)
//	{
//		++n;
//	}
//
//	static int GetN()//û��thisָ�룬���ܷ��ʷǾ�̬��Ա
//	{ return n; }
//private:
//	int _a;
//	static int n;//���� 
//	//��������ĳ������
//	//��������������ж������������
//
//};
//
//int Se::n = 0;

//class Fi
//{
//public:
//	Fi(int s, int abs, const int bs)
//		:_s(10), a(abs), b(bs)
//	{
//
//	}
//
//private:
//	Se _s;
//	int& a;
//	const int b;
//};

//int main()
//{
//	Se s1;
//	Se s2;
//	//ͻ����������ַ�ʽ
//	cout << s1.GetN() << endl;
//	cout << Se::GetN() << endl;
//	return 0;
//}

class Data
{
	//��Ԫ����
	//friend void f(Data& d);
	friend ostream& operator<<(ostream& out, const Data& d);
	friend istream& operator>>(istream& in, Data& d);
		
public:
	void print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	//�������Ϊʲô���У�
	//���ݴ��ο�֪��cout�ᴫ��thisָ�룬��d1�ش���out��˳������
	// ��������ʹ����Ԫ����
	// 
	//void operator<<(ostream& out);

private:
	int _year;
	int _month;
	int _day;
};


ostream& operator<<(ostream& out, const Data& d)
{
	out << d._year << "-" << d._month << "-" << d._day << endl;
	return out;
}


istream& operator>>(istream& in, Data& d)
{
	in >> d._year >> d._month >> d._day ;
	return in;
}
//���ⲿ������Ҫʹ�� ���Ա�������Ϳ���ʹ����Ԫ����
//void f(Data& d)
//{
//	d._year = 9;
//
//	cout << d._year << endl;
//
//}

int main()
{
	Data d1;
	Data d2;

	cin >> d1 >> d2;
	//����Ҫʹ������d1��Ҫ�������������
	cout << d1 << d2;
	return 0;
}
