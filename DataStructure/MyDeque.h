#pragma once
#include <deque>
#include <iostream>
#include <vector>


/*
*  학습 목표 : Deque에 대해 이해하고 구현한다.
* 
*  Vector와 Deque을 비교해서 설명
* 
*  Vector
*  - 임의의 원소 접근 하는 시간 0(1)
*  - 뒤에서 부터원소를 삽입할 때 효율적이다. 0(1)
*  - 중간에 원소를 삽입 삭제 0(n) - node기반 구현하면 0(1)
* 
*  Deque
*  - 임의의 원소 접근 하는 시간 0(1)
*  - 앞과 뒤에서 부터원소를 삽입할 때 효율적이다. 0(1)
*  - 중간에 원소를 삽입 삭제 0(n) - node기반 구현하면 0(1)
*/



template<typename T>
class MyDeque
{
private:
	std::vector<T*> blocks; // 각 블럭을 저장하는 자료구조, 비연속적인 메모리 관리 방식

	int blockSize; // 블록이 최대로 저장할 수 있는 크기 (커질수록 빨라짐, 용량이 늘어난다.)
	int frontIndex; // 첫번째 블록의 인덱스
	int backIndex; // 마지막 블록의 인덱스
	int iCount; // 현재 Deque 저장된 원소의 개수

	void allocateBlock() // 블록 생성 함수
	{
		blocks.push_back(new T(blockSize)); // new T(blockSize) -> vector<T*>blocks에 push back
	}

	void addFrontBlock() // 앞쪽 블럭 추가
	{
		blocks.insert(blocks.begin(), new T(blockSize));
		frontIndex = blockSize - 1;
	}
	void addBackBlock() // 뒤쪽 블럭 추가
	{
		blocks.push_back(new T[blockSize]);
		backIndex = 0;
	}

public:
	// 생성자 & 소멸자
	MyDeque(int blockSize = 4) :blockSize(blockSize), frontIndex(0), backIndex(0), iCount(0)
	{
		allocateBlock();
	}
	~MyDeque()
	{
		for (T* block : blocks)
		{
			delete[] block;
		}
	}

	// Accesor
	int getSize() const { return iCount; }

	bool empty() const { return iCount == 0 ? true : false; }

	T& getFront() const
	{
		if (empty())
		{
			throw std::out_of_range("덱이 비었습니다.");
		}
		return blocks[0][frontIndex + 1];
	}
	T& getBack() const
	{
		if (empty())
		{
			throw std::out_of_range("덱이 비었습니다.");
		}
		return blocks.back()[backIndex - 1];
	}
	// Main Method

	void push_front(const T& data)// int, float, std::string
	{
		if (frontIndex < 0) // ? 
		{
			addFrontBlock();
		}
		blocks[0][frontIndex--] = data;
		iCount++;
	}

	void pushBack(const T& data)
	{
		if (backIndex == blockSize)
		{
			addBackBlock();
		}
		blocks.back()[backIndex++] = data;
		iCount++;
	}
	void popFront()
	{
		if (empty())
		{
			std::cout << "덱이 비었습니다." << std::endl;
			return;
		}
		++frontIndex;
		--iCount;
		if (frontIndex == blockSize)
		{
			delete blocks.front();
			blocks.erase(blocks.begin());
			frontIndex = 0;
		}
	}
	void popBack()
	{
		if (empty())
		{
			std::cout << "덱이 비었습니다." << std::endl;
			return;
		}
		--backIndex;
		--iCount;
		if (backIndex < 0)
		{
			delete[] blocks.back();
			backIndex = blockSize - 1;
		}
	}

};

void IDequeExample()
{
	MyDeque<int> M_Deq;

	M_Deq.push_front(1);
	M_Deq.pushBack(4);
	M_Deq.pushBack(5);

	std::cout << "머리 : " << M_Deq.getFront() << std::endl;
	std::cout << "꼬리 : " << M_Deq.getBack() << std::endl;

	M_Deq.popBack();
	M_Deq.popFront();

	std::cout << "머리 : " << M_Deq.getFront() << std::endl;
	std::cout << "꼬리 : " << M_Deq.getBack() << std::endl;

}