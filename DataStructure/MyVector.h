#pragma once

#include <iostream>
#include <string>

// 배열 : 크기가 고정되어 있었다.
// ADT
// 배열의 길이를 바꿀 수 있는 클래스로 만들어 보자
// 배열의 전체 길이 : capacity
// 현재 배열의 담긴 원소 수 : size
// push_back() => size++; 조건 : capacity <= size -> 최대 용량을 늘려준다.(알고리즘)


template <typename T>
class Myvector
{
private:
	T* vec;   // 원소를 담을 시작 주소
	int size;   // vec에 현재 담겨 있는 크기
	int capacity;  // 최대로 담을 수 있는 크기

public:
	// 생성자
	Myvector(int temp = 10) // 클래스를 생성할 때 int 값을 인자로 넘겨주지 않으면 10크기가 자동으로 할당된다.
	{
		vec = new T[temp];
		size = 0;
		capacity = temp;
	}
	~Myvector()
	{
		delete[] vec;
	}

	// 연산자 오버로딩 [], ==, !=

	T& operator[](int index) // 배열의 index에 접근하는 기능 구현
	{
		return vec[index];
	}

	bool operator==(Myvector& other)
	{
		// 현재 자료구조의 원소 갯수, other 원소 갯수 비교
		if (size != other.size)  // 다르면 false를 리턴
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

	// 원소 추가 삭제
	
	// 새롭게 배열을 할당하는 작업이 적을 수록 시간이 적게 걸린다.

	void ResizeVector(int newSize) // 배열의 크기가 증가하는 case만 Resize해준다.
	{
		// 동적 할당 : new 키워드 capacity 크기 만큼 T타입의 데이터 배열을 만든다.

		T* newVec = new T[newSize];

		// 새로 만든 배열에 기존배열을 대입한다.

		for (int i = 0; i < size; i++)
		{
			newVec[i] = vec[i];
		}
		delete[] vec;
		vec = newVec;
	}

	void push_back(T data)
	{
		// size >= capacity // vec[10] 인데 size가 11이 되면
		// 최대 수용량 <= 원소의 크기
		if (capacity <= size)
		{
			capacity * 2;// 최대 수용량을 2배로 늘린다.
			ResizeVector(capacity);       // 기존 배열 -> 새로 만든 배열 옮기는 작업
		}

		// vec[0] ~ vec[size] = data;
		vec[size] = data;
		size++;
	}

	void pop_back()
	{
		size = size > 0 ? size - 1 : 0; // 현재 갯수가 0보다 크면 size -1 0보다 작거나 같으면  size = 0
	}

	void Print()
	{
		std::cout << "------------------------------------" << std::endl;
		for (int i = 0; i < size; i++)
		{
			std::cout << i + 1 << "번째 값 출력 : " << vec[i] << std::endl;
		}
		std::cout << "------------------------------------" << std::endl;
	}

	// vec에 직접 접근할 수 있는 GetVector 함수
	T* GetVector() { return vec; }

	int GetSize() { return size; } // 현재 vec의 원소 갯수를 리턴하는 함수
	// 도전 과제 
	// 로비 시스템, Room - Player , Add, Remove 유저가 방에 들어갔다 나왔다.
	// Player - Inventory - ItemSystem

};