#include "lectures.h"
#include "DoublilyLinkedList.h"

void lecture3()
{
	DoubliyLinkedList dList;
	dList.PushFront("문자1");
	dList.PushBack("문자2");
	dList.PushBack("문자3");
	dList.PushBack("문자4");
	dList.Insert(3, "가운데 자리");
	cout << dList.FrontValue() << endl;
	cout << dList.BackValue() << endl;
	dList.Print();

}