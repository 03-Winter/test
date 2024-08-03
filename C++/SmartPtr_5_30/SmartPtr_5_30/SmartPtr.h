#pragma once
#include<mutex>

class HeapOnly
{
public:
	 static HeapOnly* GetObj()	//static����ͻ���������
	{
		return new HeapOnly;
	}

private:
	HeapOnly()
	{}
};

//����ģʽ
class SingleTon
{
public:
	static SingleTon* Get()
	{
		//˫���ж�
		if (_plist == nullptr)
		{
			unique_lock<mutex> lock(_mtx);
			if (_plist == nullptr)
			{
				_plist = new SingleTon;
			}
			return _plist;
		}
	}

	static void Del()
	{
		unique_lock<mutex> lock(_mtx);
		delete _plist;
		_plist = nullptr;
	}

	SingleTon(const SingleTon& s) = delete;

private:
	SingleTon()
	{}
	static SingleTon* _plist;
	static mutex _mtx;
};

SingleTon* SingleTon::_plist = nullptr;

mutex SingleTon::_mtx;

namespace hungry_man
{

	//����ģʽ һ��ʼ����main����֮ǰ���ʹ�������
	class SingleTon
	{
	public:
		static SingleTon* Get()
		{
				return &_plist;
		}
		SingleTon(const SingleTon& s) = delete;

	private:
		SingleTon()
		{}
		static SingleTon _plist;
	};


}


