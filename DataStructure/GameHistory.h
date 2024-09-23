#pragma once
#include <stack>
#include <string>
#include <iostream>
// game에서 최근 로그아웃한 시간을 출력하는 클래스를 직접 구현해볼 것

// GameData
// std::string iData; "2024-09-23 / 16:57:00"
// Print() {"게임 로그아웃 시간 : " << iData}

// class GameHistory
// Stack<GameData>
// Pop, push
// SaveLogoutTime(std::string 시간) push
// PrintLogoutTime() pop

class GameData
{
private:
	std::string iData;
	// 플레이어의 현재 정보
	//

public:
	GameData(std::string data)
	{
		iData = data;
	}
	void Print()
	{
		std::cout <<"로그아웃한 시간 : " << iData << std::endl;
	}

	std::string GetData() { return iData; }

};

class GameHistory
{
private:
	std::stack<GameData> GameDatas;
	// GameData*  m_Data;
	// int		  capacity;
	// int	      top;

	// pop, push, 
public:
	GameHistory(){}

	
	void SaveLogoutTime(GameData time)
	{
		GameDatas.push(time);
	}

	void PrintLogOutTime()
	{
		GameData printData = GameDatas.top();

		printData.Print();
		GameDatas.pop();
	}

};


void iGameHistory()
{
	// 로그아웃한 이력
	GameData data1("2024-09-20 / 17:00");
	GameData data2("2024-09-21 / 17:00");
	GameData data3("2024-09-22 / 17:00");
	GameData data4("2024-09-22 / 17:00");

	// 특정 유저가 로그아웃한 시간을 출력할 수 있는 기능

	GameHistory GDatas;
	GDatas.SaveLogoutTime(data1);
	GDatas.SaveLogoutTime(data2);
	GDatas.SaveLogoutTime(data3);
	GDatas.PrintLogOutTime();
	GDatas.PrintLogOutTime();
	GDatas.PrintLogOutTime();
}