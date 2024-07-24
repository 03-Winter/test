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
			size_t index = x / 32;		//���ӳ���λ���ڵڼ�������
			size_t pos = x % 32;		//���x�����εĵڼ�λ

			_bit[index] |= (1 << pos);		//��pos��λ���ó�1
		}

		void reset(size_t x)
		{
			size_t index = x / 32;		//���ӳ���λ���ڵڼ�������
			size_t pos = x % 32;		//���x�����εĵڼ�λ

			_bit[index] &= ~(1 << pos);		//��pos��λ���ó�0
		}

		bool test(size_t x)
		{
			size_t index = x / 32;		//���ӳ���λ���ڵڼ�������
			size_t pos = x % 32;		//���x�����εĵڼ�λ

			return _bit[index] & (1 << pos);		//��pos��λ���ó�1
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

		//��ô�������ֵ
		//bitset bs1(-1);
		//bitset bs2(pow());
		//bitset bitset(0xffffffff);
	}
}

