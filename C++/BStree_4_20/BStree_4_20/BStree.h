#pragma once
template<class K>
struct BTreeNode
{
	BTreeNode<K>* _left;
	BTreeNode<K>* _right;
	K _key;//存数据

	//构造函数
	BTreeNode(const K& key)
		:_left(nullptr)
		,_right(nullptr)
		,_key(key)
	{}
};

template<class K>
class Btree
{
	typedef BTreeNode<K> Node;
public:
	//bool insert(const K& key)
	//{
	//	if (_root == nullptr)
	//	{
	//		_root = new Node(key);
	//		return true;
	//	}
	//	Node* cur = _root;
	//	Node* parent = nullptr;
	//	while (cur)
	//	{
	//		if (cur->_key > key) {
	//			parent = cur;
	//			cur = cur->_right;

	//		}
	//		else if (cur->_key < key) 
	//		{
	//			parent = cur;
	//			cur = cur->_left;

	//		}
	//		else 
	//			return false;
	//	}
	//	cur = new Node(key);
	//	if (parent->_key > key)
	//		parent->_right = cur;
	//	else if (parent->_key < key)
	//		parent->_left = cur;
	//	return true;
	//}
	bool insert(const K& kev)
	{
		if (_root == nullptr)
		{
			_root = new Node(kev);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;

		while (cur)
		{
			parent = cur;
			if (cur->_key > kev)
				cur = cur->_left;
			else if (cur->_key < kev)
				cur = cur->_right;
			else
				return false; // 已存在相同的键，返回false
		}

		Node* newnode = new Node(kev);

		//将节点跟树链接起来
		if (parent->_key > kev)
			parent->_left = newnode;
		else
			parent->_right = newnode;

		return true;
	}

	//查询key值
	bool find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else
			{
				return true;
			}
		}
		return false;
	}

	//删除
	bool erase(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				if (cur->_left == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_right;
					}
					else
					{
						if (cur == parent->_left)
							parent->_left = cur->_right;
						else if (cur == parent->_right)
							parent->_right = cur->_right;
					}

					delete cur;
				}
				else if (cur->_right = nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_left;
					}
					else
					{
						if (parent->_left == cur)
							parent->_left = cur->_left;
						else if (parent->_right == cur)
							parent->_right = cur->_left;
					}
				
					delete cur;
				}
				else
				{
					Node* RightMinParent = cur;
					Node* RightMin = cur->_right;
					while (RightMin->_left)
					{
						RightMinParent = RightMin;
						RightMin = RightMin->_left;
					}
					cur->_key = RightMin->_key;

					if (RightMin == RightMinParent->_left)
						RightMinParent->_left = RightMin->_right;
					else
						RightMinParent->_right = RightMin->_right;

					delete RightMin;
				}
				return true;
			}
		}
		return false;
	}

	//中序打印
	void _inorder(Node* root)
	{
		if (root == nullptr)
			return;
		_inorder(root->_left);
		cout << root->_key << " ";
		_inorder(root->_right);
	}

	void inorder()
	{
		_inorder(_root);
		cout << endl;
	}
private:
	Node* _root=nullptr;
};


void test_btree()
{
	Btree<int> b;
	int a[] = { 4,5,7,8,9,1,3 };
	for (auto e : a)
	{
		b.insert(e);
	}

	b.erase(2);
	b.inorder();

	b.erase(8);
	b.inorder();

	b.erase(5);
	b.inorder();

	b.erase(7);
	b.inorder();



	//cout << b.find(5) << endl;
	//cout << b.find(2) << endl;
	b.inorder();
}