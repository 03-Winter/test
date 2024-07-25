#pragma once

struct Goods
{
	string _name;
	double _price;
};

struct Compare {
	bool operator()(const Goods& g1, const Goods& g2)
	{
		return g1._price > g2._price;
	}
};