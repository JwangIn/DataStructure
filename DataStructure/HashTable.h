#pragma once

#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <string>

/*
*  balanced BST - 데이터들이 정렬되어 있어야 한다.
*  정렬이 되지 있지 않아도 데이터를 검색할 수 있는 자료구조 -> unordered_set, map // hashFunction
*  hashFunction : 특정 규격으로 정해진 값을 반환하는 함수
*  hashkey : 매우 큰 숫자를 가진다. 
*  bucket : 작은 숫자로 변환을 한다
*/

void HashExample()
{
	std::unordered_set<std::string> unordSet;

	unordSet.reserve(50000);

	unordSet.emplace("abc");
	unordSet.emplace("def");
	unordSet.emplace("ghi");

	for (const std::string& str : unordSet)
	{
		std::cout << str << std::endl;

	}
	std::cout << "abc : " << std::hash<std::string>{}("abc") << std::endl;
	// bucket 바구니 숫자가 생성이 되는가
	std::cout << "bucket 수 : " << unordSet.bucket_count();
	// 접근을 하는법 
	// 탐색을 할 때는 매우 빠른데, 데이터에 저장된 값이 데이터 추가, 삭제 될 때 마다 변햇다
}