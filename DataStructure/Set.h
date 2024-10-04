#pragma once
#include <iostream>
#include <set> 

// set �ڷᱸ���� Ư¡
// Red-Black Ʈ���� ����
// ���ĵǾ� �ִ� �ڷᱸ��
// �ߺ��� ������� �ʴ´�.

// ���� ������ ���� ��Ʈ���� �°� ǥ���غ�����.
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