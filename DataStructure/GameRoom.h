#pragma once

#include <iostream>
#include <string>
#include <vector>
// �ս� ��ǥ : [Room - User System] �ڷᱸ���� ����ؼ� Ŭ������ ����ڴ�.
// 1. List<Ŭ����> iList; <- �ڷᱸ���� ���ο� Ŭ���� Ÿ���� �����Ѵ�.
// 2. class GameRoom{private: vector m_Vector;} 

// �濡 ���� ������ ����
// (private)�ʵ� : name : std::string, id : int, level : int, 
// (public)��� : getName(), getid(), getLevel(), getUserInfo()

// GameRoom ������ �����ϴ� Ŭ����
// UserInfo - �迭, �����迭, ������ ����Ʈ�� ����
// addPlayer, deletePlayer, showPlayerList, banPlayer(�߰� ����), isEmpty, isFull,  


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
		std::cout << "���� �̸� : " << name << std::endl;
	}
	void GetId()
	{
		std::cout << "���� ���̵� : " << id << std::endl;
	}
	void GetLevel()
	{
		std::cout << "���� ���� : " << level << std::endl;
	}
	void ShowUserInfo()
	{
		GetName();
		GetId();
		GetLevel();
	}
};

// ������ ����Ʈ vs ���� �迭
// GameRoom - User
// �߰� ����, ����
// ���� ����

class GameRoom
{
// UserInfo �����ϴ� �ڷᱸ��... �迭, �����迭, ������ ����Ʈ
// �迭�� userinfo�� ǥ������ �� ������
// 6�θ��, 12�� ���... �� �ο��� �޸����� ��尡 ������ ���� �Ŷ�� Ȯ���� �ʿ�
// �迭�� �������� �ʴ�.

// ���� �迭 std::vector
private:
	std::vector<UserInfo> users;
	int maxCount;  // �� �ִ� �ο���
	int userCount;  // ���� �� �ο���

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
			std::cout << "���� ���� á���ϴ�." << std::endl;
		}
	}
	// void RemovePlayer()
	
	void BanPlayer(int Order)
	{
		if (0 <= Order <= users.size())
		{
			users[Order].GetName();
			std::cout << "��(��) �߹��߽��ϴ�." << std::endl;
						
			users.erase(users.begin() + Order);
			// std::vector<UserInfo>::Const_iterator Where;

			userCount--;
		}
		else
		{
			std::cout << "�ε����� ��ȿ���� �ʽ��ϴ�." << std::endl;
		}
	}
	void ShowListPlayer()
	{
		if (isEmpty())
		{
			std::cout << "�濡 ����� �����ϴ�." << std::endl;
			return;
		}

		// ���� ���� ������ ����
		for(int i=0;i<userCount;i++)
		{
			
			users[i].ShowUserInfo();
		}
	}

	bool isFull()
	{
		return userCount >= maxCount ? true : false;
		// userCount >= maxCount ������(true) : false
	}
	bool isEmpty()
	{
		return userCount <= 0 ? true : false;
	}

	void isClear() // ���� �������� �Լ�
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
	std::cout << "���ӷ� �����Դϴ�." << std::endl;

	// ������ ���� 3���� �����غ���.
	// ���� 1: �̸� A, �ڵ� 1000, ���� 10
	UserInfo user1("A", 1000, 10);
	user1.ShowUserInfo();
	// ���� 2: �̸� B, �ڵ� 1001, ���� 12
	UserInfo user2("B", 1001, 12);
	user2.ShowUserInfo();
	// ���� 2: �̸� C, �ڵ� 1002, ���� 14
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