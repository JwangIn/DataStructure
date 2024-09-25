#pragma once
#include <iostream>
#include <queue>

/*
*  자료 구조 : 컨테이너를 변형해서 순서를 정해두고 사용하는 어뎁터 자료구조이다.
*  자료구조에 데이터를 저장할 때 먼저 들어간 자료가 먼저 나오는 형태의 자료구조
*  예시) 대기표를 끊어야 한다. 사람들이 줄을 선다. 먼저 온 사람을 먼저 처리한다. 마지막에 온 사람은 마지막에 처리한다.
* 
*  큐 자료구조 구현.
*  - 데이터가 출력되는 인덱스를 front이름으로 표현
*  - 데이터가 저장되는 인덱스를 rear 이름으로 표현
*  - 선형 큐 front rear 초기값으로 되돌아갈 수 없다.
*/

// 구현해야 할 함수
// 입력 및 삭제 : push, pop
// 필드 값 표현 : empty(), size(), front(), back()

template <typename T>
class ArrayBasedQueue
{
private:
	T* queue; // 데이터를 저장하기 위한 배열
	int front; // 출력위치를 가리키는 인덱스
	int rear; // 데이터 입력 위치를 가리키는 인덱스
	int iCount; // 현재 자룍조의 원소의 갯수
public:
	//생성자
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
		// queue 배열 data 삽입
		// rear 변경시킨다.
		// 개수도 증가시킨다.
		queue[rear] = data;
		rear++;
		iCount++;
	}
	void Pop()
	{
		// queue 비어있지 않을때
		// queue 배열 front 변경시켜준다.
		// 개수도 감소 시켜준다.
		if(iCount != 0)
		{
			front++;
			iCount--;
		}
		else
		{
			std::cout<<"큐가 비었습니다."<<std::endl;
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
			rear->pNext = newNode; // 마지막 포인터의 다음 포인터에 새로 할당한 노드를 넣어준다.
			rear = newNode; // 새로운 노드르 rear로 재지정해준다.
		}
		iCount++;
	}
	void Pop()
	{
		if (Empty())
		{
			std::cout << "큐가 비었습니다." << std::endl;
			return;
		}
		QueueNode* oldNode = front; //삭제할 노드를 복사한다.
		front = front->pNext; // 기존의 front노드의 다음 노드를 front로 변경한다.
		delete oldNode;
		iCount--;
	}
};








void iQueueExample()
{
	std::queue<int> n_q;
	
	// 큐를 이용해서 1,2,3,4,5를 출력해보세요

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

// 선형 큐의 단점 : front, rear가 계속 증가하고, 재활용이 힘들다.
// 이름 개선하기위한 원형 큐를 만들어 볼 수 있다.