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
			
	newNode->pPrev = nullptr; // ���ο� ����� prev�� ����־���Ѵ�.
	newNode->pNext = pHead; // ���ο� ����� next�� ������ head�̿����Ѵ�.
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

	newNode->pPrev = pTail; // ���ο� ����� next�� ����־���Ѵ�.
	newNode->pNext = nullptr; // ���ο� ����� prev�� ������ tail�̿����Ѵ�.
	pTail->pNext = newNode;
	pTail = newNode;

	iCount++;
}

void DoubliyLinkedList::Insert(int index, const string _data)
{
	// index 0 (PushFront �Լ� ����)
	// index iCount-1 (PushBack �Լ� ����)
	// Node -> NewNode -> Node // 01234
	if (index < 0 || iCount <= index)
	{
		cout << "�ε��� ���� �߻�!" << endl;
		return;
	}
	else if (index == 0)
		PushFront(_data);
	else if (index == iCount)
		PushBack(_data);
	else
	{
		// �ε��� Ƚ�� ��ŭ �̵��� �ڿ� ���ڸ��� �����
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

		newNode->pPrev = CurrentNode; // �� ����� ���� : ���� ���
		newNode->pNext = CurrentNode->pNext; // �� ����� ���� : ���� ����� next

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
		// printNode �������� ���� printNode -> value
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

		// pHead -> next null�̸� 1���� ����

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
