#pragma once

#include <iostream>
#include <string>

using namespace std;

// 이중 연결 리스트
// 단일 연결 리스트의 기능 확장된 버전. Node : value, next, perv
// 장점 : 원소의 값을 찾기가 더 쉬워졌다.
// 단점 : 메모리 공간을 좀 더 사용한다.

// 문자열을 저장하는 노드

struct StringNode
{
	string value;
	StringNode* pNext;
	StringNode* pPrev;
};

class DoubliyLinkedList
{
private:
	StringNode* pHead;
	StringNode* pTail;
	int iCount;

public:
	DoubliyLinkedList() {}
	~DoubliyLinkedList() {}

	// 입력 기능
	void PushFront(const string _data);
	void PushBack(const string _data);
	void Insert(int index,const string _data);

	// 출력 기능
	string FrontValue() { return pHead->value; };
	string BackValue() { return pTail->value; };
	void Print(); // 첫번째 데이터 -> 마지막 데이터 출력

	void RemoveFront();
	void RemoveBack();
	void RemoveAt();


};
