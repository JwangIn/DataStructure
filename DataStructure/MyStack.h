#pragma once
#include <iostream>
#include <string>


/*
*  �ڷᱸ�� �����̳� : Array, Vector, Linked List
*  
*  ���� �����̳ʸ� �����ؼ�(�ڷḦ ����, ����) ����� �����ؼ� ���α׷��� ����ȭ�� ������ �ڷᱸ����.
*/

// Stack �ڷᱸ��
// ���� : ���𰡸� �״�.
// ��Ź�� �ٱ��Ͽ� ���� �׾Ƽ� �ѹ��� ��Ź�⿡ �������� �Ѵ�.
// ���� ���� �������� ���� �༮���� ��Ź�⿡ ����.
// ���� ù��°�� ���� �༮��(First In) ���� �������� ������.(Last Out) -> FILO
// ���� �������� ���� �༮��(Last In) ���� ���� ������.(Fist Out) -> LIFO

// Vector, Linked List, Array �ڷᱸ���� ����ϰ� �־��µ�,
// Stack, Queue, Priority Queue �� ����ؾ� �ϴ°�?

// Stack�� ����
// 1. Ŭ���� �����ϱⰡ ����.
// 2. LIFO �������, ������� �����մϴ�.

// ����
// 1. ���� ���(Undo) : ctrl + z �������� �������� �ʴ´ٸ�... 
// 2. ���� ǥ��� : �����ϱⰡ ���ϴ�. ��ǻ�Ͱ� �б⿡ ���� ǥ���� ���� ǥ����Դϴ�.
// ex) 1+1+2 => 112++

// �迭 ��� Stack

template <typename T>
class MyArrayStack
{
private: // �ʵ�
	T*	stackArray; // ���� ������ �����ϱ� ���� �迭
	int capacity;	// ������ �ִ� ũ��
	int top;		// ���� ���� ��ܿ� �ִ� �ε���
public: // ���
	// ������ 
	// capacity �ִ� ũ�⸦ �Ҵ��ϴ� �����ڸ� �����غ�����
	// top�� ����Ű�� �ε����� -1 : �����Ͱ� �������� ������ ǥ���ϱ� ���� ��
	// top�� ����Ű�� �ε����� 0 : ����� ���� ���� �������� ǥ���� �� �ִ�. 
	// stackArray�� capacity�� ���� �Ҵ����ش�.
	MyArrayStack(int size = 10)
	{
		stackArray = new T[size];
		capacity = size;
		top = -1;
	}
	~MyArrayStack()
	{
		// stackArray null�� �ƴҶ��� �����Ͻÿ�.
		if(stackArray!=nullptr)
			delete[] stackArray;
	}
	// ReSize()
	// TŸ���� newArray�� �����Ҵ�
	// stackArray �ε��� 0���� top������ �����͸� newArray �����Ѵ�.
	// ���� stackArray delete[] ���ݴϴ�.
	// stackArray newArray�� �����ͷ� ���� �Ҵ��Ѵ�.
	// this.capacity =_capacity;
	void Resize(int newCapacity)
	{
		T* newArray = new T[newCapacity];
		for (int i = 0; i < top; i++)
		{
			newArray[i] = stackArray[i];
		}
		delete[] stackArray;
				
		stackArray = newArray;
		capacity = newCapacity;
	}

	// IsFull()
	// top == capacity -1 
	bool IsFull() { return top == capacity - 1 ? true : false; }

	// IsEmpty()
	// top�� ����Ű�� �ִ� �༮�� "-1" true,false
	bool IsEmpty() { return top <= -1 ? true : false; }

	// push()
	// ���࿡ Full�̶�� Resize(capacity*2)
	// stackArray ������ �߰� [top] <- ������ �߰�
	// top �� 1 ���� �����ش�.

	void Push(T data)
	{
		if (IsFull())
		{
			Resize(capacity * 2);
		}

		top++;
		stackArray[top] = data;
	}

	// pop()
	// isEmpty() -> ������ ���ÿ� �����Ͱ� ������ϴ�. ���
	// return
	// top --1
	void Pop()
	{
		if (IsEmpty())
		{
			std::cout << "���� ���ÿ� �����Ͱ� �����ϴ�. Stack is UnderFlow, ������ ����� �� �� �����ϴ�." << std::endl;
			return;
		}
		
		std::cout << Top() << std::endl;
		--top;

	}
	T Top() const
	{
		return stackArray[top];
	}
	
	void Clear()
	{
		capacity = 0;
		top = -1;
	}

};

// ������ ����Ʈ ��� Stack

// StackNode next

// StackNode* pHead

// push -> �Ӹ��� ����� �Ӹ��� �� ���� �Ӹ��� ����Ű�� �����

// pop -> �Ӹ��� ����Ű�� �ִ����� �Ӹ��� �����

template <typename T>
class LinkedStack
{
private:
	struct StackNode
	{
		T data;
		StackNode* next;
	};
};


void StackExample()
{
	MyArrayStack<int> mStack;
	mStack.Push(1);
	mStack.Push(2);
	mStack.Push(3);
	mStack.Push(4);
	mStack.Pop();
	mStack.Pop();
	mStack.Pop();
	mStack.Pop();

	

	
}

