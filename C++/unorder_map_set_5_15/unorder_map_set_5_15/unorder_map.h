#pragma once
#include"HashTable.h"

namespace zjl
{
	template<class K,class V, class Hash = OPEN_HASH::_Hash<K>>
	class unorder_map
	{
		struct MapKOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename OPEN_HASH::HashTable<K, pair<K, V>, MapKOfT, Hash>::iterator iterator;
		iterator begin()
		{
			return _ht.begin();
		}
		iterator end()
		{
			return _ht.end();
		}
		pair<iterator, bool> insert(const pair<K,V>& kv)
		{
			return _ht.insert(kv);
		}
		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _ht.insert(make_pair(key, V()));
			return ret.first->second;
		}
	private:
		OPEN_HASH::HashTable<K, pair<K, V>, MapKOfT,Hash> _ht;
	};

	void testHash_map()
	{
		unorder_map<string,string> m;
		m.insert(make_pair("zifc", "字符串"));
		m.insert(make_pair("c", "C语言"));
		m.insert(make_pair("Java", "基于平台"));
		m.insert(make_pair("python", "智能化"));
		m["c"] = "cao";
		unorder_map<string,string>::iterator si = m.begin();
		while (si != m.end())
		{
			cout << si->first << " " << si->second << endl;
			++si;
		}
		cout << endl;
	}


}