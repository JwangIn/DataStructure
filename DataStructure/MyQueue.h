#pragma once
#include <iostream>
#include <queue>

/*
*  �ڷ� ���� : �����̳ʸ� �����ؼ� ������ ���صΰ� ����ϴ� ��� �ڷᱸ���̴�.
*  �ڷᱸ���� �����͸� ������ �� ���� �� �ڷᰡ ���� ������ ������ �ڷᱸ��
*  ����) ���ǥ�� ����� �Ѵ�. ������� ���� ����. ���� �� ����� ���� ó���Ѵ�. �������� �� ����� �������� ó���Ѵ�.
* 
*  ť �ڷᱸ�� ����.
*  - �����Ͱ� ��µǴ� �ε����� front�̸����� ǥ��
*  - �����Ͱ� ����Ǵ� �ε����� rear �̸����� ǥ��
*  - ���� ť front rear �ʱⰪ���� �ǵ��ư� �� ����.
*/

// �����ؾ� �� �Լ�
// �Է� �� ���� : push, pop
// �ʵ� �� ǥ�� : empty(), size(), front(), back()

template <typename T>
class ArrayBasedQueue
{
private:
	T* queue; // �����͸� �����ϱ� ���� �迭
	int front; // �����ġ�� ����Ű�� �ε���
	int rear; // ������ �Է� ��ġ�� ����Ű�� �ε���
	int iCount; // ���� �ڏ����� ������ ����
public:
	//������
	ArrayBasedQueue(int size = 10)
	{
		queue = new T[size];
		front = 0;
		rear = 0;
		iCount = 0;
	}
	~ArrayBasedQueue()
	{
		delete[] queue;
	}
	int Size()
	{
		return iCount;
	}
	T Front()
	{
		return queue[front];
	}
	T Back()
	{
		return queue[rear-1];
	}
	bool Empty()
	{
		return (iCount == 0) ? true : false;
	}

	void Push(T data)
	{
		// queue �迭 data ����
		// rear �����Ų��.
		// ������ ������Ų��.
		queue[rear] = data;
		rear++;
		iCount++;
	}
	void Pop()
	{
		// queue ������� ������
		// queue �迭 front ��������ش�.
		// ������ ���� �����ش�.
		if(iCount != 0)
		{
			front++;
			iCount--;
		}
		else
		{
			std::cout<<"ť�� ������ϴ�."<<std::endl;
		}
	}
	void Print()
	{
		std::cout << "Front Index : " << front << std::endl;
		std::cout << "Rear Index : " << rear << std::endl;
		std::cout << "Queue Count : " << iCount << std::endl;
	}

};

template<typename T>
class LinkedQueue
{
private:
	struct QueueNode
	{
		T data;
		QueueNode* pNext;

		QueueNode(T _data, QueueNode* pNode)
		{
			data = _data;
			pNext = pNode;
		}
	};
	QueueNode* front;
	QueueNode* rear;
	int iCount;
public:
	LinkedQueue()
	{
		front = nullptr;
		rear = nullptr;
		iCount = 0;
	}
	~LinkedQueue(){}
	T Front()
	{
		return front->data;
	}
	T Back()
	{
		return rear->data;
	}
	int Size()
	{
		return iCount;
	}
	bool Empty()
	{
		return iCount == 0 ? true : false;
	}

	void Push(T data)
	{
		QueueNode* newNode = new QueueNode(data,nullptr);
		if (Empty())
		{
			front = newNode;
			rear = newNode;
		}
		else
		{
			rear->pNext = newNode; // ������ �������� ���� �����Ϳ� ���� �Ҵ��� ��带 �־��ش�.
			rear = newNode; // ���ο� ��帣 rear�� ���������ش�.
		}
		iCount++;
	}
	void Pop()
	{
		if (Empty())
		{
			std::cout << "ť�� ������ϴ�." << std::endl;
			return;
		}
		QueueNode* oldNode = front; //������ ��带 �����Ѵ�.
		front = front->pNext; // ������ front����� ���� ��带 front�� �����Ѵ�.
		delete oldNode;
		iCount--;
	}
};








void iQueueExample()
{
	std::queue<int> n_q;
	
	// ť�� �̿��ؼ� 1,2,3,4,5�� ����غ�����

	n_q.push(1);
	n_q.push(2);
	n_q.push(3);
	n_q.push(4);
	n_q.push(5);
	
	std::cout << n_q.front() << std::endl;
	n_q.pop();
	std::cout << n_q.front() << std::endl;
	n_q.pop();
	std::cout << n_q.front() << std::endl;
	n_q.pop();
	std::cout << n_q.front() << std::endl;
	n_q.pop();
	std::cout << n_q.front() << std::endl;
	n_q.pop();

	ArrayBasedQueue<int> mque;

	mque.Push(1);
	mque.Push(2);
	mque.Push(3);

	std::cout << mque.Front() << std::endl;
	mque.Pop();
	std::cout << mque.Front() << std::endl;
	mque.Pop();
	std::cout << mque.Front() << std::endl;
	mque.Pop();
	mque.Print();

	LinkedQueue<int> lque;

	lque.Push(1);
	lque.Push(2);
	lque.Push(3);

	std::cout << lque.Front() << std::endl;
	lque.Pop();
	std::cout << lque.Front() << std::endl;
	lque.Pop();
	std::cout << lque.Front() << std::endl;
	lque.Pop();
}

// ���� ť�� ���� : front, rear�� ��� �����ϰ�, ��Ȱ���� �����.
// �̸� �����ϱ����� ���� ť�� ����� �� �� �ִ�.