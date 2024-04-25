
namespace zjl
{
	template<class T>
	//"__"开头是作为内部使用
	//将链表封装起来，方便使用
	struct __list_node
	{
		__list_node<T>* prev;
		__list_node<T>* next;
		T data;

		__list_node(const T& x=T())
			:data(x)
			,prev(nullptr)
			,next(nullptr)
		{}

	};

	template<class T, class Ref, class Ptr>
	struct __list_iterator
	{
		typedef  __list_node<T> Node;
		typedef  __list_iterator<T, Ref, Ptr> self;
		Node* _node;

		__list_iterator(Node* node)
			:_node(node)
		{}

		Ptr operator*()
		{
			return _node->data;
		}

		Ref operator->()
		{
			return &_node->data;
		}
		//++i
		self& operator++()
		{
			_node = _node->next;
			return *this;
		}
		//i++
		self operator++(int)
		{
			self tem(*this);
			//_node = _node->next;
			++(*this);
			return tem;
		}
		//--i
		self& operator--()
		{
			_node = _node->prev;
			return *this ;
		}
		//i--
		self operator--(int)
		{
			__list_iterator<T> tem(*this);
			--(*this);
			return *this;
		}

		bool operator!=(const self& l)
		{
			return this->_node != l._node;
		}
		bool operator==(const self& l)
		{
			return this->_node == l._node;
		}
	};


	template<class T>
	class list
	{
		typedef __list_node<T> Node;
	public:
		typedef __list_iterator<T,T* ,T&> iterator;
		typedef __list_iterator<T,const T* ,const T&> const_iterator;

		iterator begin()
		{
			return iterator(_head->next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator begin()const 
		{
			return const_iterator(_head->next);
		}

		const_iterator end() const 
		{
			return const_iterator(_head);
		}

		list()
		{
			_head = new Node;
			_head->prev = _head;
			_head->next = _head;
		}
		//拷贝构造
		list(const list<T>& l)
		{
			_head = new Node;
			_head->prev = _head;
			_head->next = _head;

			//迭代器版
			//const_iterator  ci = l.begin();
			//while (ci != l.end())
			//{
			//	push_back(*ci);
			//	++ci;
			//}

			//简洁版，范围for
			for (auto e : l)
				push_back(e);
		}
		//传统写法
		//list<T>& operator=(const list<T>& l)
		//{
		//	if (this != &l)
		//	{
		//		clear();			
		//		for (auto e : l)
		//			push_back(e);
		//	}
		//	return *this;
		//}

		//现代写法
		//直接交换头指针
		list<T>& operator=(list<T> l)
		{
			swap(_head, l._head);
			return *this;
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;

		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				erase(it++);
			}
		}
		void push_back(const T& x) 
		{
			//Node* cur = _head->prev;
			//Node* newnode = new Node(x);
			//

			//cur->next = newnode;
			//newnode->prev = cur;
			//_head->prev = newnode;
			//newnode->next = _head;

			insert(end(), x);
		}

		void pop_back()
		{
			//Node* tail = _head->prev;
			//Node* cur=tail->prev;
			//cur->next = _head;
			//_head->prev = cur;
			//delete tail;

			//erase(iterator(_head->prev));
			erase(--end());
		}

		void pop_front()
		{
			//Node* cur = _head->next->next;
			//_head->next=cur;
			//cur->prev = _head;
			erase(begin());
		}
		void push_front(const T& x) 
		{
			//Node* cur = _head->next;
			//Node* ncur = _head->next->next;
			//_head->next = ncur;
			//ncur->prev = _head;
			insert(begin(), x);
		}

		void insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* pcur = cur->prev;
			Node* newnode = new Node(x);

			pcur->next = newnode;
			newnode->prev = pcur;
			cur->prev = newnode;
			newnode->next = cur;
		}

		void erase(iterator pos)
		{
			assert(pos != end());
			Node* cur = pos._node;
			Node* pcur = cur->prev;
			Node* ncur = cur->next;

			delete cur;
			pcur->next = ncur;
			ncur->prev = pcur;
		}

	private:
		Node* _head;
	};


	void print_list(const list<int>& l)
	{
		list<int>::const_iterator it = l.begin();
		while (it != l.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void test_list5()
	{
		list<int> lt;
		lt.push_back(12);
		lt.push_back(13);
		lt.push_back(14);
		lt.push_back(15);
		lt.push_front(11);

		print_list(lt);

		list<int> lt1(lt);
		lt1.push_back(16);

		print_list(lt1);

		list<int> lt2=lt;
		print_list(lt2);


	}




	void test_list4()
	{
		list<int> lt;
		lt.push_back(12);
		lt.push_back(13);
		lt.push_back(14);
		lt.push_back(15);
		lt.push_front(11);
		//lt.erase(12);
		//测试insert
		print_list(lt);

		lt.pop_back();
		lt.pop_front();
		lt.pop_front();
		print_list(lt);

	}
}