#pragma once

#include <iostream>
#include <vector>
#include <string>
// �������� ���� 

// int abc = 10;
// int* intptr = &abc;
// *, ++,  == , !=...
// 

// class Item -> Inventory Item �ڷᱸ�� -> std::vector<int><float>. Item.Print(); ������ 

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
		std::cout << "�ð� : " << time << std::endl;
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
		// ���� ������ ++it
		Iterator& operator++()
		{
			ptr++;
			return *this;
		}
		// ���� ������ it++
		Iterator& operator++(int)
		{
			iterator temp = *this;
			ptr++;
			return temp;
		}
		bool operator==(const Iterator& other)
		{
			return ptr == other.ptr ; // ? true : false �����ص��ȴ�.
		}
		bool operator!=(const Iterator& other)
		{
			return ptr != other.ptr; // ? true : false �����ص��ȴ�.
		}
		Iterator operator+(const int count)
		{
			Iterator temp = *this;
			temp.ptr += count;
			return temp;
		}

	};

	// iterator ���� �Լ�
public:
	using iterator = Iterator;
	iterator begin() { return iterator(arr); }
	iterator end() { return begin() + _size; }

	// Container �ڷᱸ���� ��� ����
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
		_size = _size > 0 ? _size - 1 : 0; // 1. size >0 �� true -> (size -1) ����, false -> 0 ����� size ����
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

	std::cout << "iterator�� ����� �ݺ� �����" << std::endl;

	for (it; it != vec.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	// for�ݺ��� : range based for loop
	// for  ( �����ϰ� ���� ������Ÿ��  : ã����� �ڷᱸ�� )

	std::cout << "���� ��� ���� ����� " << std::endl;

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
		std::cout << "���ͷ����ͷ� ����� ��� : " << *myIt << std::endl;
	}

	// range base for loop
	// ���� ��� for �ݺ���
	for (int& elem : mycon)
	{
		elem += 100;
		std::cout << "���� ��� ��� ��� : " << elem << std::endl;
	}

	myIt = mycon.begin();

	for (myIt; myIt != mycon.end(); myIt++)
	{
		std::cout << "���ͷ����ͷ� ����� ��� : " << *myIt << std::endl;
	}

	// auto

	auto a = 10;
	auto b = 0.1f;
	auto c = 'c';
	auto d = "hello";

	std::cout << a << ", " << b << ", " << c << ", " << d << std::endl;


	std::cout << "Item Class ��� ����" << std::endl;

	Container<Item> inventory;

	Item item1(12.54f, 1);
	Item item2(24.22f, 2);

	inventory.push_back(item1);
	inventory.push_back(item2);

	Container<Item>::iterator itemIt = inventory.begin();

	// iterator for �ݺ���

	std::cout << "Item Iterator�� �̿��� �ݺ���" << std::endl;
	for (itemIt; itemIt != inventory.end(); itemIt++)
	{
		(*itemIt).Print();
	}

}