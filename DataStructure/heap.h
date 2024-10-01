#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm> // swap(a1,a2)

// �ڷᱸ���� �̿��ؼ� �����͸� �� �����ϴ� ����� �����.
// �ڷᱸ���� �ȿ� �ִ� �����͸� ���� ������, ȿ�������� ����ϴ� ����� ������Ѵ�. -> �˰���

// Heap
// Ư¡ : ���� ���� Ʈ���� ���¸� ���� �ִ�.
// ���� :
// Max Heap : �켱������ ���� ������(ū ��) ���� ū ���� ���� �ö󰡴� ����
// Min Heap : ���� ���� ���� Root ��忡 �����ϴ� Heap����

// Heapify�� ��Ģ
// root�� ��带 pop�մϴ�.
// ���� �������� ���� ��带 root�� �־��ݴϴ�.
// root�� �ڽĵ�� �θ�� �񱳸� �ؼ� ū ���� �θ�� �ٲߴϴ�.
// ���ʿ� root�� �༮�� �� �̻� ������� ���� �� ���� �ݺ��մϴ�.


// �������� ������(���)�� root��� �θ��� root 1���� �����Ѵ�.
// �� ������ �ڽñ� 2������ ���� �� �ֽ��ϴ�.
// ������ level�� ������ ������ �ڽ��� �߰��ϰ�
// ����� �ڽĵ��� ���ʺ��� ���ʴ�� ä��� ���� - ���� ���� Ʈ��

// �θ� ��� : (idx -1) / 2
// �ڽ� ��� :  left : idx * 2 + 1
//             right : idx * 2 + 2 

// ������ ������ �̿��ؼ� �Ʒ� �ڵ带 �����غ�����
// �θ� ��� < idx ��� (���� ���� ���) -> ���ε��� ��� swap = false;
// 

class PriorityQueue
{
private:
	std::vector<int> heap;
		
	void heapifyUp(int idx) // �������� ���� idx
	{
		// ���ϴ� �ڵ带 �ۼ��غ�����. ���ε��� ���, �� ����� �θ�

		while (heap[idx] > heap[(idx - 1) / 2])
		{
			std::swap(heap[idx], heap[(idx - 1) / 2]);
			idx = (idx - 1) / 2;
		}

	}

	// ������ ���� : size -1 -> root
	// left, right
	// int largest
	// while, ��

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
			throw std::out_of_range("���� ����ֽ��ϴ�.");
		}

		int root = heap[0];	// 1. ���� ū ���� root�� �����Ѵ�.
		heap[0] = heap.back(); // 3. ����ִ� root. ���� ������ ���Ҹ� �����Ѵ�.
		heap.pop_back(); // 4. ���� ������ �������� ������ �����.
		heapifyDown(0); // 5. ���� Ư���� �°� ������
		return root; // 2. ���� ��Ų��.(�ִ밪�� ����ߴ�.)
	}

	int top() const
	{
		if (heap.empty())
		{
			throw std::out_of_range("���� ����ֽ��ϴ�.");
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
		std::cout << "�켱 ���� ��� : " << p_q.pop() << std::endl;
	}

}