#pragma once

#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <string>

/*
*  balanced BST - �����͵��� ���ĵǾ� �־�� �Ѵ�.
*  ������ ���� ���� �ʾƵ� �����͸� �˻��� �� �ִ� �ڷᱸ�� -> unordered_set, map // hashFunction
*  hashFunction : Ư�� �԰����� ������ ���� ��ȯ�ϴ� �Լ�
*  hashkey : �ſ� ū ���ڸ� ������. 
*  bucket : ���� ���ڷ� ��ȯ�� �Ѵ�
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
	// bucket �ٱ��� ���ڰ� ������ �Ǵ°�
	std::cout << "bucket �� : " << unordSet.bucket_count();
	// ������ �ϴ¹� 
	// Ž���� �� ���� �ſ� ������, �����Ϳ� ����� ���� ������ �߰�, ���� �� �� ���� ���޴�
}