#pragma once

#include <iostream>
#include <vector>

// 포인터의 사용법 

// int abc = 10;
// int* intptr = &abc;
// *, ++,  == , !=...
// 


template<typename T>
class Container
{
private:
	T* arr;
	int size;
	int capacity;

	class iterator
	{
	private:
		T* ptr;
	public:
		iterator():ptr(nullptr){}
		iterator(T* ptr):ptr(ptr){}

		T& operator*()
		{
			return *ptr;
		}
		// 전위 연산자 ++it
		iterator& operator++()
		{
			ptr++;
			return *this;
		}
		// 후위 연산자 it++
		iterator& operator++(int)
		{
			iterator temp = *this;
			ptr++;
			return temp;
		}
		bool operator==(const iterator& other)
		{
			return ptr == other.ptr ; // ? true : false 생략해도된다.
		}
		bool operator!=(const iterator& other)
		{
			return ptr != other.ptr; // ? true : false 생략해도된다.
		}

	};

	// iterator 허용된 함수
public:
	using iterator = iterator;
	iterator begin() { return iterator(arr); }
	iterator end() { return begin + size; }

	// Container 자료구조의 기능 구현
public:

	Container(int size = 3)
	{
		arr = new T[size];
		size = 0;
		capacity = size;
	}

	void push_back(T data)
	{
		arr[size] = data;
		size++;
	}

	void pop_back()
	{
		size = size > 0 ? size - 1 : 0; // 1. size >0 비교 true -> (size -1) 실행, false -> 0 결과를 size 대입
	}

};


void IteratorExample()
{
	std::vector<int> vec;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << std::endl;
	}

	auto it = vec.begin();

	std::cout << "iterator로 출력한 반복 결과문" << std::endl;

	for (it; it != vec.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	// for반복문 : range based for loop
	// for  ( 반한하고 싶은 데이터타입  : 찾고싶은 자료구조 )

	std::cout << "범위 기반 루프 결과문 " << std::endl;

	for (int elem : vec) // iterator vec.begin() ~ vec.end() it++ 
	{
		std::cout << elem<<std::endl;

	}

	Container<int> mycon;
	mycon.push_back(2);
	mycon.push_back(4);
	mycon.push_back(8);


}