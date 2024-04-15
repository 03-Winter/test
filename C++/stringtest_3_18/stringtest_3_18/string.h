#pragma once
#include<assert.h>
namespace zjl
{
	class string
	{
	public:

		typedef char* interator;
		interator begin()
		{
			return _str;
		}

		interator end()
		{
			return _str + _size; 
		}


		string()
			:_str(new char[1])
		{
			_str[0] = '\0';
		}
		//���Լ�const����
		//string(const char* str) 
		//	:_str(new char[strlen(str)+1])
		//{
		//	strcpy(_str, str);

		//}
		// 
		///��Ա��ʼ��
		string(const char* str = "")
		{
			_size = strlen(str);
			_capecity = _size;
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}

		//���������
		string(const string& s)
			:_str(new char[strlen(s._str)+1])
		{
			strcpy(_str, s._str);
		}


		//ʵ��һ��=�����������

		string& operator=(const string& s)
		{
			if (this != &s)
			{
				char* tem = new char[strlen(s._str) + 1];
				strcpy(tem, s._str);
				delete[] _str;
				_str = tem;
			}
			return *this;
		}

		~string()
		{
			_size = _capecity = 0;
			delete[] _str;
			_str = nullptr;
		}

		//�����ַ�����
		const char* c_str() const
		{
			return _str;
		}

		size_t size()
		{
			return strlen(_str);
		}

		size_t capecity()
		{
			return _capecity;
		}
		//[]�����������
		char& operator[](size_t i)
		{
			assert(i < _size);
			return _str[i];
		}
		//const����
		const char& operator[](size_t i) const 
		{
			assert(i < _size);
			return _str[i];
		}

		const char* c_str()
		{
			return _str;
		}

		void reverse(size_t n)
		{
			if (n > _capecity)
			{
				char* tem = new char[n + 1];
				strcpy(tem, _str);
				delete[] _str;
				_str = tem;
				_capecity = n;
			}
		}

		void resize(size_t n, char ch='\0')
		{
			if (n < _size)
			{
				_str[n] = '\0';
				_size = n;
			}
			else
			{
				if (n > _capecity)	reverse(n);

				for (size_t i = _size; i < n; ++i)
				{
					_str[i] = ch;
				}
				_size = n;
				_str[_size] = '\0';
			}
		}

		//�����ַ�
		void push_back(char ch)
		{
			if (_size == _capecity)
			{
				size_t _newcapecity = _capecity == 0 ? 4 : _capecity * 2;
				reverse(_newcapecity);
			}
			_str[_size++] = ch;

			//Ҫ�㣺��ӡ�\0���Ľ�����
			_str[_size] = '\0';
		}


		//����ַ���
		void append(const char* ch)
		{
			size_t len = strlen(ch);
			if (_size +len > _capecity)
			{
				//size_t _newcapecity = _size + len;
				reverse(_size+len);
			}
			//���ַ��������
			strcpy(_str+_size, ch);
			_size += len;

			//Ҫ�㣺��ӡ�\0���Ľ�����
			_str[_size] = '\0';
		}

		string& operator+=(const char ch)
		{
			this->push_back(ch);
			return *this;
		}


		string& operator+=(const char* str)
		{
			this->append(str);
			return *this;
		}

		string& insert(size_t pos, char ch)
		{
			assert(pos < _size);
			if (_size == _capecity)
			{
				size_t newstr = _capecity == 0 ? 4 : _capecity * 2;
				reverse(newstr);
			}
			int end = _size;
			while (end >= pos)
			{
				_str[end + 1] = _str[end];
				--end;
			}
			_str[pos] = ch;
			++_size;

			return *this;
			//_str[_size] = '\0';
		}
		string& insert(size_t pos, const char* str)
		{
			assert(pos < _size);
			size_t len = strlen(str);
			if (_size +len> _capecity)
			{
				reverse(_size + len);
			}
			int end = _size;
			while(end >= pos)
			{
				_str[end + len] = _str[end];
				--end;
			}

			//Ϊʲô����strcpy����Ϊ����ѡ�/0��Ҳ����ȥ
			strncpy(_str + pos, str, len);//strncpy����ѡ�񿽱�����
			_size += len;

			return *this;
		}

		void erase(size_t pos,size_t len=nops) 
		{
			assert(pos < _size);
			if (len>=_size-pos)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				size_t i = pos + len;
				while (i <= _size)
				{
					_str[i - len] = _str[i];
					//_str[pos++] = _str[i++];
					++i;
				}
				_size -= len;
			}
		}
		size_t find(char ch, size_t pos=0)
		{
			while (pos <= _size)
			{
				if (_str[pos] == _str[ch])
				{
					return pos;
				}
				++pos;
			}
			return nops;
		}

		size_t find(const char* str, size_t pos=0)
		{
			char* p = strstr(_str, str);
			if (p== nullptr)
			{
				return nops;
			}
			else return p - _str;
		}

		bool operator<(const string& s)
		{
			 int ret = strcmp(_str, s._str);
			return ret < 0;
		}
		bool operator==(const string& s)
		{
			int ret = strcmp(_str, s._str);
			return ret == 0;
		}
		bool operator<=(const string& s)
		{
			return *this < s || *this == s;
		}
		bool operator>(const string& s)
		{
			return !(*this <= s);
		}
		bool operator>=(const string& s)
		{
			return !(*this < s);
		}
		bool operator!=(const string& s)
		{
			return !(*this == s);
		}



	private:
		char* _str;
		size_t _size;
		size_t _capecity;

		static size_t nops;
	};

	size_t string::nops = -1;

	istream& operator>>(istream& in, string& s)
	{
		while (1)
		{
			char ch;
			ch = in.get();
			//getline����ֻ�����˿ո���ж�
	/*		if ( ch == '\n')
			{
				break;
			}*/
			//get()������ԭ��
			if (ch == ' ' || ch == '\n')
			{
				break;
			}
			else
			{
				s += ch;
			}
		}
		return in;
	}

	ostream& operator<<(ostream& out, string& s)
	{
		for (size_t i = 0; i < s.size(); ++i)
		{
			cout << s[i];
		}
		cout << endl;
		return out;
	}
	void test_string3()
	{
		string w1("asdf");
		cin >> w1;
		//w1.insert(1, 'n');
		//w1.insert(3, "hahha");
		cout << w1 << endl;
		//cout << w1.size() << endl;
		//cout << w1.capecity() << endl;

		//w1.resize(11,'p');
		//cout << w1 << endl;
		//cout << w1.size() << endl;
		//cout << w1.capecity() << endl;

		//w1.resize(18,'k');
		//cout << w1 << endl;
		//cout << w1.size() << endl;
		//cout << w1.capecity() << endl;
		//cout << w1 << endl;
		//size_t r = w1.find('n',0);
		//cout << r;

		//size_t re = w1.find("hah",0);
		//cout << re;
		//w1.erase(2, 2);
		//cout << w1 << endl;
		//for (auto e : w1)
		//{
		//	cout << e;
		//}
		//cout << endl;
	}
}