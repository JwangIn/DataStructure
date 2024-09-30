#pragma once

#include <iostream>
#include <vector>
#include <string>
// 포인터의 사용법 

// int abc = 10;
// int* intptr = &abc;
// *, ++,  == , !=...
// 

// class Item -> Inventory Item 자료구조 -> std::vector<int><float>. Item.Print(); 포인터 

class Item
{
private:
	float time;
	int idx;
public:
	Item(){}
	Item(float Time, int Idx):time(Time),idx(Idx){}
	void Print()
	{
		std::cout << "시간 : " << time << std::endl;
		std::cout << "No." << idx << std::endl;
	}
};


template<typename T>
class Container
{
private:
	T* arr;
	int _size;
	int capacity;

	class Iterator
	{
	private:
		T* ptr;
	public:
		Iterator():ptr(nullptr){}
		Iterator(T* ptr):ptr(ptr){}

		T& operator*()
		{
			return *ptr;
		}
		// 전위 연산자 ++it
		Iterator& operator++()
		{
			ptr++;
			return *this;
		}
		// 후위 연산자 it++
		Iterator& operator++(int)
		{
			iterator temp = *this;
			ptr++;
			return temp;
		}
		bool operator==(const Iterator& other)
		{
			return ptr == other.ptr ; // ? true : false 생략해도된다.
		}
		bool operator!=(const Iterator& other)
		{
			return ptr != other.ptr; // ? true : false 생략해도된다.
		}
		Iterator operator+(const int count)
		{
			Iterator temp = *this;
			temp.ptr += count;
			return temp;
		}

	};

	// iterator 허용된 함수
public:
	using iterator = Iterator;
	iterator begin() { return iterator(arr); }
	iterator end() { return begin() + _size; }

	// Container 자료구조의 기능 구현
public:

	Container(int _size = 3)
	{
		arr = new T[_size];
		_size = 0;
		capacity = _size;
	}

	void push_back(T data)
	{
		arr[_size] = data;
		_size++;
	}

	void pop_back()
	{
		_size = _size > 0 ? _size - 1 : 0; // 1. size >0 비교 true -> (size -1) 실행, false -> 0 결과를 size 대입
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

	Container<int>::iterator myIt = mycon.begin();

	for (myIt; myIt != mycon.end(); myIt++)
	{
		std::cout << "이터레이터로 출력한 결과 : " << *myIt << std::endl;
	}

	// range base for loop
	// 범위 기반 for 반복문
	for (int& elem : mycon)
	{
		elem += 100;
		std::cout << "범위 기반 결과 출력 : " << elem << std::endl;
	}

	myIt = mycon.begin();

	for (myIt; myIt != mycon.end(); myIt++)
	{
		std::cout << "이터레이터로 출력한 결과 : " << *myIt << std::endl;
	}

	// auto

	auto a = 10;
	auto b = 0.1f;
	auto c = 'c';
	auto d = "hello";

	std::cout << a << ", " << b << ", " << c << ", " << d << std::endl;


	std::cout << "Item Class 사용 예시" << std::endl;

	Container<Item> inventory;

	Item item1(12.54f, 1);
	Item item2(24.22f, 2);

	inventory.push_back(item1);
	inventory.push_back(item2);

	Container<Item>::iterator itemIt = inventory.begin();

	// iterator for 반복문

	std::cout << "Item Iterator를 이용한 반복문" << std::endl;
	for (itemIt; itemIt != inventory.end(); itemIt++)
	{
		(*itemIt).Print();
	}

}