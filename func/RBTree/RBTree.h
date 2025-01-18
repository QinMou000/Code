#pragma once
#include<iostream>

using namespace std;

enum color
{
	RED,
	BLACK
};
template<class K,class V>
struct RBNode
{
public:
	RBNode(const pair<K, V>& kv)
		:_kv(kv),
		_parent(nullptr),
		_left(nullptr),
		_right(nullptr),
		_col(RED)
	{}
	struct RBNode<K, V>* _parent;
	struct RBNode<K, V>* _left;
	struct RBNode<K, V>* _right;
	pair<K, V> _kv;
	color _col;
};

template<class K,class V>
class RBTree
{
	typedef struct RBNode<K, V> Node;
public:
	bool insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
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
					parent = cur;//�ȸ���parent
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
							gradfather->_col = RED;
							cur->_col = BLACK;
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

			return true;
		}
	}
private:
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

		//���������
		if (parent)
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
			if (Pparent->_left == parent)
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
	}

private:
	Node* _root = nullptr;
};