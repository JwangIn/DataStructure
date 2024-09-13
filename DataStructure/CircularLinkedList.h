#pragma once

// 단일 연결 리스트 일치합니다.
// tail의 next - nullptr;
// 원형 연결 리스트 : 꼬리의 next -> head

// 이중 연결 리스트
// 노드가 앞과 뒤
// 이중 원형 연결 리스트

// 원형 리스트의 사용 장점
// Head를 따로 지정하지 않아도 된다. - 모든 노드가 시작점이 될 수 있다.

// 단일 연결 리스트의 head : head->prev :nullptr;. 노드의 자료구조에서 처음 입력하는 데이터
// 원형 연결 리스트 시작점 : 0, 1, 2, 3, 4, 5
// 원형 연결 리스트의 마지막을 파악하는 함수 : 처음 시작점 head 자료구조를 생성할 때 저장을 해준다. 시작점과 똑같은 노드가 들어올 때 : 한바퀴를 돌았다.

struct cNode
{
	int value;
	cNode* next;
};

class CircularLinkedList
{
private:
	cNode* pHead; // 시작점
	int iCount;
public:
	int IsEnd()
	{
		cNode* cur = pHead;
		int iCount = 0;
		while (true)
		{
			iCount++;
			cur = cur->next;

			if (cur == pHead)
			{
				return true;
			}
		}
		return iCount;
	}
};