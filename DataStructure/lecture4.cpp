#include "lectures.h"
#include <iostream>
#include <list>
#include <string>
#include "LinkedList.h"
#include "DoublilyLinkedList.h"

// 게임 아이템. 삭제, 추가  - 인벤토리
//             배열                    <->          연결 리스트
// 장점 : 임의의 원소 접근이 빠르다.     <->  단점 : 임의의 원소 접근이 불가능하다.
// 단점 : 데이터의 삭제 및 추가가 느리다. <->  장점 : 데이터 삭제 및 추가가 빠르다.

class Item
{
private:
	int itemCode;
	std::string name;
public:
	Item(int _itemCode, std::string _name ):itemCode(_itemCode),name(_name){}

	void ShowInfo()
	{
		std::cout << "아이템 코드 : " << itemCode << std::endl;
		std::cout << "아이템 이름 : " << name << std::endl;
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
	std::cout << "STL : 연결 리스트 사용" << std::endl;

	// 동적할당 : std::list<int>* iList = new std::list<int>();

	std::list<int> iList; // 클래스 생성

	// 데이터 앞에 저장 pushFront - push_front
	// 데이터 뒤에 저장 pushBack - push_back
	// 앞 데이터 삭제 removeFront - pop_front
	// 뒤에 데이터 삭제 removeBack - pop_back

	std::list<Item> inventory;
	
	Item* newItem = new Item(1001,"대검");
	Item* newItem2 = new Item(1002, "한손검");
	Item* newItem3 = new Item(1003, "해머");

	inventory.push_front(*newItem);
	inventory.push_back(*newItem2);
	inventory.push_back(*newItem3);

	
	
	// 특정 index에 값을 넣는 insert
	
	// iterator : 포인터를 일반화시킨 클래스

	std::list<Item>::iterator iterEnd = inventory.end();

	for (std::list<Item>::iterator iterPos = inventory.begin(); iterPos != iterEnd;++iterPos)
	{
		iterPos->ShowInfo();

	}
	


	// 클래스 구현

	// list, LinkedList.h - int, DoubliyLinkedList.h - string

	// LinkedList<int> iList1;
	// std::list<int> iList2;

	// DoubliyLinkedList dList1;
	// DoubliyLinkedList dList2;

	ILinkedList iList1;
	iList1.PushFront(2);
	iList1.FrontValue();

	std::list<int> iList2;

	// 예제 문제
	
	// 도형을 클래스로 정의를 합니다.
	// A(50,200) B(20,80) C(75,10) D(130,80) E(100,200)
	// Class Pos{posX, posY}
	// pos를 value로 가지는 node로 재정의


	

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


