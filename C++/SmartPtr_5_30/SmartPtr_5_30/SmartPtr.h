#pragma once
#include<mutex>

class HeapOnly
{
public:
	 static HeapOnly* GetObj()	//static可以突破类域访问
	{
		return new HeapOnly;
	}

private:
	HeapOnly()
	{}
};

//单列模式
class SingleTon
{
public:
	static SingleTon* Get()
	{
		//双重判断
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

	//懒汉模式 一开始（在main函数之前）就创建对象
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


