#include "LinkedList.h"

ILinkedList::ILinkedList()
{
}

ILinkedList::~ILinkedList()
{
}

void ILinkedList::PushFront(const int& _data)
{
	IntNode* pNewNode = new IntNode;
	pNewNode->value = _data;
	
	if (nullptr == pHead) // Head�� ����Ű�� �ִ� ������ null ����ִ� �ڷᱸ��.
	{
		// Head �����͸� ���ο� ���� �������ش�.
		pHead = pNewNode;
		pTail = pNewNode;
	}

	pNewNode->pNext = pHead;// ���ο� ����� next �ּҸ� head�� ����Ű���� ������.
	pHead = pNewNode;  // ���� head�� ���ο� ���� �����ض�.

	++iCount; // �ڷᱸ���� ����ִ� �������� �� ����
}

void ILinkedList::PushBack(const int& _data)
{
	IntNode* pNewNode = new IntNode;
	pNewNode->value = _data;

	if (nullptr == pHead)
	{
		pHead = pNewNode;
		pTail = pNewNode;
	}

	pTail->pNext = pNewNode; // ������ ���� �����Ͱ� ���ο� ��尡 �ȴ�.
	pTail = pNewNode; // ������ �����Ͱ� ���ο� ��尡 �ȴ�.
	
		
	++iCount;
}

void ILinkedList::RemoveFront()
{
	if (nullptr == pHead) // bool IsEmpty()
	{
		std::cout << "�����Ͱ� �����ϴ�. ������ ����մϴ�." << std::endl;
		return;
	}

	IntNode* pOldNode = pHead;  // pHead �ӽ� �����͸� �������ش�.

	if(nullptr == pOldNode->pNext)
	{
		pHead = nullptr;
		pTail = nullptr;
	}
	else
	{
		pHead = pHead->pNext;  // pHead -> pNext : head�� �����.
	}
	delete pOldNode;  // oldNode �޸𸮸� �������ش�.
	iCount--;
}

void ILinkedList::RemoveBack()
{
	if (nullptr == pHead) // bool IsEmpty()
	{
		std::cout << "�����Ͱ� �����ϴ�. ������ ����մϴ�." << std::endl;
		return;
	}

	IntNode* pOldNode = pTail;  // pTail �ӽ� �����͸� �������ش�.

	if (nullptr == pOldNode->pNext)
	{
		pHead = nullptr;
		pTail = nullptr;
	}
	else
	{
		 // pTail�� ����Ű�� ���� pTail�� �����.
		// iCount�� ���ؼ� �Ӹ����� �ϳ� �� �Ѿ ���� �տ� �ִ� ���� ������ �����.
	}


	delete pOldNode;  // oldNode �޸𸮸� �������ش�.
	iCount--;

}

void ILinkedList::FrontValue()
{
	std::cout<<"���� �ڷᱸ���� �� ���� : "<<iCount << ", ù��° ������ �� : " << pHead->value << std::endl;
}

void ILinkedList::BackValue()
{
	std::cout << "���� �ڷᱸ���� �� ���� : " << iCount << ", ������ ������ �� : " << pTail->value << std::endl;
}
