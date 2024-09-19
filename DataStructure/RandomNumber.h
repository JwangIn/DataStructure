#pragma once

#include <iostream>
#include <cstdlib>  // rand(), srand()
#include <ctime>   // time()

#include <random>  // c++ 지원하는 랜덤 라이브러리

int ReturnRandomNumber( int endNumber) //  e:100 1부터 100까지 숫자를 랜덤하게 반환하는 함수
{
	std::srand(time(nullptr)); // 현재 시간을 난수로(seed)
	int randNumber = std::rand() % endNumber + 1; // 0부터 endNumber -1 까지의 숫자가 반환

	return randNumber;
}

int R_Number(int startNumber,int endNumber)
{
	std::random_device rd;  // 시드를 생성하기 위한 객체
	std::mt19937 gen( rd() ); // mt19937 알고리즘을 사용하여 난수를 생성한다. // rd()
	std::uniform_int_distribution<> distrib(startNumber, endNumber); // 시작 숫자부터 끝 숫자까지 출력해주는 기능
	int randomNumber = distrib(gen);
	return randomNumber;
}