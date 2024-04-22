#pragma once


namespace zjl
{ 
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		iterator begin(){ return _start; }

		iterator end(){ return _finish; }

		const_iterator begin()const { return _start; }

		const_iterator end()const { return _finish; }

		vector()
			:_start(nullptr),_finish(nullptr),_endofstorage(nullptr)
		{}

		//传统写法
		//vector<T>& operator=(const vector<T>& v)
		//{
		//	if (this != &v)
		//	{
		//		delete[] _start;
		//		_start = new T[v.capecity()];
		//		memcpy(_start, v._start, sizeof(T) * v.size());
		//	}

		//	return *this;
		//}

		//简洁写法
		vector<T>& operator=(vector<T>& v)
		{
			Swap(v);
			return *this;
		}

		void Swap(vector<int>& v)
		{
			//：：的意义是：申明它的作用域是全局的
			::swap(_start, v._start);
			::swap(_finish, v._finish);
			::swap(_finish, v._finish);

		}
		//传统写法
		//vector(const vector<T>& v)
		//{
		//	_start = new T[v.capecity()];
		//	_finish = _start;
		//	_endofstorage = _start + v.capecity();

		//	for (size_t t=0;t<v.size();++t)
		//	{
		//		//*_finish = v._start[t];
		//		*_finish = v[t];
		//		++_finish;
		//	}
		//}


		//简洁写法
		vector(const vector<T>& v)
			:_start(nullptr),_finish(nullptr),_endofstorage(nullptr)
		{
			reserve(v.capecity());
			for (const auto& e : v)
			{
				push_back(e);
			}
		}

		//~vector()
		//{
		//	delete[] _start;
		//	_start = _finish = _endofstorage = nullptr;
		//}


		void reserve(size_t n)
		{
			if (n > capecity())
			{
				size_t sz = size();
				T* tem = new T[n];
				if (_start)
				{
					//按字节拷贝，属于浅拷贝
					memcpy(tem, _start, sizeof(T) * sz);

					//for (size_t t = 0; t < v.size(); ++t)
					//{
					//	tem[t] = v[t];				//调用的是T的operator=，属于深拷贝
					//}

					delete[] _start;
				}
				_start = tem;

				_finish = _start + sz;
				_endofstorage = _start + n;
			}
		}

		void push_back(const T& val)
		{
			//if (_endofstorage==_finish)
			//{
			//	size_t newcap =capecity() == 0 ? 2 : capecity() * 2;
			//	reserve(newcap);
			//}
			//*_finish = val;
			//_finish++;
			insert(_finish , val);
		}


		void pop_back()
		{
			assert(_finish);
			--_finish;
		}

		void insert(iterator pos,const T& val)
		{
			assert(pos <= _finish);
			if (_finish == _endofstorage)
			{
				size_t n = pos - _start;
				size_t newcap = capecity() == 0 ? 2 : capecity() * 2;
				reserve(newcap);
				pos = _start+n;
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = val;
			++_finish;
		}


		void resize(size_t n, const T& val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if ( n > capecity())
				{
					reserve( n);
				}

				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}

		iterator erase(iterator pos)
		{
			assert(pos<=_finish);
			iterator it = pos;
			while (it <= _finish)
			{
				*(it) = *(it + 1);
				++it;
			}
			--_finish;

			return pos;
		}


		T& operator[](size_t i)
		{
			return _start[i];
		}

		const T& operator[](size_t i) const 
		{
			return _start[i];
		}

		size_t size() const {
			return _finish - _start;;
		}
		size_t capecity() const {
			return _endofstorage - _start;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};

	void test_vector4()
	{
		vector<string> v1;
		//在使用memcpy时，它是按字节拷贝，属于浅拷贝，当析构时，程序崩溃
		v1.push_back("22222222222222222222222");
		v1.push_back("11111111111111111111111");
		//v1.push_back("33333333333333333333333");
		//1.push_back("44444444444444444444444");

		for (auto e : v1)
		{
			cout << e << " ";//打印结果：44444444444444444444444 葺葺葺葺葺葺葺葺葺葺葺?33333333333333333333333 44444444444444444444444
		}

		cout << endl;
	}


}