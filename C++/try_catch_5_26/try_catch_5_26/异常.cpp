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
		return "���ݿ����:" + _errmsg;
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
		return "�������:" + _errmsg;
	}
};


void SeverStart()
{
	if (rand() % 3 == 0)
		throw sqlException(1, "���ݿ�����ʧ��");
	if (rand() % 7 == 0)
		throw networkException(3, "��������ʧ��");

	cout << "��������" << endl;
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
			cout << "δ֪�쳣" << endl;
		}
	}

	return 0;
}