#pragma once

#include <iostream>
#include <string>
#include <vector>
// 합습 목표 : [Room - User System] 자료구조를 사용해서 클래스를 만들겠다.
// 1. List<클래스> iList; <- 자료구조의 새로운 클래스 타입을 저장한다.
// 2. class GameRoom{private: vector m_Vector;} 

// 방에 들어온 유저의 정보
// (private)필드 : name : std::string, id : int, level : int, 
// (public)기능 : getName(), getid(), getLevel(), getUserInfo()

// GameRoom 유저를 저장하는 클래스
// UserInfo - 배열, 가변배열, 연결형 리스트로 저장
// addPlayer, deletePlayer, showPlayerList, banPlayer(추가 정보), isEmpty, isFull,  


class UserInfo
{
private:
	std::string name;
	int id;
	int level;
public:
	UserInfo(){}
	UserInfo(std::string name, int id, int level) :name(name), id(id), level(level) {}

	void GetName()
	{
		std::cout << "유저 이름 : " << name << std::endl;
	}
	void GetId()
	{
		std::cout << "유저 아이디 : " << id << std::endl;
	}
	void GetLevel()
	{
		std::cout << "유저 레벨 : " << level << std::endl;
	}
	void ShowUserInfo()
	{
		GetName();
		GetId();
		GetLevel();
	}
};

// 연결형 리스트 vs 가변 배열
// GameRoom - User
// 중간 갑입, 삭제
// 랜덤 접근

class GameRoom
{
// UserInfo 저장하는 자료구조... 배열, 가변배열, 연결형 리스트
// 배열로 userinfo를 표현했을 때 문제점
// 6인모드, 12인 모드... 등 인원이 달리지는 모드가 나오지 않을 거라는 확신이 필요
// 배열은 적합하지 않다.

// 가변 배열 std::vector
private:
	std::vector<UserInfo> users;
	int maxCount;  // 방 최대 인원수
	int userCount;  // 현재 방 인원수

public:
	GameRoom(int max = 8)
	{
		maxCount = max;
		userCount = 0;
	}
	~GameRoom(){}

	void AddPlayer(UserInfo& user)
	{		
		if ( !isFull())
		{
			users.push_back(user);
			userCount++;
		}
		else
		{
			std::cout << "방이 가득 찼습니다." << std::endl;
		}
	}
	// void RemovePlayer()
	
	void BanPlayer(int Order)
	{
		if (0 <= Order <= users.size())
		{
			users[Order].GetName();
			std::cout << "을(를) 추방했습니다." << std::endl;
						
			users.erase(users.begin() + Order);
			// std::vector<UserInfo>::Const_iterator Where;

			userCount--;
		}
		else
		{
			std::cout << "인덱스가 유효하지 않습니다." << std::endl;
		}
	}
	void ShowListPlayer()
	{
		if (isEmpty())
		{
			std::cout << "방에 사람이 없습니다." << std::endl;
			return;
		}

		// 시작 부터 마지막 까지
		for(int i=0;i<userCount;i++)
		{
			
			users[i].ShowUserInfo();
		}
	}

	bool isFull()
	{
		return userCount >= maxCount ? true : false;
		// userCount >= maxCount 가득참(true) : false
	}
	bool isEmpty()
	{
		return userCount <= 0 ? true : false;
	}

	void isClear() // 방이 없어지는 함수
	{
		while (!isEmpty())
		{
			users.pop_back();
			userCount--;
		}
	}
	void isClear2()
	{
		users.erase(users.begin(), users.end());
		userCount=0;
	}

};


void IGameRoomExample()
{
	std::cout << "게임룸 예시입니다." << std::endl;

	// 가상의 유저 3명을 생성해본다.
	// 유저 1: 이름 A, 코드 1000, 레벨 10
	UserInfo user1("A", 1000, 10);
	user1.ShowUserInfo();
	// 유저 2: 이름 B, 코드 1001, 레벨 12
	UserInfo user2("B", 1001, 12);
	user2.ShowUserInfo();
	// 유저 2: 이름 C, 코드 1002, 레벨 14
	UserInfo user3("C", 1004, 14);
	user3.ShowUserInfo();

	GameRoom room(3);
	room.AddPlayer(user1);
	room.AddPlayer(user2);
	room.AddPlayer(user3);
	room.BanPlayer(1);
	room.ShowListPlayer();

	room.isClear();
	room.ShowListPlayer();
}