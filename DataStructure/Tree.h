#pragma once

#include <iostream>

// 트리 : 나무 , 생김새가 나무처럼 생긴 자료구조.

// 트리의 노드가 가질 수 있는 최대 수에 따른 분류
// 2개 : 이진 트리(binary tree) - 주로 다루어 볼 것
// 3개 : Ternary tree
// 4개 : Octree

// 트리의 용어 
// 노드 : 트리의 기본 요소로 데이터를 저장하는 단위
// 루트 : 최상위에 있는 노드. 부모 노드가 없는 유일 노드입니다.
// 부모 노드 : 하위의 노드와 직접 연결된 노드.
// 자식 노드 : 부모 노드의 하위에 직접 연결된 노드.
// 형제 노드 : 같은 부모를 가진 노드.
// 조상 노드 : 특정 노드에서 루트까지 경로에 있는 모든 노드들
// 후손 노드 : 특정 노드의 모든 자식, 자식의 자식 들을 포함한 노드들
// 레벨 : 루트로 부터의 거리. 루트노드 레벨 : 0 
// 높이 : 트리에서 가장 깊은 레벨을 의미한다.
// 서브 트리 : 트리 내부의 노드와 그 후손들로 구성된 트리
// 차수 (degree) : 하나의 노드가 가진 자식 노드의 수
// 경로 : 하나의 노드에서 다른 노드로 이동할 때 거치는 노드들의 순서

// 트리
// 1. 루트가 한 개만 존재해야다.
// 2. 노드들이 순환하지 않아야한다.

// 이진 트리의 종류 
// 이진 트리 : 모든 노드들이 가질 수 있는 자식의 수(degree) 2개 이하로 구성된 자료구조
// 이진 탐색, 중간 삽입 삭제 빠른 자료구조 - 이진 검색 트리
// Full binary tree
// complate binary tree
// perfect binary tree

// 트리의 순회 방식
// PreOrder 전위 순회
// InOrder 중위 순회
// PostOrder 후위 순회

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
		// 재귀 함수 : 자기 자신의 함수를 호출하는 함수
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

// BST : 이진 검색 트리
// 선형 자료구조에서 이진 검색이 비효율적이다. 이진 검색을 효율적으로 할 수 있는 구조

// 이진 검색을 하기 위해서 다음의 규칙을 따릅니다.
// 노드의 기준으로 왼쪽 노드는 자신 노드보다 작은 값, 오른쪽 노드는 자신보다 큰 값을 저장한다.
// 중복은 허용하지않는다.

// 검색에 걸리는 시간 : logn
// 중간 삽입 삭제 : logn
// insert
// delete

// 삭제의 방법

// 1. 삭제하고자 하는 노드의 자식이 없을 때
 
// 2. 삭제하고자 하는 노드에 왼쪽에만 자식이 있을 때
 
// 3. 삭제하고자 하는 노드의 오른쪽에만 자식이 있을 때
 
// 4. 양쪽에 자식이 있을때

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
	// Tree 자료구조에 저장되어 있는 상태 root
	// 데이터를 순회하는 방법 : PreOrder, InOrder, PostOrder

	Tree::Node* root = new Tree::Node(3);
	root->left = new Tree::Node(4);
	root->right = new Tree::Node(1);
	root->left->left = new Tree::Node(5);
	root->left->right = new Tree::Node(2);

	Tree myTree;
	// PreOrder의 결과 : 1 - 2 - 4 - 5 - 3
	std::cout << "== 전위 순회 PreOrder ==" << std::endl;
	myTree.PreOrder(root);
	std::cout << std::endl;
	// InOrder의 결과 : 4 - 2 - 5 - 1 - 3
	std::cout << "== 중위 순회 InOrder ==" << std::endl;
	myTree.InOrder(root);
	std::cout << std::endl;
	// PostOrder의 결과 : 4 - 5 - 2 - 3 - 1
	std::cout << "== 후위 순회 PostOrder ==" << std::endl;
	myTree.PostOrder(root);
	std::cout << std::endl;

	BinarySearchTree bst;

	bst.insert(10);
	bst.insert(7);
	bst.insert(25);
	bst.insert(8);
	bst.insert(49);

	bst.InOrder();

	std::cout << "탐색결과 : " << (bst.search(30) ? "찾음" : "못 찾음") << std::endl;

}



