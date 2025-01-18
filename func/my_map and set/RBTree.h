#pragma once
#include<iostream>

using namespace std;

enum color
{
	RED,
	BLACK
};
template<class T>
struct RBNode
{
	struct RBNode<T>* _parent;
	struct RBNode<T>* _left;
	struct RBNode<T>* _right;
	T _data;
	color _col;

	RBNode(const T& data)
		:_data(data),
		_parent(nullptr),
		_left(nullptr),
		_right(nullptr)
	{}
};

template<class T,class Ref,class Ptr>
struct RBTreeIterator
{
	typedef RBNode<T> Node;
	typedef RBTreeIterator<T, Ref, Ptr> Self;

	Node* _node;
	Node* _root;

	RBTreeIterator(Node* node, Node* root)
		:_node(node)
		,_root(root)
	{}

	Self operator++()
	{
		if (_node->_right)
		{
			// �Ҳ�Ϊ�գ�������һ�����ʵĽڵ���������������(��С)�ڵ�
			Node* min = _node->_right;
			while (min->_right)
				min = min->_right;
			_node = min;
		}
		else
		{
			// ��Ϊ�գ��������溢���Ǹ�������Ǹ�����
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_right)
			{
				cur = parent;
				parent = cur->_parent;
			}
			_node = parent;
		}
		return *this;
	}
	Self operator--()
	{
		if (_node == nullptr)
		{
			// �����Ѿ�������������Ľ�β�ˣ�--�͵��������������ҽڵ�
			Node* RightMost = _root;
			while (RightMost && RightMost->_right)
				RightMost = RightMost->_right;
			_node = RightMost;
		}
		else if (_node->_left)
		{
			// ��ǰ�ڵ����������Ϊ�գ�--�͵��������������ҽڵ�
			Node* RightMost = _node->_left;
			while (RightMost->_right)
				RightMost = RightMost->_right;
			_node = RightMost;
		}
		else
		{
			// ��ǰ�ڵ��������Ϊ�գ�--�͵��˺����Ǹ����ҵĽڵ�
			Node* cur = _node;
			Node* parent = _node->_parent;
			while (parent && cur == parent->_left)
			{
				cur = parent;
				parent = cur->_parent;
			}
			_node = parent;
		}
		return *this;
	}
	Ref operator*()
	{
		return _node->_data;
	}
	Ptr operator->()
	{
		return &_node->_data;
	}
	bool operator!=(const Self& s) const
	{
		return _node != s._node;
	}
	bool operator==(const Self& s) const
	{
		return _node == s._node;
	}
};

template<class K,class T,class KeyOfT>
class RBTree
{
	typedef struct RBNode<T> Node;
public:
	typedef RBTreeIterator<T, T&, T*> Iterator;
	typedef RBTreeIterator<T, const T&, const T*> ConstIterator;

	Iterator Begin()
	{
		Node* cur = _root;
		while (cur && cur->_left)
			cur = cur->_left;
		return Iterator(cur, _root);
	}
	Iterator End()
	{
		return Iterator(nullptr, _root);
	}
	ConstIterator Begin() const
	{
		Node* cur = _root;
		while (cur && cur->_left)
			cur = cur->_left;
		return ConstIterator(cur, _root);
	}
	ConstIterator End() const
	{
		return ConstIterator(nullptr, _root);
	}
	pair<Iterator,bool> Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			return { Iterator(_root,_root),true };
		}

		KeyOfT kot;
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (kot(cur->_data) > kot(data))
			{
				parent = cur;//�ȸ���parent
				cur = cur->_left;
			}
			else if (kot(cur->_data) < kot(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else
				return { Iterator(cur,_root),false };
		}
		cur = new Node(data);
		Node* newnode = cur;
		cur->_col = RED;
		if (kot(parent->_data) < kot(data))
			parent->_right = cur;
		else
			parent->_left = cur;
		cur->_parent = parent;
			
		// �����½ڵ㣬�丸�ڵ������Ϊ�죬�����Ϲ�����Ҫ����
		while (parent && parent->_col == RED)
		{
			Node* gradfather = parent->_parent;
			if (parent == gradfather->_left)
			{
				Node* uncle = gradfather->_right;
				if (uncle && uncle->_col == RED)// ���������Ϊ��
				{
					parent->_col = uncle->_col = BLACK;
					gradfather->_col = RED;
					// ���ϴ���
					cur = gradfather;
					parent = cur->_parent;
				}
				else// ���岻���ڣ��������������Ϊ��
				{
					if (cur == parent->_left)
					{
						//      g
						//    p   u
						//  c
						RotateR(gradfather);
						parent->_col = BLACK;
						gradfather->_col = RED;
					}
					else
					{
						//      g
						//    p   u
						//     c
						RotateL(parent);
						RotateR(gradfather);
						cur->_col = BLACK;
						gradfather->_col = RED;
					}
					break;
				}
			}
			else
			{
				Node* uncle = gradfather->_left;
				if (uncle && uncle->_col == RED)// ���������Ϊ��
				{
					parent->_col = uncle->_col = BLACK;
					gradfather->_col = RED;
					// ���ϴ���
					cur = gradfather;
					parent = cur->_parent;
				}
				else// ���岻���ڣ��������������Ϊ��
				{
					if (cur == parent->_right)
					{
						//      g
						//    u   p
						//          c
						RotateL(gradfather);
						parent->_col = BLACK;
						gradfather->_col = RED;
					}
					else
					{
						//      g
						//    u   p
						//       c
						RotateR(parent);
						RotateL(gradfather);
						cur->_col = BLACK;
						gradfather->_col = RED;
					}
					break;
				}
			}
		}
		_root->_col = BLACK;

		return { Iterator(newnode, _root),true };
	}
private:
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		Node* pParent = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;

		if (parent == _root)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (pParent->_left == parent)
			{
				pParent->_left = subL;
			}
			else
			{
				pParent->_right = subL;
			}

			subL->_parent = pParent;
		}
	}
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		Node* parentParent = parent->_parent;
		subR->_left = parent;
		parent->_parent = subR;
		if (parentParent == nullptr)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (parent == parentParent->_left)
			{
				parentParent->_left = subR;
			}
			else
			{
				parentParent->_right = subR;
			}
			subR->_parent = parentParent;
		}
	}

private:
	Node* _root = nullptr;
};