#pragma once
#include <iostream>
#include <set> 

// set �ڷᱸ���� Ư¡
// Red-Black Ʈ���� ����
// ���ĵǾ� �ִ� �ڷᱸ��
// �ߺ��� ������� �ʴ´�.

// ���� ������ ���� ��Ʈ���� �°� ǥ���غ�����.
// 8,7,9,3,6,4,5,12,10,11

// balanced BCT ���ǰ� �ִ� set�� ����Ͽ���
// Ž��,����,���� log b
// data������ ũ��񱳸� �ؾ��ϴµ�, ��� �� ���ΰ�? ���α׷��Ӱ� ���� ���踦 ������Ѵ�.
// string char*	
// apple > banana ���� �� ū��
// 1 > 5

// Ÿ���� �ΰ� ����ϴ� Ŭ������ ������

template<typename T1,typename T2>
struct MyPair
{
	T1 first; // key
	T2 second; // value

	MyPair() : first(),second(){}
	MyPair(const T1& x, const T2& y) : first(x),second(y){}

	const T1& GetFirst() { return first; }
	const T2& GetSecond() { return second; }
};

class SomeData
{
private:
	int count;
	float time;
public:
	SomeData(int Count,float Time):count(Count),time(Time){}
	void Print()
	{
		std::cout << count << ", " << time << std::endl;
	}

};



void SetExample()
{
	std::set<int> mySet;

	mySet.emplace(1);
	mySet.emplace(10);
	mySet.emplace(115);
	mySet.emplace(151);
	mySet.emplace(1223);

	for (const int num : mySet)
	{
		std::cout << num << ", ";
	}

	std::set<SomeData*> set2;

	// �տ����� count�� ������ �񱳸� �� ��

	set2.insert(new SomeData(1, 0.5f));
	set2.insert(new SomeData(2, 1.5f));
	set2.insert(new SomeData(4, 0.8f));

	std::cout << "pair ����" << std::endl;

	MyPair<int, SomeData*> mp1(1, new SomeData(1, 0.5f));
	MyPair<int, SomeData*> mp2(2, new SomeData(2, 1.5f));
	MyPair<int, SomeData*> mp3(4, new SomeData(4, 0.8f));

	std::cout << "No." << mp1.GetFirst() << std::endl;
	mp1.GetSecond()->Print();

	std::multiset<int> mymultiSet;

	mymultiSet.emplace(1);
	mymultiSet.emplace(10);
	mymultiSet.emplace(115);
	mymultiSet.emplace(151);
	mymultiSet.emplace(1223);
	mymultiSet.emplace(1223);
	mymultiSet.emplace(1223);
	mymultiSet.emplace(1223);

	for (const int num : mymultiSet)
	{
		std::cout << num << ", ";
	}

}