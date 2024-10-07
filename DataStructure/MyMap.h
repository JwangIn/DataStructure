#pragma once

#include <map>
#include <iostream>
#include <string>

// 학생 클래스 

// 인덱스

using namespace std;

class student
{
private:
	std::string name;
	int score;

public:
	student(){}
	student(std::string Name,int Score):name(Name),score(Score){}

	std::string GetName()const { return name; }
	int GetScore()const { return score; }
};

// map

class player
{
private:
	std::string name;
	int id;
public:
	player(){}
	player(std::string Name,int Id):name(Name),id(Id){}

	std::string GetName()const { return name; }
	int GetScore()const { return id; }
};

void MapExample()
{
	std::pair<int, student> myPair;

	std::map<int, student*> myMap;

	

	// map에 데이터를 입력하는 방법
	myMap.emplace(make_pair(1, new student("AAA", 100)));

	myMap.insert(pair<int, student*>(4, new student("DDD", 200)));
	myMap.insert(make_pair(2, new student("BBB", 100)));

	myMap.insert({ 3, new student("CCC", 100) });


	// begin,end

	for (auto i = myMap.begin(); i != myMap.end(); i++)
	{
		std::cout << i->first << ", " << i->second->GetName() << ", " << i->second->GetScore() << std::endl;
	}

	std::map<int, player*> myPlayer;

	myPlayer.emplace(make_pair(1, new player("III", 101)));
	myPlayer.emplace(make_pair(2, new player("SSS", 124)));
	myPlayer.emplace(make_pair(3, new player("QQQ", 136)));

	for (auto i = myPlayer.begin(); i != myPlayer.end(); i++)
	{
		std::cout << i->first << ", " << i->second->GetName() << ", " << i->second->GetScore() << std::endl;
	}

	

}