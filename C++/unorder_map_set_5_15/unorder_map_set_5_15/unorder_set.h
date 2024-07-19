#pragma once
#include"HashTable.h"

namespace zjl
{
	template<class K, class Hash = OPEN_HASH::_Hash<K> >
	class unorder_set
	{

		struct SetKOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};

	public:
		typedef typename OPEN_HASH::HashTable<K, K, SetKOfT, Hash>::iterator iterator;

		iterator begin()
		{
			return _ht.begin();
		}
		iterator end()
		{
			return _ht.end();
		}

		pair<iterator, bool> insert(const K& k)
		{
			return _ht.insert(k);
		}


	private:
		OPEN_HASH::HashTable<K, K, SetKOfT, Hash> _ht;
	};


	void testHash_set()
	{
		unorder_set<int> s;
		s.insert(3);
		s.insert(1);
		s.insert(5);
		s.insert(2);

		unorder_set<int>::iterator si = s.begin();
		while (si != s.end())
		{
			cout << *si << " ";
			++si;
		}
		cout << endl;
	}
}