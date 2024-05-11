#pragma once
#pragma once
template<class K,class V>
struct BTreeNode
{
	BTreeNode<K,V>* _left;
	BTreeNode<K,V>* _right;

	K _key;//��ؼ���
	V _value;//������

	//���캯��
	BTreeNode(const K& key,const V& value)
		:_left(nullptr)
		, _right(nullptr)
		, _key(key)
		,_value(value)
	{}
};

template<class K,class V>
class Btree
{
	typedef BTreeNode<K,V> Node;
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
	bool insert(const K& kev,const V& value)
	{
		if (_root == nullptr)
		{
			_root = new Node(kev,value);
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
				return false; // �Ѵ�����ͬ�ļ�������false
		}

		Node* newnode = new Node(kev,value);

		//���ڵ������������
		if (parent->_key > kev)
			parent->_left = newnode;
		else
			parent->_right = newnode;

		return true;
	}

	//��ѯkeyֵ
	Node* find(const K& key)
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
				return cur;
			}
		}
		return nullptr;
	}

	//ɾ��
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

	//�����ӡ
	void _inorder(Node* root)
	{
		if (root == nullptr)
			return;
		_inorder(root->_left);
		cout << root->_key << ":" << root->_value << endl;;
		_inorder(root->_right);
	}

	void inorder()
	{
		_inorder(_root);
		cout << endl;
	}
private:
	Node* _root = nullptr;
};


void test_KV()
{
	//Btree<string, string> dict;
	//dict.insert("sort", "����");
	//dict.insert("milk", "ţ��");
	//dict.insert("apple", "ƻ��");
	//dict.insert("startle", "����");

	//string str;
	//while (cin >> str)
	//{
	//	BTreeNode<string, string>* ret = dict.find(str);
	//	if (ret)
	//	{
	//		cout << ret->_value << endl;
	//	}
	//	else
	//		cout << "���޴˴�" << endl;
	//}

	string array[] = {
		"ƻ��","С��","��Ϊ","ƻ��","С��","��Ϊ","����","oppo","vivo","��Ϊ","����","oppo","vivo"
	};
	Btree<string, int> count;
	for (auto e : array)
	{
		BTreeNode<string, int>* ret = count.find(e);
		if (ret==nullptr)
		{
			count.insert(e, 1);
		}
		else
		{
			ret->_value++;
		}
	}
	count.inorder();
}