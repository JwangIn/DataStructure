#pragma once
#include <iostream>
#include <set> 

// set 자료구조의 특징
// Red-Black 트리로 구현
// 정렬되어 있는 자료구조
// 중복을 허용하지 않는다.

// 다음 순서를 레드 블랙트리에 맞게 표현해보세요.
// 8,7,9,3,6,4,5,12,10,11

// balanced BCT 사용되고 있는 set을 사용하였다
// 탐색,삽입,삭제 log b
// data사이의 크기비교를 해야하는데, 어떻게 할 것인가? 프로그래머가 직접 설계를 해줘야한다.
// string char*	
// apple > banana 누가 더 큰가
// 1 > 5

// 타입을 두개 사용하는 클래스를 만들자

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

	// 앞에오는 count를 가지고 비교를 할 때

	set2.insert(new SomeData(1, 0.5f));
	set2.insert(new SomeData(2, 1.5f));
	set2.insert(new SomeData(4, 0.8f));

	std::cout << "pair 예제" << std::endl;

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