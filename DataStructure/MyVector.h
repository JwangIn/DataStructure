#pragma once

#include <iostream>
#include <string>

// �迭 : ũ�Ⱑ �����Ǿ� �־���.
// ADT
// �迭�� ���̸� �ٲ� �� �ִ� Ŭ������ ����� ����
// �迭�� ��ü ���� : capacity
// ���� �迭�� ��� ���� �� : size
// push_back() => size++; ���� : capacity <= size -> �ִ� �뷮�� �÷��ش�.(�˰���)


template <typename T>
class Myvector
{
private:
	T* vec;   // ���Ҹ� ���� ���� �ּ�
	int size;   // vec�� ���� ��� �ִ� ũ��
	int capacity;  // �ִ�� ���� �� �ִ� ũ��

public:
	// ������
	Myvector(int temp = 10) // Ŭ������ ������ �� int ���� ���ڷ� �Ѱ����� ������ 10ũ�Ⱑ �ڵ����� �Ҵ�ȴ�.
	{
		vec = new T[temp];
		size = 0;
		capacity = temp;
	}
	~Myvector()
	{
		delete[] vec;
	}

	// ������ �����ε� [], ==, !=

	T& operator[](int index) // �迭�� index�� �����ϴ� ��� ����
	{
		return vec[index];
	}

	bool operator==(Myvector& other)
	{
		// ���� �ڷᱸ���� ���� ����, other ���� ���� ��
		if (size != other.size)  // �ٸ��� false�� ����
			return false;
		
		if (capacity != other.capacity)
			return false;

		for (int i = 0; i < size; i++)
		{
			if (vec[i] != other[i])
				return false;
		}

		return true;

	}

	bool operator!=(Myvector& other)
	{
		return !(*this == other);

	}

	// ���� �߰� ����
	
	// ���Ӱ� �迭�� �Ҵ��ϴ� �۾��� ���� ���� �ð��� ���� �ɸ���.

	void ResizeVector(int newSize) // �迭�� ũ�Ⱑ �����ϴ� case�� Resize���ش�.
	{
		// ���� �Ҵ� : new Ű���� capacity ũ�� ��ŭ TŸ���� ������ �迭�� �����.

		T* newVec = new T[newSize];

		// ���� ���� �迭�� �����迭�� �����Ѵ�.

		for (int i = 0; i < size; i++)
		{
			newVec[i] = vec[i];
		}
		delete[] vec;
		vec = newVec;
	}

	void push_back(T data)
	{
		// size >= capacity // vec[10] �ε� size�� 11�� �Ǹ�
		// �ִ� ���뷮 <= ������ ũ��
		if (capacity <= size)
		{
			capacity * 2;// �ִ� ���뷮�� 2��� �ø���.
			ResizeVector(capacity);       // ���� �迭 -> ���� ���� �迭 �ű�� �۾�
		}

		// vec[0] ~ vec[size] = data;
		vec[size] = data;
		size++;
	}

	void pop_back()
	{
		size = size > 0 ? size - 1 : 0; // ���� ������ 0���� ũ�� size -1 0���� �۰ų� ������  size = 0
	}

	void Print()
	{
		std::cout << "------------------------------------" << std::endl;
		for (int i = 0; i < size; i++)
		{
			std::cout << i + 1 << "��° �� ��� : " << vec[i] << std::endl;
		}
		std::cout << "------------------------------------" << std::endl;
	}

	// vec�� ���� ������ �� �ִ� GetVector �Լ�
	T* GetVector() { return vec; }

	int GetSize() { return size; } // ���� vec�� ���� ������ �����ϴ� �Լ�
	// ���� ���� 
	// �κ� �ý���, Room - Player , Add, Remove ������ �濡 ���� ���Դ�.
	// Player - Inventory - ItemSystem

};