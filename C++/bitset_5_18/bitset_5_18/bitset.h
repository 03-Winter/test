#pragma once

#include<vector>
namespace zjl
{
	class bitset
	{
	public:
		bitset(size_t N)
		{
			_bit.resize(N/32+1, 0);
			_num = 0;
		}
		void set(size_t x)
		{
			size_t index = x / 32;		//算出映射的位置在第几个整形
			size_t pos = x % 32;		//算出x在整形的第几位

			_bit[index] |= (1 << pos);		//第pos个位置置成1
		}

		void reset(size_t x)
		{
			size_t index = x / 32;		//算出映射的位置在第几个整形
			size_t pos = x % 32;		//算出x在整形的第几位

			_bit[index] &= ~(1 << pos);		//第pos个位置置成0
		}

		bool test(size_t x)
		{
			size_t index = x / 32;		//算出映射的位置在第几个整形
			size_t pos = x % 32;		//算出x在整形的第几位

			return _bit[index] & (1 << pos);		//第pos个位置置成1
		}
	private:
		std::vector<int> _bit;
		size_t _num;
	};

	void test_bitset()
	{
		bitset bs(100);
		bs.set(45);
		bs.set(99);
		bs.set(88);

		for (size_t i = 0; i < 100; ++i)
		{
			printf("[%d]:%d\n", i, bs.test(i));
		}
		cout << endl;

		//怎么设置最大值
		//bitset bs1(-1);
		//bitset bs2(pow());
		//bitset bitset(0xffffffff);
	}
}

