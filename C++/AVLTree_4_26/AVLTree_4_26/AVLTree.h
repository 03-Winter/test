#pragma once
template<class K,class V>
struct AVLTreeNode		//平衡二叉树，平衡因子绝对值不超过2
{
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _parent;

	int _bf;//balance factor
	pair<K, V> _kv;//键值对

	//构造函数
	AVLTreeNode(const pair<K,V>& kv)
		:_left(nullptr),
		_right(nullptr),
		_parent(nullptr),
		_bf(0),
		_kv(kv)
	{}
};

template<class K,class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	bool insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
				return false;
		}
		cur = new Node(kv);
		if (parent->_kv.first > kv.first)
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		//平衡二叉树因子

		while (parent)
		{
			if (cur == parent->_right)
				parent->_bf++;
			else
				parent->_bf--;

			if (parent->_bf == 0)//高度不变，更新结束
				break;
			else if (parent->_bf == 1 || parent->_bf == -1)//高度变了，继续向上更新
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					RotalRL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					RotalLR(parent);
				}

				break;
				////parent的子树出现问题，需要旋转处理
				//if (parent->_bf == 2)
				//{
				//	//if (cur->_bf == 1)
				//	if (cur->_bf >= 0)
				//	{
				//		RotalL(parent);
				//	}
				//	//else if (cur->_bf == -1)
				//	else
				//	{
				//		//双旋
				//		RotalRL(parent);
				//	}
				//}
				//else if(parent->_bf == -2)
				//{
				//	//if (cur->_bf == -1)
				//	if (cur->_bf <= 0)
				//	{
				//		RotalR(parent);
				//	}
				//	//else if (cur->_bf == 1)
				//	else
				//	{
				//		//双旋
				//		RotalLR(parent);
				//	}
				//}
				//break;
			}
			
		}

		return true; 
	}


	//void RotateR(Node* parent)
	//{
	//	Node* subL = parent->_left;
	//	Node* subLR = subL->_right;

	//	parent->_left = subLR;
	//	if (subLR)
	//		subLR->_parent = parent;

	//	subL->_right = parent;

	//	Node* ppNode = parent->_parent;
	//	parent->_parent = subL;

	//	if (parent == _root)
	//	{
	//		_root = subL;
	//		_root->_parent = nullptr;
	//	}
	//	else
	//	{
	//		if (ppNode->_left == parent)
	//		{
	//			ppNode->_left = subL;
	//		}
	//		else
	//		{
	//			ppNode->_right = subL;
	//		}

	//		subL->_parent = ppNode;
	//	}

	//	parent->_bf = subL->_bf = 0;
	//}

	//void RotateL(Node* parent)
	//{
	//	Node* subR = parent->_right;
	//	Node* subRL = subR->_left;

	//	parent->_right = subRL;
	//	if (subRL)
	//		subRL->_parent = parent;

	//	subR->_left = parent;
	//	Node* ppNode = parent->_parent;

	//	parent->_parent = subR;

	//	if (parent == _root)
	//	{
	//		_root = subR;
	//		_root->_parent = nullptr;
	//	}
	//	else
	//	{
	//		if (ppNode->_right == parent)
	//		{
	//			ppNode->_right = subR;
	//		}
	//		else
	//		{
	//			ppNode->_left = subR;
	//		}
	//		subR->_parent = ppNode;
	//	}

	//	parent->_bf = subR->_bf = 0;
	//}
	//左旋
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		subR->_left = parent;
		Node* ppnode = parent->_parent;
		parent->_parent = subR;

		//1.parent是根
		//2。不是根，则要改变链接关系
		if (_root == parent)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
				ppnode->_left = subR;
			else
				ppnode->_right = subR;

			subR->_parent = ppnode;
		}
		subR->_bf = parent->_bf = 0;
	}

	////右旋
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;
		Node* ppnode = parent->_parent;
		parent->_parent = subL;

		if (_root == parent)//这里少了个等号，导致我平衡树全错
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)//这里少了个等号，导致我平衡树全错
				ppnode->_left = subL;
			else
				ppnode->_right = subL;

			subL->_parent = ppnode;
		}
		subL->_bf = parent->_bf = 0;
	}


	//右左双旋
	void RotalRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		RotateR(parent->_right);
		RotateL(parent);

		if (bf == 1)
		{
			subR->_bf = 0;
			subRL->_bf = 0;
			parent->_bf = -1;
		}
		else if (bf == -1)
		{
			parent->_bf = 0;
			subR->_bf = 1;
			subRL->_bf = 0;
		}
		else if (bf == 0)
		{
			parent->_bf = 0;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
	}


	//左右双旋

	void RotalLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		RotateL(parent->_left);
		RotateR(parent);

		//旋转完成后，调节平衡因子
		if (bf == 1)
		{
			parent->_bf = 0;
			subL->_bf = -1;
			subLR->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 1;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
		else if (bf == 0)
		{
			parent->_bf = 0;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
	}

	int Height(Node* root)
	{
		if (!root) return 0;

		int leftheight = Height(root->_left);
		int rightheight = Height(root->_right);

		return leftheight > rightheight ? leftheight + 1 : rightheight + 1;
	}

	bool _Isbalace(Node* root)
	{
		if (root==nullptr) return true;

		int leftheight = Height(root->_left);
		int rightheight = Height(root->_right);

		return abs(leftheight - rightheight) < 2
			&&	_Isbalace(root->_left)
			&&  _Isbalace(root->_right);
	}


	bool Isbalace()
	{
		return _Isbalace(_root);
	}


	void _Inorder(Node* root)
	{
		if (root == nullptr) return;

		_Inorder(root->_left);
		cout << root->_kv.first << " : " << root->_kv.second << endl;
		_Inorder(root->_right);
	}

	void Inorder()
	{
		_Inorder(_root);
	}

private:
	Node* _root = nullptr;
};
