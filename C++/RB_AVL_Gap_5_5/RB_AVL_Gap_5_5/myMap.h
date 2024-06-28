#pragma once
#include"RBTree.h"
#include<string>
namespace zjl
{
	template<class K,class V>
	class MyMap
	{
	public:
		struct MapOfT
		{
			const K& operator()(const pair<K,V>& key)
			{
				return key.first;
			}
		};
		//typename：告诉编译器，最后再找这个名字
		typedef typename RBTree<K, pair<K,V>, MapOfT>::iterator iterator;


		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _t.insert(kv);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _t.insert(make_pair(key, V()));
			return ret.first->second;
		}

		//V& operator[](const K& key)
		//{
		//	// 使用 _t.find() 检查键是否存在
		//	iterator it = _t.find(key);

		//	// 如果找到，则返回对应的值
		//	if (it != _t.end())
		//		return it->second;

		//	// 如果没有找到，则插入新值并返回刚插入的值的引用
		//	else
		//	{
		//		pair<iterator, bool> ret = _t.insert(make_pair(key, V()));
		//		return ret.first->second;
		//	}
		//}

	private:
		RBTree<K,pair<K,V>, MapOfT> _t;
	};

	void testmap()
	{
		//m.insert(make_pair(4,4));
		//m.insert(make_pair(6,6));
		//m.insert(make_pair(1,1));
		//m.insert(make_pair(2,2));
		//m.insert(make_pair(9,9));
		//m.insert(make_pair(7,7));

		//MyMap<int, int>::iterator it = m.begin();
		//while (it != m.end())
		//{
		//	cout << it->first << ": " << it->second << endl;
		//	++it;
		//}
		//cout << endl;


		string str[] = { "aa","bb","cc","aa","bb" ,"cc","aa","bb" };
		MyMap<string, int> count;

		for (auto e : str)
		{
			count[e]++;
		}
		for (auto e : count)
		{
			cout << e.first << ": " << e.second << endl;
		}
		cout << endl;
	}
}