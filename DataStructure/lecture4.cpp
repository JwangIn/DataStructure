#include "lectures.h"
#include <iostream>
#include <list>
#include <string>
#include "LinkedList.h"
#include "DoublilyLinkedList.h"

// ���� ������. ����, �߰�  - �κ��丮
//             �迭                    <->          ���� ����Ʈ
// ���� : ������ ���� ������ ������.     <->  ���� : ������ ���� ������ �Ұ����ϴ�.
// ���� : �������� ���� �� �߰��� ������. <->  ���� : ������ ���� �� �߰��� ������.

class Item
{
private:
	int itemCode;
	std::string name;
public:
	Item(int _itemCode, std::string _name ):itemCode(_itemCode),name(_name){}

	void ShowInfo()
	{
		std::cout << "������ �ڵ� : " << itemCode << std::endl;
		std::cout << "������ �̸� : " << name << std::endl;
	}
};

class Pos
{
public:
	int posX;
	int posY;
	char tag;
	Pos(int x, int y, char _tag) : posX(x), posY(y), tag(_tag) {}

};

class Point
{
private:
	Pos data;
	Point* next;
public:
	Point(Pos _data) :data(_data) {}

	void ShowData()
	{
		std::cout << data.tag << " : " << data.posX << " , " << data.posY << std::endl;;
	}
};



void lecture4()
{
	std::cout << "STL : ���� ����Ʈ ���" << std::endl;

	// �����Ҵ� : std::list<int>* iList = new std::list<int>();

	std::list<int> iList; // Ŭ���� ����

	// ������ �տ� ���� pushFront - push_front
	// ������ �ڿ� ���� pushBack - push_back
	// �� ������ ���� removeFront - pop_front
	// �ڿ� ������ ���� removeBack - pop_back

	std::list<Item> inventory;
	
	Item* newItem = new Item(1001,"���");
	Item* newItem2 = new Item(1002, "�Ѽհ�");
	Item* newItem3 = new Item(1003, "�ظ�");

	inventory.push_front(*newItem);
	inventory.push_back(*newItem2);
	inventory.push_back(*newItem3);

	
	
	// Ư�� index�� ���� �ִ� insert
	
	// iterator : �����͸� �Ϲ�ȭ��Ų Ŭ����

	std::list<Item>::iterator iterEnd = inventory.end();

	for (std::list<Item>::iterator iterPos = inventory.begin(); iterPos != iterEnd;++iterPos)
	{
		iterPos->ShowInfo();

	}
	


	// Ŭ���� ����

	// list, LinkedList.h - int, DoubliyLinkedList.h - string

	// LinkedList<int> iList1;
	// std::list<int> iList2;

	// DoubliyLinkedList dList1;
	// DoubliyLinkedList dList2;

	ILinkedList iList1;
	iList1.PushFront(2);
	iList1.FrontValue();

	std::list<int> iList2;

	// ���� ����
	
	// ������ Ŭ������ ���Ǹ� �մϴ�.
	// A(50,200) B(20,80) C(75,10) D(130,80) E(100,200)
	// Class Pos{posX, posY}
	// pos�� value�� ������ node�� ������


	

	Pos A = Pos(50, 200, 'A');
	Pos B = Pos(20, 80, 'B');
	Pos C = Pos(75, 10, 'C');
	Pos D = Pos(130, 80, 'D');
	Pos E = Pos(100, 200, 'E');

	// (1)
	std::list<Point> Star;

	Star.push_back(A);
	Star.push_back(B);
	Star.push_back(C);
	Star.push_back(D);
	Star.push_back(E);

	std::list<Point>::iterator iterEnd2 = Star.end();

	for (std::list<Point>::iterator iterPos = Star.begin(); iterPos != iterEnd2; ++iterPos)
	{
		iterPos->ShowData();
	}

	

	// (2)
	Point A_P = Point(A);
	Point B_P = Point(B);
	Point C_P = Point(C);
	Point D_P = Point(D);
	Point E_P = Point(E);



}


