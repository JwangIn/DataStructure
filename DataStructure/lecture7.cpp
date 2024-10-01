#include "lectures.h"
#include <vector>
#include <iostream>
#include <chrono>
// 자료를 저장하는 거 까지 배웠다.
// 자료구조 안에 있는 데이터를 찾아서, 사용하기 위해서
// 데이터를 가장 효율적으로 저장하는 방법에 대해서 배웠습니다.

// ADT . Queue. Stack. Priority_Queue

// 자료구조 내부에 있는 데이터를 어떻게 빨리 찾을까
// 1순위 시간 복잡도 Time complexity
// 2순위 공간 복잡도 Space complexity

// 반복문을 통해서 모든 원소를 순회(traverse) 시간 O(n) : 데이터 많으면 많을수록 오래걸린다.
// O(logn) - 자료구조가 정렬 되어 있으면 이진 탐색(binary search)으로 O(logn) 탐색 할 수 있다.
// O(1)

// 자료구조의 vector 이진 탐색을 구현을 했습니다.
// Linked list..-> 이진 탐색 가능할까요? -> 불가능합니다.
// 중간에 데이터 삽입, 삭제 발생 vector _rebuilding
// 이진 탐색도 하고 싶은데, 중간 삽입, 삭제도 가능한 자료구조는 없는가?
// 


using namespace std::chrono;

class MySearchTool
{
private:

public:
	int search(const std::vector<int>& arr, int target)
	{
		auto it = arr.begin();

		for (it; it != arr.end(); it++)
		{
			if ((*it) == target)
			{
				std::cout << "목표 값을 찾았습니다. : " << *it << std::endl;
				
				return (*it);
			}
		}

		std::cout << "타겟이 없었습니다." << std::endl;
		return -1;
	}

	int binarySearch(const std::vector<int>& arr, int target)
	{
		int left = 0;
		int right = arr.size() - 1;

		while (left <= right)
		{
			int mid = left + (right - left) / 2;

			if (target > arr[mid]) // mid target 클 때
			{
				left = mid + 1;
			}
			else if (target < arr[mid]) // mid target 작을 때
			{
				right = mid - 1;
			}
			else // mid target 일 때
			{
				std::cout << "목표값을 찾았습니다. " << std::endl;
				return arr[mid];
			}

		}

			// 배열의 인덱스 mid, left, right
		std::cout << "타겟이 없습니다." << std::endl;
		return -1;

	}
};


void lecture7()
{
	// command system -> (vector 커맨드 - queue 인풋) 같은 녀석 출력

	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	// vector 안에 있는 숫자를 찾는다. 탐색
		
	MySearchTool tool;

	int targetnumber = 4;

	auto start = high_resolution_clock::now();
	
	tool.search(vec, targetnumber);

	auto end = high_resolution_clock::now();
	
	auto duration = duration_cast<microseconds>(end - start);

	std::cout << "for 반복문 순회 탐색 방식 : " << duration.count() /1000.0<<"ms" << std::endl;

	auto start2 = high_resolution_clock::now();

	tool.binarySearch(vec, targetnumber);

	auto end2 = high_resolution_clock::now();

	auto duration2 = duration_cast<microseconds>(end2 - start2);

	std::cout << "for 반복문 순회 탐색 방식 : " << duration2.count() / 1000.0 << "ms" << std::endl;
}