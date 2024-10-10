#pragma once

#include <iostream>
#include <vector>
#include <stack>
#include <set>
// 그래프 Graph
// 1. 그래프란? vertex(점)와 edge(선)으로 데이터 간의 연결 관계를 범용적으로 표현한 자료구조이다.

// 그래프의 특색(feature)

// 1. 방향성 갖거나, 갖지 않는다. (directed vs unDirected)
// 2. 선이 가중치를 갖는가? weighted, 연결된 선의 가중치를 부여할 수 있다. 부여하지 않으면 0,1로 표현한다.
// 3. 순회하는가? cyclic graph vs Acyclic graph

// Graph Theroy 그래프이론
// DAG (Directed Acyclic Graph) : 트리의 한 종류이다.

// 그래프의 표현
// 1. adjacent matrix 인접 메트릭스
// 2. adjacent list 인접 리스트

// 그래프의 순회, 검색(search)
// DFS, BFS
// Depth First Search : 깊이 우선 탐색
// Breadth First Search : 폭(가로) 우선 탐색

class Graph_Matrix
{
private:
	int Vertex; // 정점의 수
	std::vector<std::vector<int>> adjMatrix;
public:
	Graph_Matrix(int vertices) : Vertex(vertices), adjMatrix(vertices,vector<int>(vertices,0))
	{
	}

	void addEfgeMatrix(int v1,int v2)
	{
		adjMatrix[v1][v2] = 1;
		adjMatrix[v2][v1] = 1;

	}
	
	
	void printGraphMatrix()
	{
		for (int i = 0; i < Vertex; i++)
		{
			for (int j = 0; j < Vertex; j++)
			{
				std::cout << adjMatrix[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}

};

class Garph_List
{
private:
	int Vertex; // 정점의 수
	std::vector<std::vector<int>> adjList;
	std::set<int> seen; // 출력한 노드들을 저장할 자료구조

	void recur_DFS(int index) // 0번 검색
	{
		std::cout << index << " ";	// 시작 데이터를 출력
		seen.insert(index); // 0번 seen 삽입
		vector<int>& keys = adjList[index]; // 시작 vertex의 인접 vertex를 찾는다. 1, 0보다 크면 있다.

		for (int key : keys)
		{
			if (seen.find(key) == seen.end()) // seen에 없는 데이터라면 실행, seen.key 검색 없는게 true 실행
			{
				recur_DFS(key);
			}
		}
		
	}

public:
	Garph_List(int vertices) : Vertex(vertices) 
	{
		adjList.resize(Vertex);
	}
	
	void addEdgeList(int v1, int v2)// directed, undirected
	{
		adjList[v1].push_back(v2);
		adjList[v2].push_back(v1);
	}

	bool RecurDFS() // Graph DFS 사용해서 모든 경로가 연결되어 있는지 파악하는 함수
	{
		seen.clear();
		recur_DFS(0);

		// seen vertex, adjList.size
		if(seen.size()==adjList.size())
			std::cout << "모든 경로가 연결되어 있습니다." << std::endl;
		else
			std::cout << "모든 경로가 연결되어 있지 않습니다." << std::endl;

		return seen.size() == adjList.size();
	}

	void IterDFS(int index) // for(it = begin(), !=end().it++)
	{
		seen.clear();

		std::stack<int> s; // 인접한 vertex 저장 -> 인접한 vertex
		s.push(index);
		
		while (!s.empty())
		{
			int vertex = s.top();
			s.pop();

			if (seen.find(vertex) == seen.end()) // 중복을 막는다
			{
				std::cout << vertex << " ";
				seen.insert(vertex);

				for (auto it = adjList[vertex].rbegin(); it != adjList[vertex].rend(); it++)
				{
					if(seen.find(*it)==seen.end())
						s.push(*it);
				}
			}
			
		}
		if(seen.size()==adjList.size())
			std::cout << "모든 경로가 연결되어 있습니다." << std::endl;
		else
			std::cout << "모든 경로가 연결되어 있지 않습니다." << std::endl;

		
	}
	void IterBFS(int index) // for(it = begin(), !=end().it++)
	{
		seen.clear();

		std::queue<int> s; // 인접한 vertex 저장 -> 인접한 vertex
		s.push(index);

		while (!s.empty())
		{
			int vertex = s.front();
			s.pop();

			if (seen.find(vertex) == seen.end()) // 중복을 막는다
			{
				std::cout << vertex << " ";
				seen.insert(vertex);

				for (auto it = adjList[vertex].begin(); it != adjList[vertex].end(); it++)
				{
					if (seen.find(*it) == seen.end())
						s.push(*it);
				}
			}

		}
		if (seen.size() == adjList.size())
			std::cout << "모든 경로가 연결되어 있습니다." << std::endl;
		else
			std::cout << "모든 경로가 연결되어 있지 않습니다." << std::endl;


	}


	void printGraphList()
	{
		for (int i = 0; i < Vertex; i++)
		{
			std::cout << "정점" << i << "의 인접 메트릭스 :";
			for (auto x : adjList[i])
			{
				std::cout << " ->" << x;
			}
			std::cout << std::endl;
		}
	}
	

};


void GraphExample()
{
	Garph_List graph_L(7);
	// graph_L.addEdgeList(0, 2);
	// graph_L.addEdgeList(0, 3);
	// graph_L.addEdgeList(1, 3);
	// graph_L.addEdgeList(1, 4);
	// graph_L.addEdgeList(2, 4);

	graph_L.addEdgeList(0, 1);
	graph_L.addEdgeList(1, 4);
	graph_L.addEdgeList(4, 6);
	graph_L.addEdgeList(0, 2);
	graph_L.addEdgeList(2, 4);
	graph_L.addEdgeList(2, 5);
	graph_L.addEdgeList(0, 3);

	graph_L.printGraphList();
	graph_L.RecurDFS();
	graph_L.IterDFS(0);
	graph_L.IterBFS(0);

	std::cout << "Graph Matrix" << std::endl;

	Graph_Matrix graph_M(5);
	graph_M.addEfgeMatrix(0, 2);
	graph_M.addEfgeMatrix(0, 3);
	graph_M.addEfgeMatrix(1, 3);
	graph_M.addEfgeMatrix(1, 4);
	graph_M.addEfgeMatrix(2, 4);

	graph_M.printGraphMatrix();

	// vector<vector<int>> example
	// {
	// 	{0,1},{0,2},{0,3},
	// 	{1,4}
	// }

	
}

// 그래프 탐색 문제
// 0번 문 :  1,3 연결
// 1번 문 : 0,1,3,5 연결
// 2번 문 : 2,4 연결
// 3번 문 : 0,2 연결
// 4,5 문 : 연결 x

// 이 문이 전체가 연결되어 있으면 true 반환, 아니면 false반환하도록 코드를 작성해보세요.

class VisitAllRooms
{
private:
	std::vector<std::vector<int>> rooms; // 방들을 그래프로 표현하는 2차원 배열 
	set<int> seen; // 탐색한 방을 저장하는 자료구조

	// 재귀 방식
	void recurDFS(std::vector<std::vector<int>> rooms)
	{
		// stack : 인접한 vertex 대입, seen 넣고, 출력



	}

	// iterative
	// seen에 넣고 이동 스택 
	void iterDFS()
	{
		while (1)
		{
			
		}


	}

	void BFS()
	{

	}
};