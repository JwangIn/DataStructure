#include "lectures.h"
#include "DoublilyLinkedList.h"

void lecture3()
{
	DoubliyLinkedList dList;
	dList.PushFront("����1");
	dList.PushBack("����2");
	dList.PushBack("����3");
	dList.PushBack("����4");
	dList.Insert(3, "��� �ڸ�");
	cout << dList.FrontValue() << endl;
	cout << dList.BackValue() << endl;
	dList.Print();

}