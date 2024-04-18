#define _CRT_SECURE_NO_WARNINGS  1
#include <iostream>
#include<assert.h>
#include<string>
using namespace std;


//cpp�����˳���
//template<class T>
//class vector
//{
//public:
//	vector()
//		:_a(nullptr),_size(0),_capecity(0)
//	{}
//	~vector()
//	{
//		delete[] _a;
//		_a = nullptr;
//		_size = _capecity = 0;
//	}
//
//	//�����涨��
//	void push_back(const T& x);
//	void push_pop();
//
//	size_t size()
//	{
//		return _size;
//	}
//	T& operator[](size_t i)		//�������ÿ��Խ����ʱ��������
//	{
//		assert(i < _size);
//		return _a[i];//��ʱ������г���
//	}
//
//private:
//	T* _a;
//	size_t _size;
//	size_t _capecity;
//};
//
////����������
//template<class T>
//void vector<T>::push_back(const T& x) {
//	if (_size == _capecity)
//	{
//		size_t newcapecity = _capecity == 0 ? 2 : _capecity * 2;
//		T* tem = new T[newcapecity];
//		if (_a)
//		{
//			memcpy(tem, _a, sizeof(T) * _size);
//			delete _a;
//		}
//		_a = tem;
//		_capecity = newcapecity;
//	}
//	_a[_size++] = x;
//}
//template<class T>
//
//void vector<T>::push_pop()
//{
//	assert(_size>0);
//	//free(_a[_size]);
//	_size--;
//	
//}
//
//int main() {
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	//д
//	for (size_t i = 0; i < v.size(); ++i)
//	{
//		cout << v[i] << " ";
//	}
//	cout << endl;
//	//��
//	for (size_t i = 0; i < v.size(); ++i)
//	{
//		//����ֵ���г��ԣ����ɸ�
//		v[i] *= 2;
//	}
//	cout << endl;
//
//	return 0;
//
//}






//int main()
//{
//	//string s1;
//	//string s2("hello");
//	//string s3(s2);
//	//string s4(10,'a');
//	//string s5="hello";
//	//string s6=s5;
//
//	//cout << s1 << endl;
//	//cout << s2 << endl;
//	//cout << s3 << endl;
//	//cout << s4 << endl;
//	//cout << s5 << endl;
//	//cout << s6 << endl;
//
//
//	//string s1("12335");
//	//s1.push_back('4');
//	//s1.append("678");
//	//s1 += "90";
//
//	//cout << s1 << endl;
//
//
//	//���ַ���ת��������
//
//	string s1 = "23456";
//	int val = 0;
//	for (size_t i = 0; i < s1.size(); ++i)
//	{
//		val *= 10;
//		val += (s1[i] - '0');
//	}
//	cout << val << endl;
//
//	return 0;
//}

void TestString1()
{
	string s1("hello");
	//��ͨ��
	for (size_t i = 0; i < s1.size(); ++i)
	{
		cout << s1[i] << " ";
	}
	cout << endl;
	for (size_t i = 0; i < s1.size(); ++i)
	{
		s1[i] += 1;
		cout << s1[i] << " ";

	}
	cout << endl;

	//��������
	string::iterator it = s1.begin();
	while (it != s1.end())
	{
		*it -= 1;
		++it;
	}
	it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;


	//��Χfor

	for (auto e : s1)
	{
		cout << e << " ";
	}
	cout << endl;
}
int stringint(const string& str)
{
	int val = 0;

	//�����޸İ������
	//string::const_iterator cit = str.begin();
	//while (cit != str.end())
	//{
	//	val *= 10;
	//	val += (*cit - '0');
	//	++cit;
	//}
	//cout << endl;
	//int val = 0;

	//�����޸����ð������
	string::const_reverse_iterator crit = str.rbegin();
	while (crit != str.rend())
	{
		val *= 10;
		val += (*crit - '0');
		++crit;
	}
	cout << endl;
	return val;
}

void TestString2()
{
	string s1("Fantastic");

	//���ñ���
	string::reverse_iterator rit = s1.rbegin();
	while (rit != s1.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;


}

void TestString3()
{
	string s1("meaningful");
	string s2("wonderful");
	//cout << s1.size() << endl;
	//cout << s2.size() << endl;
	//cout << s1.length() << endl;
	//cout << s2.length() << endl;
	//cout << s1.max_size() << endl;
	//cout << s2.max_size() << endl;
	//cout << s1.capacity() << endl;
	//cout << s2.capacity() << endl;
	s1.clear();
	cout << s1 << endl;
	s1.resize(10);//���ÿռ��С
	s2.resize(20, 'a');//�ռ����е�ֵ���䣬����ֵ��Ϊ��a��
}

//int main()
//{
//	//TestString1();
//	//TestString2();
//	TestString3();
//
//	return 0;
//}