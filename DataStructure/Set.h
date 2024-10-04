#pragma once
#include <iostream>
#include <set> 

// set 자료구조의 특징
// Red-Black 트리로 구현
// 정렬되어 있는 자료구조
// 중복을 허용하지 않는다.

// 다음 순서를 레드 블랙트리에 맞게 표현해보세요.
// 8,7,9,3,6,4,5,12,10,11


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
}