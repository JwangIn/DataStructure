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
	
	if (nullptr == pHead) // Head가 가리키고 있는 포인터 null 비어있는 자료구조.
	{
		// Head 포인터를 새로운 노드로 변경해준다.
		pHead = pNewNode;
		pTail = pNewNode;
	}

	pNewNode->pNext = pHead;// 새로운 노드의 next 주소를 head를 가리키도록 만들어라.
	pHead = pNewNode;  // 기존 head를 새로운 노드로 변경해라.

	++iCount; // 자료구조에 들어있는 데이터의 총 갯수
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

	pTail->pNext = pNewNode; // 꼬리의 다음 포인터가 새로운 노드가 된다.
	pTail = pNewNode; // 꼬리의 포인터가 새로운 노드가 된다.
	
		
	++iCount;
}

void ILinkedList::RemoveFront()
{
	if (nullptr == pHead) // bool IsEmpty()
	{
		std::cout << "데이터가 없습니다. 실행을 취소합니다." << std::endl;
		return;
	}

	IntNode* pOldNode = pHead;  // pHead 임시 데이터를 생성해준다.

	if(nullptr == pOldNode->pNext)
	{
		pHead = nullptr;
		pTail = nullptr;
	}
	else
	{
		pHead = pHead->pNext;  // pHead -> pNext : head로 만든다.
	}
	delete pOldNode;  // oldNode 메모리를 해제해준다.
	iCount--;
}

void ILinkedList::RemoveBack()
{
	if (nullptr == pHead) // bool IsEmpty()
	{
		std::cout << "데이터가 없습니다. 실행을 취소합니다." << std::endl;
		return;
	}

	IntNode* pOldNode = pTail;  // pTail 임시 데이터를 생성해준다.

	if (nullptr == pOldNode->pNext)
	{
		pHead = nullptr;
		pTail = nullptr;
	}
	else
	{
		 // pTail을 가리키던 것을 pTail로 만든다.
		// iCount를 통해서 머리부터 하나 씩 넘어서 꼬리 앞에 있는 것을 꼬리로 만든다.
	}


	delete pOldNode;  // oldNode 메모리를 해제해준다.
	iCount--;

}

void ILinkedList::FrontValue()
{
	std::cout<<"현재 자료구조의 총 갯수 : "<<iCount << ", 첫번째 원소의 값 : " << pHead->value << std::endl;
}

void ILinkedList::BackValue()
{
	std::cout << "현재 자료구조의 총 갯수 : " << iCount << ", 마지막 원소의 값 : " << pTail->value << std::endl;
}
