#pragma once

#include"bitset.h"
#include<string>
namespace zjl
{
	struct Hashstr1
	{
		size_t operator()(const std::string& str)
		{
			//BKDR算法
			size_t hash = 0;
			for (size_t i = 0; i < str.size(); i++)
			{
				hash *= 131;
				hash += str[i];
			}
			return hash;
		}
	};

	struct Hashstr2
	{
		size_t operator()(const std::string& str)
		{
			//SDBM算法
			size_t hash = 0;
			for (size_t i = 0; i < str.size(); i++)
			{
				hash *= 65599;
				hash += str[i];
			}
			return hash;
		}
	};

	struct Hashstr3
	{
		size_t operator()(const std::string& str)
		{
			//RSH算法
			size_t hash = 0;
			size_t magic = 63689;
			for (size_t i = 0; i < str.size(); i++)
			{
				hash *= magic;
				hash += str[i];
				hash *= 378551;
			}
			return hash;
		}
	};


	template<class K,
		class Hash1=Hashstr1,
		class Hash2=Hashstr2,
		class Hash3=Hashstr3>
	class BloomFliter
	{
	public:
		BloomFliter(size_t num)
			:_bs(5*num),
			_N(5*num)
		{}
		void set(const K& key)
		{
			size_t index1 = Hash1()(key) % _N;
			size_t index2 = Hash2()(key) % _N;
			size_t index3 = Hash3()(key) % _N;

			_bs.set(index1);
			_bs.set(index2);
			_bs.set(index3);

		}
		bool test(const K& key)
		{
			size_t index1 = Hash1()(key) % _N;
			if (_bs.test(index1) == false)
				return false;

			size_t index2 = Hash2()(key) % _N;
			if (_bs.test(index2) == false)
				return false;

			size_t index3 = Hash3()(key) % _N;
			if (_bs.test(index3) == false)
				return false;

			return true;
		}

		//不支持删除

	private:
		bitset _bs;
		size_t _N;
	};


	void test_bloomfilter()
	{
		BloomFliter<std::string> bf(100);
		bf.set("abcd");
		bf.set("dcba");
		bf.set("abdc");

		cout << bf.test("abcd") << endl;
		cout << bf.test("dcba") << endl;
		cout << bf.test("abdc") << endl;
	}
}
