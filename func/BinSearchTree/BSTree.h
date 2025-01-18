#pragma once
#include<iostream>
#include<assert.h>

using namespace std;

template<class K>
struct BSNode
{
	BSNode(const K& key)
	{
		_key = key;
		_left = nullptr;
		_right = nullptr;
	}
	struct BSNode* _left;
	struct BSNode* _right;
	K _key;
};

template<class K>
class BSTree
{
	typedef struct BSNode<K> Node;
public:
	bool Insert(const K& key)
	{
		Node* newnode = new Node(key);
		if (_root == nullptr)
		{
			_root = newnode;
			return true;
		}
		else
		{
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key > newnode->_key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_key < newnode->_key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else
					return false;
			}
			if (parent->_key > newnode->_key)
				parent->_left = newnode;
			if (parent->_key < newnode->_key)
				parent->_right = newnode;
			return true;
		}
	}
	Node* Find(const K& key)
	{
		assert(_root);
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
				return cur;
		}
		return nullptr;
	}
	bool Erase(const K& key)
	{
		assert(_root);
		Node* cur = _root;
		Node* parent = nullptr;
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
				// ɾ��
				if (cur->_left == nullptr)
				{
					if (cur == _root)//���ɾ��û���������ĸ��ڵ�
					{
						_root = cur->_right;
					}
					// ������Ϊ��and����������Ϊ��
					else if (parent->_left == cur)
					{
						parent->_left = cur->_right;
					}
					else if (parent->_right == cur)
					{
						parent->_right = cur->_right;
					}
					delete cur;
				}
				else if (cur->_right == nullptr)
				{
					if (cur == _root)//���ɾ��û���������ĸ��ڵ�
					{
						_root = cur->_left;
					}
					// ������Ϊ��
					else if (parent->_left == cur)
					{
						parent->_left = cur->_left;
					}
					else if (parent->_right == cur)
					{
						parent->_right = cur->_left;
					}
					delete cur;
				}
				else
				{
					//������������Ϊ��
					Node* replaceparent = cur;
					Node* replace = cur->_right;
					while (replace->_left)
					{
						replaceparent = replace;
						replace = replace->_left;
					}
					cur->_key = replace->_key;

					if (replaceparent->_left == replace)
					{
						replaceparent->_left = replace->_right;
					}
					else if (replaceparent->_right == replace)
					{
						replaceparent->_right = replace->_right;
					}
					delete replace;
				}
				return true;
			}
		}
		return false;
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
private:
	void _InOrder(const Node* node)
	{
		if (node == nullptr)
			return;
		_InOrder(node->_left);
		cout << node->_key << " ";
		_InOrder(node->_right);
	}
public:
	Node* _root = nullptr;
};