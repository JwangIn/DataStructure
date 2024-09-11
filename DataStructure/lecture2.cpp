#include "lectures.h"
#include "LinkedList.h"

void lecture2()
{
	ILinkedList iList;

	iList.PushFront(10);
	iList.FrontValue();
	iList.PushFront(5);
	iList.FrontValue();
	iList.RemoveFront();
	iList.PushBack(2);
	iList.BackValue();


}