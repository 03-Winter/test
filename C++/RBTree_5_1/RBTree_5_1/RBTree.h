#pragma once
enum Color
{
	RED,
	BLACK,
};

template<class K,class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;

	pair<K, V> _kv;
	Color _col;
	RBTreeNode(const pair<K,V>& key)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_kv(key)
		,_col(RED)
	{}
};

template<class K,class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	bool insert(const pair<K, V>& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			_root->_col = BLACK;
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > key.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < key.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
				return false;
		}

		cur = new Node(key);
		cur->_col = RED;

		if (parent->_kv.first > key.first)
		{
			parent->_left = cur;
		}
		else if (parent->_kv.first < key.first)
		{
			parent->_right = cur;
		}
		cur->_parent = parent;

		while (parent && parent->_col == RED)
		{
			Node* grandparent = parent->_parent;
			if (grandparent->_left == parent)
			{
				Node* uncle = grandparent->_right;
				//情况一：unclec存在为红
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandparent->_col = RED;

					cur = grandparent;
					parent = cur->_parent;
				}
				else//情况二，uncle不存在，或者存在且为黑 
				{
					if (cur == parent->_right)
					{
						RotateL(parent);
						swap(parent, cur);
					}
					RotateR(grandparent);
					grandparent->_col = RED;
					parent->_col = BLACK;
					//break即可有也可无
					//break;//要放在里面，不然崩啦
				}
				//break;//要放在外面崩啦
			}
			else if (grandparent->_right == parent)
			{
				Node* uncle = grandparent->_left;
				if (uncle && uncle->_col == RED)
				{
					uncle->_col = parent->_col = BLACK;
					grandparent->_col = RED;

					cur = grandparent;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_left)
					{
						RotateR(parent);
						swap(parent, cur);
					}
					RotateL(grandparent);
					grandparent->_col = RED;
					parent->_col = BLACK;
					
				}
				break;
			}

		}
		_root->_col = BLACK;
		return true;
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		parent->_right = subRL;//左旋方向错误
		if (subRL)
			subRL->_parent = parent;
		subR->_left = parent;
		Node* ppnode = parent->_parent;
		parent->_parent = subR;
		if (_root == parent)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = subR;
			}
			else
			{
				ppnode->_right = subR;
			}
			subR->_parent = ppnode;
		}
	}
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;
		subL->_right = parent;
		Node* ppNode = parent->_parent;
		parent->_parent = subL;
		if (parent == _root)
		{
			_root = subL;
			_root->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
			{
				ppNode->_left = subL;
			}
			else
			{
				ppNode->_right = subL;
			}
			subL->_parent = ppNode;
		}
	}

	void _Inorder(Node* root)
	{
		if (!root) return;
		_Inorder(root->_left);
		cout << root->_kv.first << " : " << root->_kv.second << endl;
		_Inorder(root->_right);
	}
	void Inorder()
	{
		_Inorder(_root);
	}

	bool IsvalidRbTree()
	{
		Node* pRoot = _root;
		if (!pRoot) return true;
		if (pRoot->_col != BLACK)
		{
			cout << "性质二：根节点为黑" << endl;
			return false;
		}
		size_t count = 0;
		Node* pCur = pRoot;
		while (pCur)
		{
			if (BLACK == pCur->_col)
				count++;
			pCur = pCur->_left;
		}
		size_t k = 0;
		return _IsvalidRbTree(pRoot, k, count);
	}

	bool _IsvalidRbTree(Node* pRoot, size_t k, const size_t count)
	{
		if (nullptr==pRoot)
		{
			if (k != count)
			{
				cout << "性质四：每条路的黑节点个数相同" << endl;
				return false;
			}
			return true;
		}
		if (BLACK == pRoot->_col)
			++k;
		Node* pParent = pRoot->_parent;
		if (pParent && RED == pParent->_col && pRoot->_col == RED)
		{
			cout << "性质三：连续的红节点" << endl;
			return false;
		}
		return _IsvalidRbTree(pRoot->_left, k, count) &&
			_IsvalidRbTree(pRoot->_right, k, count);
	}

	Node* Find(const K& key) {
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > key)
			{
				cur = cur->_left;
			}
			else if (cur->_kv.first < key)
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


private:
	Node* _root = nullptr;
};
