#include "Complexity.h"

void Print()
{

}

void lecture1()
{
	// 시간 복잡도의 단순 계산 1.

	// 1 ~ n 까지의 합을 구하기 위한 해결 방법 . 시간 복잡도를 비교 해보았다.

	float s = 0.0f;
	for (int i = 0; i < 10; i++) // (비교 1번, 덧셈 1번, 증강 연산 1) * n(10)
	{
		s += 1;
	}                           // 3n + 1번 연산 O(n)
	std::cout << "0부터 10까지의 합 : " << s << std::endl;

	// n의 범위를 아주 크게 해보자. 1 ~ 1억 덧셈. -> 3억 + 1 연산

	// 시간 복잡도의 단순 계산 1 ~ 2. 1 ~ n 더하기 : n(n + 1)/2

	int sum = 0;

	int count = 100;

	sum = sum + 1;
	sum = sum / 2;
	sum = sum * count; // 시간 복잡도 : 5 O(1);

	// 시간 복잡도를 계산하기 위한 방법 : 빅오 계산법
	// Best Case : 빅 오메가
	// Worst Case : 빅오 표기법
	// 평균 계산법 : 빅 세타 

	// 빅오 표기법의 특징 
	// 1. 가장 큰 차수 n^3 + n^2 + n + 1 // 10억 x 10억 x 10억
	// 2. 자주 사용하는 빅오의 차이

	// (빠른 순서) O(1) < O(logn) < O(n) < O(nlogn) < O(n^2) < O(n!)
	// log란 a를 n번 곱해서 = x    a^n = x   n=logaX;
	// 특정 수를 n번 나누었을 때 언제 1이 되는지 구한다.

	
}

void Example01()
{
	// 1. 시간 복잡도를 빠른 순서대로 빅오 표기로 출력해보세요.
	// 출력 형태는 O(기호)를 갖추어서 O(a)<O(b)...

	// 2. 아래의 코드의 시간 복잡도와 공간 복잡도를 계산해서 std::cout 출력해보세요
	// 시간 복잡도 : O()
	// 공간 복잡도 : O()

	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{

		}
	}

std::cout<<""


}



// 공간 복잡도 예시
float abc(float a, float b, float c)
{
	return(a + b + c * c + c + c + c * b +( a * a * a) * a);

	// 공간 복잡도 : 0 (문제 해결과 전혀 관계없는 메모리 공간)
}

float Sum(float a[], int n)
{
	float result = 0.0f;
	for (int i = 0; i < n; i++)
	{
		result += a[i];
	}
	return result;  // a[] - n개, n - 1개, r - 1개, i - 1개 -> n + 3개
}

// 공간 복잡도를 잘 안쓰는 이유
// c언어가 처음 나왔을 때에 비해... 최근 하드웨어가 매우 발달함
// NASA 우주비행사 (embeded) - 
