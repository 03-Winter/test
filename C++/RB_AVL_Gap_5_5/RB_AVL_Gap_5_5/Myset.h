#pragma once

#include"RBTree.h"

namespace zjl
{
	template<class K>
	class MySet
	{

	public:
		struct SetOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
		//typename：告诉编译器，最后再找这个名字
		typedef typename RBTree<K, K, SetOfT>::iterator iteratorset;


		iteratorset begin()
		{
			return _t.begin();
		}

		iteratorset end()
		{
			return _t.end();
		}

		pair<iteratorset, bool> insert(const K& k)
		{
			return _t.insert(k);
		}

	private:
		RBTree<K, K, SetOfT> _t;
	};


	void testset()
	{
		MySet<int> s;
		s.insert(4);
		s.insert(6);
		s.insert(3);
		s.insert(1);

		MySet<int>::iteratorset it = s.begin();
		while (it != s.end())
		{
			cout << *it << " " << endl;
			++it;
		}
		cout << endl;

	}
}