#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include"AVLTree.h"
#include"RBTree.h"
#include"Myset.h"
#include"myMap.h"
using namespace std;

#include<vector>
#include<time.h>

//void testRB_AVLtree()
//{
//	const int n = 10000000;
//	vector<int> v;
//	v.reserve(n);
//	srand(time(0));
//	for (size_t i = 0; i < n; ++i)
//	{
//		v.push_back(rand());
//	}
//	RBTree<int, int> r;
//	AVLTree<int, int> a;
//
//	size_t begin1 = clock();
//	for (auto e : v)
//	{
//		r.insert(make_pair(e, e));
//	}
//	size_t end1 = clock();
//
//	size_t begin2 = clock();
//	for (auto e : v)
//	{
//		a.insert(make_pair(e, e));
//	}
//	size_t end2 = clock();
//
//	cout << "r : " << end1 - begin1 << endl;
//	cout << "a : " << end2 - begin2 << endl;
//}


int main()
{
	//testRB_AVLtree();
	zjl::testmap();
	zjl::testset();
	return 0;
}

