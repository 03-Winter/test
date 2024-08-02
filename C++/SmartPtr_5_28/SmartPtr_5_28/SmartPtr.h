#pragma once

#include<mutex>

template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{}
	~SmartPtr()
	{
		if (_ptr)
		{
			cout << "delete:" << _ptr << endl;
			delete _ptr;
			_ptr = nullptr;
		}
	}
	T* operator->()
	{
		return _ptr;
	}

	T& operator*()
	{
		return *_ptr;
	}
private:
	T* _ptr;
};


namespace zjl
{
	//����Ȩת�ƣ�ȱ�ݶ�

	//ȱ�ݣ�ap1=ap2�����£�Aap1���գ����ʱ���
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{}

		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap)
		{
			ap._ptr = nullptr;
		}

		auto_ptr<T>& operator=(const auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				if (_ptr)
					delete _ptr;
				_ptr = ap._ptr;
				ap._ptr = nullptr;
			}
			return *this;
		}


		~auto_ptr()
		{
			if (_ptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
				_ptr = nullptr;
			}
		}

		T* operator->()
		{
			return _ptr;
		}

		T& operator*()
		{
			return *_ptr;
		}

	private:
		T* _ptr;
	};

	//���ƣ�������
	//ȱ�ݣ����ܿ���
	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr)
			:_ptr(ptr)
		{}

		//����಻����������
		unique_ptr(unique_ptr<T>& up) = delete;
		unique_ptr<T>& operator=(unique_ptr<T>& up) = delete;

		~unique_ptr()
		{
			if (_ptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
				_ptr = nullptr;
			}
		}
		T* operator->()
		{
			return _ptr;
		}

		T& operator*()
		{
			return *_ptr;
		}
	private:
		T* _ptr;
	};

	//���ƣ����ü��������Կ���
	//ȱ�ݣ�ѭ������
	template<class T>
	class share_ptr
	{
	public:
		share_ptr(T* ptr)
			:_ptr(ptr)
			,_count(new int(1))
			,_mtx(new mutex)
		{}

		share_ptr(share_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _count(sp._count)
			,_mtx(sp._mtx)
		{
			add_count();
		}

		void add_count()
		{
			_mtx->lock();

			++(*_count);

			_mtx->unlock();
		}

		void release()
		{
			_mtx->lock();
			bool flag = false;
			if (--(*_count) == 0)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
				_ptr = nullptr;

				delete _count;
				_count = nullptr;

				flag = true;
			}

			_mtx->unlock();

			if (flag)
			{
				delete _mtx;
				_mtx = nullptr; 
			}
		}


		share_ptr<T>& operator=(const share_ptr<T>& sp)
		{
			if (this != &sp)
			{
				release();

				_ptr = sp._ptr;
				_count = sp._count;
				_mtx = sp._mtx;

				add_count();
			}
			return *this;
		}


		~share_ptr()
		{
			release();
		}

		int use_count()
		{
			return *_count;
		}
		T* operator->()
		{
			return _ptr;
		}

		T& operator*()
		{
			return *_ptr;
		}
	private:
		T* _ptr;
		int* _count;
		mutex* _mtx;//Ϊָ�룬��Ȼmutex�����������죬������ָ��ָ��ͬһ��mutex
	};
}
