#pragma once

#include <iostream>
#include <queue>
#include <string>

class Command
{
protected:
	std::string Key;// 키 : Command 명령어를 저장을 한다.

public:
	Command(std::string key) :Key(key){} // 커맨드 클래스의 생성자 - 키를 초기화
	virtual ~Command() = default; // 가상 소멸자 : 부모 클래스가 가장 마지막에 소멸되도록 해주는 문법
	virtual std::string execute() const = 0; // 모든 커맨드의 실행 기능
	std::string GetKey() { return Key; } // 
};


class FireBall : public Command
{
public:
	FireBall(std::string key) :Command(key){}
	std::string execute() const override
	{
		return "파이어볼 시전!";
	}	
};

class MeteorStrike : public Command
{
public:
	MeteorStrike(std::string key):Command(key){}
	std::string execute() const override
	{
		return "파멸의 일격!";
	}
};

template<typename T>
class CiruclarQueue
{
private:
	T* arr; 
	int front; 
	int rear; 
	int iCount;
	int MaxICount;
public:
	CiruclarQueue(int size= 4)
	{
		arr = new T[size];
		front = 0;
		rear = 0;
		iCount = 0;
		MaxICount = size;
	}
	T Front()
	{
		return arr[front];
	}
	T Rear()
	{
		return arr[rear];
	}
	int size()
	{
		return iCount;
	}
	bool IsEmpty()
	{
		return rear == front ? true : false;
	}
	bool IsFull()
	{
		return (rear + 1) % MaxICount == front ? true : false;
	}
	void Push(T data)
	{
		if (IsFull())
		{
			std::cout << "원형 큐가 가득 찼습니다." << std::endl;
			return;
		}
		else 
		{
			arr[rear] = data;
			rear = (rear + 1) % MaxICount; 
			iCount++;
		}
		
	}
	void Pop()
	{
		if (IsEmpty())
		{
			std::cout << "원형 큐가 비었습니다." << std::endl;
		}
		else
		{
			front = (front + 1) % MaxICount;
			iCount--;
		}

	}

};

/// <summary>
/// Command를 사용해서 특별한 동작을 실행하는 클래스
/// </summary>
class CommandSystem
{
private:
	// 자료구조 Command들을 가장 효율적으로 저장할 수 있는 것이 무엇일지
	std::vector<Command*> Commands; // 특별한 이유가 없으면 vector가 효율적이다. (원소 수가 적으면 적을 수록)
	CiruclarQueue<std::string> inputs; // 유저가 보낸 신호를 순서대로 저장을 해야하는 데이터
public:

	void addCommand(Command* command)
	{
		Commands.push_back(command);
	}

	void addInput(const std::string& input)
	{
		// 최대 갯수

		if (inputs.size() < 3)
		{
			inputs.Push(input);
		}
		if (inputs.size() == 3)
		{
			ProcessCommand();// 커맨드를 실행한다.
			ClearQueue();// 큐를 비워준다.
		}
	}

	void ProcessCommand()
	{
		// 유저가 입력한 순서대로 커맨드가 실행되어야 한다.
		std::string userCommand = "";

		while (!inputs.IsEmpty()) // 큐가 0이 될때까지 실행한다.
		{
			userCommand += inputs.Front();
			inputs.Pop();
		}
		// 커맨드의 Key와 userCommand 비교 값이 일치하는 게 있다.
		for(int i=0; i<Commands.size();i++)
		{
			if (userCommand == Commands[i]->GetKey())
			{
				std::cout << Commands[i]->execute() << std::endl;
				return;
			}
		}

		std::cout << "일치하는 커맨드가 없습니다." << std::endl;

	}
	void ClearQueue()
	{
		while (!inputs.IsEmpty())
		{
			inputs.Pop();
		}
	}
	void ShowCommandList()
	{
		std::cout << "=== 커맨드 목폭 ===" << std::endl;
		std::cout << "FireBall 커맨드 : " << "QWR" << std::endl;
		std::cout << "MeteorStrike 커맨드 : " << "QWE" << std::endl;
	}
	void ShowPlayerInput()
	{
		std::cout << "현재 입력 값 : [ ";
		CiruclarQueue<std::string> temp = inputs;

		while (!temp.IsEmpty()) // 큐가 0이 될때까지 실행한다.
		{
			std::cout << temp.Front() << " ";
			temp.Pop();
		}
		std::cout << "] " << std::endl;
	}
};

// CommandSystemExample 호출 함수
void CommandSystemExample()
{
	CommandSystem manager;

	FireBall command1("QWR");
	MeteorStrike command2("QWE");

	manager.addCommand(&command1);
	manager.addCommand(&command2);

	std::string input;

	while (true)
	{
		manager.ShowCommandList();
		manager.ShowPlayerInput();
		
		std::cin >> input;
		manager.addInput(input);

		if (input == "L")
		{
			std::cout << "시스템 종료 " << std::endl;
			break;
		}
	}
	
}