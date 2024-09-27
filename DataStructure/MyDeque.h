#pragma once
#include <deque>
#include <iostream>
#include <vector>


/*
*  �н� ��ǥ : Deque�� ���� �����ϰ� �����Ѵ�.
* 
*  Vector�� Deque�� ���ؼ� ����
* 
*  Vector
*  - ������ ���� ���� �ϴ� �ð� 0(1)
*  - �ڿ��� ���Ϳ��Ҹ� ������ �� ȿ�����̴�. 0(1)
*  - �߰��� ���Ҹ� ���� ���� 0(n) - node��� �����ϸ� 0(1)
* 
*  Deque
*  - ������ ���� ���� �ϴ� �ð� 0(1)
*  - �հ� �ڿ��� ���Ϳ��Ҹ� ������ �� ȿ�����̴�. 0(1)
*  - �߰��� ���Ҹ� ���� ���� 0(n) - node��� �����ϸ� 0(1)
*/



template<typename T>
class MyDeque
{
private:
	std::vector<T*> blocks; // �� ���� �����ϴ� �ڷᱸ��, �񿬼����� �޸� ���� ���

	int blockSize; // ����� �ִ�� ������ �� �ִ� ũ�� (Ŀ������ ������, �뷮�� �þ��.)
	int frontIndex; // ù��° ����� �ε���
	int backIndex; // ������ ����� �ε���
	int iCount; // ���� Deque ����� ������ ����

	void allocateBlock() // ��� ���� �Լ�
	{
		blocks.push_back(new T(blockSize)); // new T(blockSize) -> vector<T*>blocks�� push back
	}

	void addFrontBlock() // ���� �� �߰�
	{
		blocks.insert(blocks.begin(), new T(blockSize));
		frontIndex = blockSize - 1;
	}
	void addBackBlock() // ���� �� �߰�
	{
		blocks.push_back(new T[blockSize]);
		backIndex = 0;
	}

public:
	// ������ & �Ҹ���
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
			throw std::out_of_range("���� ������ϴ�.");
		}
		return blocks[0][frontIndex + 1];
	}
	T& getBack() const
	{
		if (empty())
		{
			throw std::out_of_range("���� ������ϴ�.");
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
			std::cout << "���� ������ϴ�." << std::endl;
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
			std::cout << "���� ������ϴ�." << std::endl;
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

	std::cout << "�Ӹ� : " << M_Deq.getFront() << std::endl;
	std::cout << "���� : " << M_Deq.getBack() << std::endl;

	M_Deq.popBack();
	M_Deq.popFront();

	std::cout << "�Ӹ� : " << M_Deq.getFront() << std::endl;
	std::cout << "���� : " << M_Deq.getBack() << std::endl;

}