#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;
#include<string>

namespace St
{
	//完成析构+构造+[]+拷贝
	class easy_string
	{
	public:
		//s1("sdda")
		easy_string(const char* str)
			:_str(new char[strlen(str) + 1])
		{
			strcpy(_str, str);
		}
		//s1(s2)
		//传统写法
		//easy_string(const easy_string& s)
		//	:_str(new char[strlen(s._str)+1])
		//{
		//	strcpy(_str, s._str);
		//}

		//现代写法
		easy_string(const easy_string& s)
			:_str(nullptr)
			,_size(0),_capecity(0)
		{
			easy_string tem(s);
			this->swap(tem);
		/*	if (this != &s)
			{
				easy_string tem(s._str);
				swap(_str, tem._str);
			}*/
			//return *this;
		}
		void swap(easy_string& s)
		{
			//::符号的意义：调用全局域的swap函数
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capecity, s._capecity);
		}
		bool operator==(const easy_string& s)
		{
			size_t ret = strcmp(_str, s._str);
			return ret < 0;
		}
		bool operator!=(const easy_string& s)
		{
			return !(*this == s);
		}
		//s1=s2

		//传统写法
		
		//easy_string& operator=(const easy_string& s)
		//{
		//	if(this!=&s)//方法一：
		//	if (*this != s)//方法二
		//	{
		//		char* tem = new char[strlen(s._str) + 1];
		//		strcpy(tem, s._str);
		//		delete[] _str;
		//		_str = tem;
		//	}
		//	return *this;
		//}
			
		//现代写法
		easy_string& operator=(easy_string& s)
		{
			this->swap(s);
			//swap(_str, s._str);
			return *this;
		}
		//[]的重载
		char& operator[](size_t i)
		{
			return _str[i];
		}
		size_t size() 
		{
			return strlen(_str);
		}

		~easy_string()
		{
			delete[] _str;
			_str = nullptr;
		}

	private:
		char* _str;
		size_t _size;
		size_t _capecity;
	};
}

int main()
{
	St::easy_string s1("hell0");
	St::easy_string s2(s1);
	for (size_t i=0;i<s2.size();++i)
	{
		cout << s2[i];
	}
	cout << endl;
	St::easy_string s3("world");
	s1 = s3;
	for (size_t i = 0; i < s1.size(); ++i)
	{
		cout << s1[i];
	}
	cout << endl;
	return 0;
}