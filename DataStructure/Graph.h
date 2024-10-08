#pragma once

#include <iostream>
#include <vector>
#include <stack>
#include <set>
// �׷��� Graph
// 1. �׷�����? vertex(��)�� edge(��)���� ������ ���� ���� ���踦 ���������� ǥ���� �ڷᱸ���̴�.

// �׷����� Ư��(feature)

// 1. ���⼺ ���ų�, ���� �ʴ´�. (directed vs unDirected)
// 2. ���� ����ġ�� ���°�? weighted, ����� ���� ����ġ�� �ο��� �� �ִ�. �ο����� ������ 0,1�� ǥ���Ѵ�.
// 3. ��ȸ�ϴ°�? cyclic graph vs Acyclic graph

// Graph Theroy �׷����̷�
// DAG (Directed Acyclic Graph) : Ʈ���� �� �����̴�.

// �׷����� ǥ��
// 1. adjacent matrix ���� ��Ʈ����
// 2. adjacent list ���� ����Ʈ

// �׷����� ��ȸ, �˻�(search)
// DFS, BFS
// Depth First Search : ���� �켱 Ž��
// Breadth First Search : ��(����) �켱 Ž��

class Graph_Matrix
{
private:
	int Vertex; // ������ ��
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
	int Vertex; // ������ ��
	std::vector<std::vector<int>> adjList;
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
	void printGraphList()
	{
		for (int i = 0; i < Vertex; i++)
		{
			std::cout << "����" << i << "�� ���� ��Ʈ���� :";
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
	Garph_List graph_L(5);
	graph_L.addEdgeList(0, 2);
	graph_L.addEdgeList(0, 3);
	graph_L.addEdgeList(1, 3);
	graph_L.addEdgeList(1, 4);
	graph_L.addEdgeList(2, 4);

	graph_L.printGraphList();

	std::cout << "Graph Matrix" << std::endl;

	Graph_Matrix graph_M(5);
	graph_M.addEfgeMatrix(0, 2);
	graph_M.addEfgeMatrix(0, 3);
	graph_M.addEfgeMatrix(1, 3);
	graph_M.addEfgeMatrix(1, 4);
	graph_M.addEfgeMatrix(2, 4);

	graph_M.printGraphMatrix();

	
}

// �׷��� Ž�� ����
// 0�� �� :  1,3 ����
// 1�� �� : 0,1,3,5 ����
// 2�� �� : 2,4 ����
// 3�� �� : 0,2 ����
// 4,5 �� : ���� x

// �� ���� ��ü�� ����Ǿ� ������ true ��ȯ, �ƴϸ� false��ȯ�ϵ��� �ڵ带 �ۼ��غ�����.

class VisitAllRooms
{
private:
	std::vector<std::vector<int>> rooms; // ����� �׷����� ǥ���ϴ� 2���� �迭 
	set<int> seen; // Ž���� ���� �����ϴ� �ڷᱸ��

	// ��� ���
	void recurDFS()
	{
		// stack : ������ vertex ����, seen �ְ�, ���



	}

	// iterative
	// seen�� �ְ� �̵� ���� 
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