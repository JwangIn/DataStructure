#pragma once

#include <iostream>

// Ʈ�� : ���� , ������� ����ó�� ���� �ڷᱸ��.

// Ʈ���� ��尡 ���� �� �ִ� �ִ� ���� ���� �з�
// 2�� : ���� Ʈ��(binary tree) - �ַ� �ٷ�� �� ��
// 3�� : Ternary tree
// 4�� : Octree

// Ʈ���� ��� 
// ��� : Ʈ���� �⺻ ��ҷ� �����͸� �����ϴ� ����
// ��Ʈ : �ֻ����� �ִ� ���. �θ� ��尡 ���� ���� ����Դϴ�.
// �θ� ��� : ������ ���� ���� ����� ���.
// �ڽ� ��� : �θ� ����� ������ ���� ����� ���.
// ���� ��� : ���� �θ� ���� ���.
// ���� ��� : Ư�� ��忡�� ��Ʈ���� ��ο� �ִ� ��� ����
// �ļ� ��� : Ư�� ����� ��� �ڽ�, �ڽ��� �ڽ� ���� ������ ����
// ���� : ��Ʈ�� ������ �Ÿ�. ��Ʈ��� ���� : 0 
// ���� : Ʈ������ ���� ���� ������ �ǹ��Ѵ�.
// ���� Ʈ�� : Ʈ�� ������ ���� �� �ļյ�� ������ Ʈ��
// ���� (degree) : �ϳ��� ��尡 ���� �ڽ� ����� ��
// ��� : �ϳ��� ��忡�� �ٸ� ���� �̵��� �� ��ġ�� ������ ����

// Ʈ��
// 1. ��Ʈ�� �� ���� �����ؾߴ�.
// 2. ������ ��ȯ���� �ʾƾ��Ѵ�.

// ���� Ʈ���� ���� 
// ���� Ʈ�� : ��� ������ ���� �� �ִ� �ڽ��� ��(degree) 2�� ���Ϸ� ������ �ڷᱸ��
// ���� Ž��, �߰� ���� ���� ���� �ڷᱸ�� - ���� �˻� Ʈ��
// Full binary tree
// complate binary tree
// perfect binary tree

// Ʈ���� ��ȸ ���
// PreOrder ���� ��ȸ
// InOrder ���� ��ȸ
// PostOrder ���� ��ȸ

class Tree
{
private:

public:
	struct Node
	{
		int data;
		Node* left;
		Node* right;

		Node(int _data) :data(_data), left(nullptr), right(nullptr){}
	};

	void PreOrder(Node* root)
	{
		// ��� �Լ� : �ڱ� �ڽ��� �Լ��� ȣ���ϴ� �Լ�
		if (root == nullptr)return;

		std::cout << root->data << " ";
		PreOrder(root->left);
		PreOrder(root->right);

	}
	void InOrder(Node* root)
	{
		if (root == nullptr)return;

		InOrder(root->left);
		std::cout << root->data << " ";
		InOrder(root->right);
	}
	void PostOrder(Node* root)
	{
		if (root == nullptr)return;

		PostOrder(root->left);
		PostOrder(root->right);
		std::cout << root->data << " ";

	}

};

// BST : ���� �˻� Ʈ��
// ���� �ڷᱸ������ ���� �˻��� ��ȿ�����̴�. ���� �˻��� ȿ�������� �� �� �ִ� ����

// ���� �˻��� �ϱ� ���ؼ� ������ ��Ģ�� �����ϴ�.
// ����� �������� ���� ���� �ڽ� ��庸�� ���� ��, ������ ���� �ڽź��� ū ���� �����Ѵ�.
// �ߺ��� ��������ʴ´�.

// �˻��� �ɸ��� �ð� : logn
// �߰� ���� ���� : logn
// insert
// delete

// ������ ���

// 1. �����ϰ��� �ϴ� ����� �ڽ��� ���� ��
 
// 2. �����ϰ��� �ϴ� ��忡 ���ʿ��� �ڽ��� ���� ��
 
// 3. �����ϰ��� �ϴ� ����� �����ʿ��� �ڽ��� ���� ��
 
// 4. ���ʿ� �ڽ��� ������

class BinarySearchTree
{
public:
	struct Node
	{
		int data;
		Node* left;
		Node* right;

		Node(int _data) :data(_data), left(nullptr), right(nullptr) {}
	};
private:
	Node* root;

	Node* insert(Node* root, int value)
	{
		if (root == nullptr)
			return new Node(value);

		if (value < root->data)
		{
			root->left = insert(root->left,value);
		}

		if (value > root->data)
		{
			root->right = insert(root->right, value);
		}

		return root;
	}

	Node* search(Node* root, int target)
	{
		if (root == nullptr || root->data == target)
		{
			return root;
		}

		if (target < root->data)
		{
			return search(root->left, target);
		}
		else if (target > root->data)
		{
			return search(root->right, target);
		}
	}
	void inOrder(Node* root)
	{
		if (root == nullptr)return;

		inOrder(root->left);
		std::cout << root->data << " ";
		inOrder(root->right);
	}
public:
	BinarySearchTree():root(nullptr){}

	void insert(int value)
	{
		root = insert(root, value);
	}

	bool search(int value)
	{
		return search(root, value) != nullptr;
	}

	void InOrder()
	{
		inOrder(root);
		std::cout << std::endl;
	}
};

void TreeExample()
{
	// Tree �ڷᱸ���� ����Ǿ� �ִ� ���� root
	// �����͸� ��ȸ�ϴ� ��� : PreOrder, InOrder, PostOrder

	Tree::Node* root = new Tree::Node(3);
	root->left = new Tree::Node(4);
	root->right = new Tree::Node(1);
	root->left->left = new Tree::Node(5);
	root->left->right = new Tree::Node(2);

	Tree myTree;
	// PreOrder�� ��� : 1 - 2 - 4 - 5 - 3
	std::cout << "== ���� ��ȸ PreOrder ==" << std::endl;
	myTree.PreOrder(root);
	std::cout << std::endl;
	// InOrder�� ��� : 4 - 2 - 5 - 1 - 3
	std::cout << "== ���� ��ȸ InOrder ==" << std::endl;
	myTree.InOrder(root);
	std::cout << std::endl;
	// PostOrder�� ��� : 4 - 5 - 2 - 3 - 1
	std::cout << "== ���� ��ȸ PostOrder ==" << std::endl;
	myTree.PostOrder(root);
	std::cout << std::endl;

	BinarySearchTree bst;

	bst.insert(10);
	bst.insert(7);
	bst.insert(25);
	bst.insert(8);
	bst.insert(49);

	bst.InOrder();

	std::cout << "Ž����� : " << (bst.search(30) ? "ã��" : "�� ã��") << std::endl;

}



