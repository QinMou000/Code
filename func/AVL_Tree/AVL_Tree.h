#pragma once
#include<iostream>
#include<vector>
#include<assert.h>

using namespace std;

template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode(const pair<K, V>& kv)
		:_parent(nullptr),
		_left(nullptr),
		_right(nullptr),
		_kv(kv),
		_bf(0)
	{}
	struct AVLTreeNode<K, V>* _parent;
	struct AVLTreeNode<K, V>* _left;
	struct AVLTreeNode<K, V>* _right;
	pair<K, V> _kv;
	int _bf;
};

template<class K,class V>
class AVLTree
{
	typedef struct AVLTreeNode<K,V> Node;
public:
	AVLTree()
		:_root(nullptr)
		,_size(0)
	{}
	bool Insert(const pair<K,V>& kv)
		// 插入不要新建一个newnode，直接用cur节点，
		// newnode可能会导致
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_size++;
			return true;
		}
		else
		{
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_kv.first > kv.first)
				{
					parent = cur;//先更新parent
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

			if (parent->_kv.first < cur->_kv.first)
				parent->_right = cur;
			else
				parent->_left = cur;
			cur->_parent = parent;

			while (parent)
			{
				if (cur == parent->_left)
					parent->_bf--;
				else
					parent->_bf++;

				if (parent->_bf == 0)
					break;// 结束更新
				else if (parent->_bf == 1 || parent->_bf == -1)
				{
					// 继续往上更新
					cur = parent;// 先更新cur
					parent = parent->_parent;
				}
				else if (parent->_bf == 2 || parent->_bf == -2)
				{
					// 旋转
					if (parent->_bf == 2 && cur->_bf == 1)
						RotateL(parent);
					else if (parent->_bf == -2 && cur->_bf == -1)
						RotateR(parent);
					else if (parent->_bf == 2 && cur->_bf == -1)
						RotateRL(parent);
					else if(parent->_bf == -2 && cur->_bf == 1)
						RotateLR(parent);
					break;
				}
				else
					assert(false);// 在插入之前就不是AVL树
			}
		}
		_size++;
		return true;
	}
	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < key)
			{
				cur = cur->_right;
			}
			else if (cur->_kv.first > key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}
	int Height()
	{
		return _Height(_root);
	}
	bool IsBalanceTree()
	{
		return _IsBalanceTree(_root);
	}
	int Size()
	{
		return _size;
	}
private:

	bool _IsBalanceTree(Node* root)
	{
		// 空树也是AVL树
		if (nullptr == root)
			return true;
		// 计算pRoot结点的平衡因⼦：即pRoot左右⼦树的⾼度差
		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);
		int diff = rightHeight - leftHeight;
		// 如果计算出的平衡因⼦与pRoot的平衡因⼦不相等，或者
		// pRoot平衡因⼦的绝对值超过1，则⼀定不是AVL树
		if (abs(diff) >= 2)
		{
			cout << root->_kv.first << "⾼度差异常" << endl;
			return false;
		}
		if (root->_bf != diff)
		{
			cout << root->_kv.first << "平衡因⼦异常" << endl;
			return false;
		}
		// pRoot的左和右如果都是AVL树，则该树⼀定是AVL树
		return _IsBalanceTree(root->_left) && _IsBalanceTree(root->_right);
	}
	int _Height(Node* root)
	{
		if (root == nullptr)
			return 0;
		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);
		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		Node* Pparent = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;

		//链接上面的
		if (Pparent)
		{
			subL->_parent = Pparent;

			if (Pparent->_left == parent)
				Pparent->_left = subL;
			else
				Pparent->_right = subL;
		}	
		else
		{
			subL->_parent = nullptr;
			_root = subL;
		}
		parent->_bf = 0;
		subL->_bf = 0;
	}
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		Node* Pparent = parent->_parent;

		subR->_left = parent;
		parent->_parent = subR;

		if (Pparent)
		{
			if(Pparent->_left == parent)
				Pparent->_left = subR;
			else
				Pparent->_right = subR;

			subR->_parent = Pparent;
		}
		else
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		subR->_bf = 0;
		parent->_bf = 0;
	}
	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		int bf = subLR->_bf;

		RotateL(subL);
		RotateR(parent);

		if (bf == 0)
		{
			subL->_bf = 0;
			subLR->_bf = 0;
			parent->_bf = 0;
		}
		else if (bf == 1)
		{
			subL->_bf = -1;
			subLR->_bf = 0;
			parent->_bf = 0;
		}
		else if (bf == -1)
		{
			subL = 0;
			subLR->_bf = 0;
			parent->_bf = 1;
		}
		else
			assert(false);
	}
	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		int bf = subRL->_bf;

		RotateR(subR);
		RotateL(parent);

		if (bf == 0)
		{
			subR->_bf = 0;
			subRL->_bf = 0;
			parent->_bf = 0;
		}
		else if (bf == -1)
		{
			subR->_bf = 1;
			subRL->_bf = 0;
			parent->_bf = 0;
		}
		else if (bf == 1)
		{
			subR->_bf = 0;
			subRL->_bf = 0;
			parent->_bf = -1;
		}
		else
			assert(false);
	}

private:
	int _size;
	Node* _root;
};