#pragma once
#include<iostream>
using namespace std;
enum Color
{
	RED,
	BLACK,
};

template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent; 

	T _data;
	Color _col;
	RBTreeNode(const T& data)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_data(data)
		,_col(RED)
	{}
};
 
//Ref和Ptr的模板可以实现复用，用于实现const_iteartor迭代器
template<class T, class Ref,class Ptr> 
struct __TreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef __TreeIterator<T,Ref,Ptr> Self;
	Node* _node;
	
	__TreeIterator(Node* node)
		:_node(node)
	{}

	Ref operator*()
	{
		return _node->_data;
	}
	Ptr operator->()
	{
		return &_node->_data;
	}

	Self& operator++()
	{
		//如果右不为空，中序的下一个就是右子树的最左节点
		//如果右不为空，表示_node所在的子树已经放完成，在一个节点早它的祖先种找
		if (_node->_right)
		{
			Node* subLeft = _node->_right;
			while (subLeft->_left)
			{
				subLeft = subLeft->_left;
			}
			_node = subLeft;
		}
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && parent->_right == cur)
			{
				cur = parent;
				//cur = cur->_parent;
				parent = parent->_parent;
			}
			//cur = parent;错误，赋值
			_node = parent;
		}
		return *this;
	}

	Self& operator--()
	{
		if (_node->_left)
		{
			
			Node* subRight = _node->_left;
			while (subRight->_right)
			{
				subRight = subRight->_right;
			}
			_node = subRight;
		}
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_left)
			{
				cur = parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		return *this;
	}

	bool operator!=(const Self& s)
	{
		return s._node != this->_node;
	}

	bool operator==(const Self& s)
	{
		return s._node == this->_node;
	}

};



template<class K,class T,class KOfT>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef __TreeIterator<T, T&, T*> iterator;
	typedef __TreeIterator<T, const T&,const T*> const_iterator;//const迭代器

	iterator begin()
	{
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}
		return iterator(cur);
	}

	iterator end()
	{
		return iterator(nullptr);
	}

	pair<iterator,bool> insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			return make_pair(iterator(_root),true);
		}
		KOfT koft;
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (koft(cur->_data) > koft(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (koft(cur->_data) < koft(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else
				return make_pair(iterator(cur), false);
		}

		cur = new Node(data);
		Node* newnode = cur;
		cur->_col = RED;

		if (koft(parent->_data) > koft(cur->_data))
		{
			parent->_left = cur;
		}
		else if (koft(parent->_data) < koft(cur->_data))
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
					break;//要放在里面，不然崩啦
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
		return make_pair(iterator(newnode), true);
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

	//bool IsvalidRbTree()
	//{
	//	Node* pRoot = _root;
	//	if (!pRoot) return true;
	//	if (pRoot->_col != BLACK)
	//	{
	//		cout << "性质二：根节点为黑" << endl;
	//		return false;
	//	}
	//	size_t count = 0;
	//	Node* pCur = pRoot;
	//	while (pCur)
	//	{
	//		if (BLACK == pCur->_col)
	//			count++;
	//		pCur = pCur->_left;
	//	}
	//	size_t k = 0;
	//	return _IsvalidRbTree(pRoot, k, count);
	//}

	//bool _IsvalidRbTree(Node* pRoot, size_t k, const size_t count)
	//{
	//	if (nullptr==pRoot)
	//	{
	//		if (k != count)
	//		{
	//			cout << "性质四：每条路的黑节点个数相同" << endl;
	//			return false;
	//		}
	//		return true;
	//	}
	//	if (BLACK == pRoot->_col)
	//		++k;
	//	Node* pParent = pRoot->_parent;
	//	if (pParent && RED == pParent->_col && pRoot->_col == RED)
	//	{
	//		cout << "性质三：连续的红节点" << endl;
	//		return false;
	//	}
	//	return _IsvalidRbTree(pRoot->_left, k, count) &&
	//		_IsvalidRbTree(pRoot->_right, k, count);
	//}

	iterator Find(const K& key) {
		KOfT koft;
		Node* cur = _root;
		while (cur)
		{
			if (koft(cur->_data) > koft(key))
			{
				cur = cur->_left;
			}
			else if (koft(cur->_data) < koft(key))
			{
				cur = cur->_right;
			}
			else
			{
				return iterator(cur);
			}
		}
		return iterator(nullptr);
	}


private:
	Node* _root = nullptr;
};

