#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;

//������ģ��
//ע�⣺��������������ַ�����������Ϊ������ģ�����
//һ�������Σ�long/char/int/short
//template<class T,int N>
//class Aray
//{
//public:
//
//private:
//	T _a[N];
//};

//template<class T>
//bool isequal(T& x, T& y)
//{
//	return x == y;
//}
//
////ģ����ػ������� ���ĳ���������⻯����
//
//template<>
//bool isequal<char*>(char*& x, char*& y)
//{
//	return strcmp(x, y) == 0;
//}
//
template<class T1, class T2>
class Data
{
public:
	//Date() {
	//	cout << "ԭģ��" << endl;
	//}
private:
	T1 _a;
	T2 _b;
};
//ȫ�ػ���ƫ�ػ�
template<>
class Data<int, char>
{
public: 
	Data() { cout << "ȫ�ػ�" << endl; }
private:

};

template<class T2>
class Data<int,T2>
{
public: 
	Data() { cout << "ƫ�ػ�" << endl; }
private:

};

template<class T1,class T2>
class Data<T1*,T2*>//�����ģ��������ܺ�����һ��
{
public: 
	Data() { cout << "ƫ�ػ�" << endl; }
private:

};

template<class T1,class T2>
class Data<T1&,T2&>//�����ģ��������ܺ�����һ��
{
public: 
	Data() { cout << "ƫ�ػ�" << endl; }
private:

};



int main()
{
	Data<int, char> a1;
	Data<int, int> a2;
	Data<int, double> a3;
	//Data<char, char> a4;
	Data<int*, char*> a5;
	Data<int&, char&> a6;
	//int a = 3, b = 3;
	//cout << isequal(a, b) << endl;

	//const char* c = "hello";
	//const char* d = "windows";
	//cout << isequal(c, d);
	//Aray<int, 10> a1;
	//Aray<int, 1000> a2;
	return 0;
}