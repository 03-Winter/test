#define _CRT_SECURE_NO_WARNINGS  1
#include<string>
#include<iostream>
using namespace std;

class Exception
{
public:
	Exception(const int& errid,const string& errmsg)
		:_errid(errid)
		,_errmsg(errmsg)
	{}
	virtual string what() = 0;

protected:
	int _errid;
	string _errmsg;

};

class sqlException :public Exception
{
public:
	sqlException(const int& errid, const string& errmsg)
		:Exception(errid,errmsg)
	{}
	virtual string what()
	{
		return "数据库错误:" + _errmsg;
	}
};


class networkException : public Exception
{
public:
	networkException(const int& errid, const string& errmsg)
		:Exception(errid, errmsg)
	{}
	virtual string what()
	{
		return "网络错误:" + _errmsg;
	}
};


void SeverStart()
{
	if (rand() % 3 == 0)
		throw sqlException(1, "数据库启动失败");
	if (rand() % 7 == 0)
		throw networkException(3, "网络连接失败");

	cout << "正常运行" << endl;
}


int main()
{
	for (size_t i = 0; i < 10; i++)
	{
		try
		{
			SeverStart();
		}
		catch (Exception& e)
		{
			cout << e.what() << endl;
		}
		catch (...)
		{
			cout << "未知异常" << endl;
		}
	}

	return 0;
}