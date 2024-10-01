#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm> // swap(a1,a2)

// 자료구조를 이용해서 데이터를 잘 저장하는 방법을 배웠다.
// 자료구조들 안에 있는 데이터를 가장 빠르고, 효율적으로 사용하는 방법을 배워야한다. -> 알고리즘

// Heap
// 특징 : 완전 이진 트리의 형태를 갖고 있다.
// 종료 :
// Max Heap : 우선순위가 높은 데이터(큰 수) 가장 큰 수가 위로 올라가는 형태
// Min Heap : 가장 작은 수가 Root 노드에 존재하는 Heap구조

// Heapify의 규칙
// root의 노드를 pop합니다.
// 가장 마지막에 들어온 노드를 root에 넣어줍니다.
// root의 자식들과 부모랑 비교를 해서 큰 수를 부모와 바꿉니다.
// 최초에 root들어간 녀석이 더 이상 변경되지 않을 때 까지 반복합니다.


// 가장위의 데이터(노드)를 root라고 부르고 root 1개만 존재한다.
// 각 노드들은 자시글 2개까지 가질 수 있습니다.
// 노드들의 level이 가득찰 때까지 자식을 추가하고
// 노드의 자식들을 왼쪽부터 차례대로 채우는 형식 - 완전 이진 트리

// 부모 노드 : (idx -1) / 2
// 자식 노드 :  left : idx * 2 + 1
//             right : idx * 2 + 2 

// 다읨의 내용을 이용해서 아래 코드를 구현해보세요
// 부모 노드 < idx 노드 (새로 들어온 노드) -> 새로들어온 노드 swap = false;
// 

class PriorityQueue
{
private:
	std::vector<int> heap;
		
	void heapifyUp(int idx) // 마지막에 들어온 idx
	{
		// 비교하는 코드를 작성해보세요. 새로들어온 노드, 그 노드의 부모

		while (heap[idx] > heap[(idx - 1) / 2])
		{
			std::swap(heap[idx], heap[(idx - 1) / 2]);
			idx = (idx - 1) / 2;
		}

	}

	// 마지막 원소 : size -1 -> root
	// left, right
	// int largest
	// while, 비교

	void heapifyDown(int idx)
	{
		int size = heap.size();
		while (true)
		{
			int largest = idx;
			int left = idx * 2 + 1;
			int right = idx * 2 + 2;

			if (left<size && heap[largest] < heap[left])
				largest = left;

			if (right<size && heap[largest] < heap[right])
				largest = right;

			if (largest == idx)
				break;

			std::swap(heap[largest], heap[idx]);
			idx = largest;

		}

	}


public:
	void push(int _data)
	{
		heap.push_back(_data);
		heapifyUp(heap.size()-1);
	}

	int pop()
	{
		if (heap.empty())
		{
			throw std::out_of_range("힙이 비어있습니다.");
		}

		int root = heap[0];	// 1. 가장 큰 수를 root에 저장한다.
		heap[0] = heap.back(); // 3. 비어있는 root. 가장 마지막 원소를 대입한다.
		heap.pop_back(); // 4. 가장 마지막 데이터의 공간이 비었다.
		heapifyDown(0); // 5. 힙의 특성에 맞게 재정렬
		return root; // 2. 리턴 시킨다.(최대값을 출력했다.)
	}

	int top() const
	{
		if (heap.empty())
		{
			throw std::out_of_range("힙이 비어있습니다.");
		}
		return heap[0];
	}

	bool empty() const { return heap.empty(); }

	int size() const { return heap.size(); }

};


void PriortyQueueExample()
{
	PriorityQueue p_q;
	p_q.push(1);
	p_q.push(3);
	p_q.push(5);
	p_q.push(7);
	p_q.push(9);

	while (!p_q.empty())
	{
		std::cout << "우선 순위 결과 : " << p_q.pop() << std::endl;
	}

}