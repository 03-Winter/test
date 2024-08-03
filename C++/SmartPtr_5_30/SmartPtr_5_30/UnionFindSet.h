#pragma once
#include<vector>
template<class T>

class UnionFindSet
{
public:
	UnionFindSet(int n)
	{
		_v.resize(n, -1);
	}

	int FindRoot(int x)
	{
		while (_v[x] >= 0)
		{
			x = _v[x];
		}
		return x;
	}
	bool Union(int x, int y)
	{
		int root1 = FindRoot(x);
		int root2 = FindRoot(y);
		if (root1 == root2)
		{
			return false;
		}
		_v[root1] += _v[root2];
		_v[root2] = root1;

		return true;
	}

private:
	vector<T> _v;
};
