#pragma once
#include <stack>
#include <string>
#include <iostream>
// game���� �ֱ� �α׾ƿ��� �ð��� ����ϴ� Ŭ������ ���� �����غ� ��

// GameData
// std::string iData; "2024-09-23 / 16:57:00"
// Print() {"���� �α׾ƿ� �ð� : " << iData}

// class GameHistory
// Stack<GameData>
// Pop, push
// SaveLogoutTime(std::string �ð�) push
// PrintLogoutTime() pop

class GameData
{
private:
	std::string iData;
	// �÷��̾��� ���� ����
	//

public:
	GameData(std::string data)
	{
		iData = data;
	}
	void Print()
	{
		std::cout <<"�α׾ƿ��� �ð� : " << iData << std::endl;
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
	// �α׾ƿ��� �̷�
	GameData data1("2024-09-20 / 17:00");
	GameData data2("2024-09-21 / 17:00");
	GameData data3("2024-09-22 / 17:00");
	GameData data4("2024-09-22 / 17:00");

	// Ư�� ������ �α׾ƿ��� �ð��� ����� �� �ִ� ���

	GameHistory GDatas;
	GDatas.SaveLogoutTime(data1);
	GDatas.SaveLogoutTime(data2);
	GDatas.SaveLogoutTime(data3);
	GDatas.PrintLogOutTime();
	GDatas.PrintLogOutTime();
	GDatas.PrintLogOutTime();
}