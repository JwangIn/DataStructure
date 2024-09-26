#pragma once

#include <iostream>
#include <queue>
#include <string>

class Command
{
protected:
	std::string Key;// Ű : Command ��ɾ ������ �Ѵ�.

public:
	Command(std::string key) :Key(key){} // Ŀ�ǵ� Ŭ������ ������ - Ű�� �ʱ�ȭ
	virtual ~Command() = default; // ���� �Ҹ��� : �θ� Ŭ������ ���� �������� �Ҹ�ǵ��� ���ִ� ����
	virtual std::string execute() const = 0; // ��� Ŀ�ǵ��� ���� ���
	std::string GetKey() { return Key; } // 
};


class FireBall : public Command
{
public:
	FireBall(std::string key) :Command(key){}
	std::string execute() const override
	{
		return "���̾ ����!";
	}	
};

class MeteorStrike : public Command
{
public:
	MeteorStrike(std::string key):Command(key){}
	std::string execute() const override
	{
		return "�ĸ��� �ϰ�!";
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
			std::cout << "���� ť�� ���� á���ϴ�." << std::endl;
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
			std::cout << "���� ť�� ������ϴ�." << std::endl;
		}
		else
		{
			front = (front + 1) % MaxICount;
			iCount--;
		}

	}

};

/// <summary>
/// Command�� ����ؼ� Ư���� ������ �����ϴ� Ŭ����
/// </summary>
class CommandSystem
{
private:
	// �ڷᱸ�� Command���� ���� ȿ�������� ������ �� �ִ� ���� ��������
	std::vector<Command*> Commands; // Ư���� ������ ������ vector�� ȿ�����̴�. (���� ���� ������ ���� ����)
	CiruclarQueue<std::string> inputs; // ������ ���� ��ȣ�� ������� ������ �ؾ��ϴ� ������
public:

	void addCommand(Command* command)
	{
		Commands.push_back(command);
	}

	void addInput(const std::string& input)
	{
		// �ִ� ����

		if (inputs.size() < 3)
		{
			inputs.Push(input);
		}
		if (inputs.size() == 3)
		{
			ProcessCommand();// Ŀ�ǵ带 �����Ѵ�.
			ClearQueue();// ť�� ����ش�.
		}
	}

	void ProcessCommand()
	{
		// ������ �Է��� ������� Ŀ�ǵ尡 ����Ǿ�� �Ѵ�.
		std::string userCommand = "";

		while (!inputs.IsEmpty()) // ť�� 0�� �ɶ����� �����Ѵ�.
		{
			userCommand += inputs.Front();
			inputs.Pop();
		}
		// Ŀ�ǵ��� Key�� userCommand �� ���� ��ġ�ϴ� �� �ִ�.
		for(int i=0; i<Commands.size();i++)
		{
			if (userCommand == Commands[i]->GetKey())
			{
				std::cout << Commands[i]->execute() << std::endl;
				return;
			}
		}

		std::cout << "��ġ�ϴ� Ŀ�ǵ尡 �����ϴ�." << std::endl;

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
		std::cout << "=== Ŀ�ǵ� ���� ===" << std::endl;
		std::cout << "FireBall Ŀ�ǵ� : " << "QWR" << std::endl;
		std::cout << "MeteorStrike Ŀ�ǵ� : " << "QWE" << std::endl;
	}
	void ShowPlayerInput()
	{
		std::cout << "���� �Է� �� : [ ";
		CiruclarQueue<std::string> temp = inputs;

		while (!temp.IsEmpty()) // ť�� 0�� �ɶ����� �����Ѵ�.
		{
			std::cout << temp.Front() << " ";
			temp.Pop();
		}
		std::cout << "] " << std::endl;
	}
};

// CommandSystemExample ȣ�� �Լ�
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
			std::cout << "�ý��� ���� " << std::endl;
			break;
		}
	}
	
}