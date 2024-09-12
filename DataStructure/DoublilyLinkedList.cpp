#include "DoublilyLinkedList.h"

void DoubliyLinkedList::PushFront(const string _data)
{
	StringNode* newNode = new StringNode;
	newNode->value = _data;
	newNode->pNext = nullptr;
	newNode->pPrev = nullptr;

	if (nullptr == pHead)
	{
		pHead = newNode;
		pTail = newNode;
	}
			
	newNode->pPrev = nullptr; // 새로운 노드의 prev는 비어있어야한다.
	newNode->pNext = pHead; // 새로운 노드의 next는 기존의 head이여야한다.
	pHead->pPrev = newNode;
	pHead = newNode;

	iCount++;
}

void DoubliyLinkedList::PushBack(const string _data)
{
	StringNode* newNode = new StringNode;
	newNode->value = _data;
	newNode->pNext = nullptr;
	newNode->pPrev = nullptr;

	if (nullptr == pHead)
	{
		pHead = newNode;
		pTail = newNode;
	}

	newNode->pPrev = pTail; // 새로운 노드의 next는 비어있어야한다.
	newNode->pNext = nullptr; // 새로운 노드의 prev는 기존의 tail이여야한다.
	pTail->pNext = newNode;
	pTail = newNode;

	iCount++;
}

void DoubliyLinkedList::Insert(int index, const string _data)
{
	// index 0 (PushFront 함수 실행)
	// index iCount-1 (PushBack 함수 실행)
	// Node -> NewNode -> Node // 01234
	if (index < 0 || iCount <= index)
	{
		cout << "인덱스 에러 발생!" << endl;
		return;
	}
	else if (index == 0)
		PushFront(_data);
	else if (index == iCount)
		PushBack(_data);
	else
	{
		// 인덱스 횟수 만큼 이동한 뒤에 그자리에 만들기
		StringNode* newNode = new StringNode;
		newNode->value = _data;
		newNode->pNext = nullptr;
		newNode->pPrev = nullptr;
		
		StringNode* CurrentNode = pHead;

		int i = 0;

		while (i < index - 1)
		{
			CurrentNode = CurrentNode->pNext;
			i++;
		}

		newNode->pPrev = CurrentNode; // 새 노드의 이전 : 기존 노드
		newNode->pNext = CurrentNode->pNext; // 새 노드의 이후 : 기존 노드의 next

		CurrentNode->pNext->pPrev = newNode;
		CurrentNode->pNext = newNode;
		
		iCount++;
	}



}

void DoubliyLinkedList::Print()
{
	StringNode* printNode = pHead;

	while (printNode != nullptr);
	{
		// printNode 마지막일 때는 printNode -> value
		if (nullptr == printNode->pNext) // printNode->next nullptr
		{
			cout << printNode->value << endl;
		}
		else
		{
			cout << printNode->value << " " << "<->" << " ";

		}
		printNode = printNode->pNext;
		
	}
}

void DoubliyLinkedList::RemoveFront()
{
	if (pHead != nullptr)
	{
		StringNode* remove = pHead;

		// pHead -> next null이면 1개만 존재

		if (nullptr == remove->pNext)
		{
			pHead = pTail = nullptr;
		}
		else
		{
			pHead = pHead->pNext;
			pHead->pPrev = nullptr;
			delete remove;
		}
		iCount--;
	}
}

void DoubliyLinkedList::RemoveBack()
{
}

void DoubliyLinkedList::RemoveAt()
{
}
