#include "lectures.h"
#include "MyVector.h"
#include "RandomNumber.h"
// �н� ��ǥ : ���� �迭(Vector) - Array List

// ����(Vector)
// ���� ����ϴ� �ڷᱸ�� �� �ϳ��Դϴ�. Linked List, Array List(Vector)
// int arr[10];
// ������ �����ε����� ���� [], ==, != ... 


// ���� ����Ʈ vs ���� �迭
//                          | �ڷᱸ���� ũ�� ���� ��� | �߰� ����, ���� ��� | ���� ���� ��� | ���� ���� ���
// ���� ����Ʈ(Linked List)  |           o             |          o         |       o       |    x
// ���� �迭(Vector)         |           o             |          x         |       o       |    o
// �÷��̾��� �κ��丮 -> ���Ḯ��Ʈ ���� Inventory, Vector Inventory

// ���� : ũ�� �߰� ���� ��ɰ� ���� ���� ������� �� �ڷᱸ���� �������� ���� �� �ִ�.
// �߰� ����, ������ ���ų� ���� �߻��ϴ� ��쿡�� Vector�� ����ϸ� ����.
// �߰� ����, ������ ���� �߻��ϴ� ��쿡�� ���� ����Ʈ�� ����ϸ� ����.

void lecture5()
{
	Myvector<int> i_Vec(20);

	Myvector<int> i_Vec2;
		
	if (i_Vec != i_Vec2)
	{
		std::cout << "������ �����ε��� ���������� ������" << std::endl;
	}

	i_Vec.push_back(4);
	i_Vec.push_back(6);
	i_Vec.push_back(5);
	i_Vec.Print();

	int r_index = R_Number(0, i_Vec.GetSize()-1);
	std::cout << "i_Vec ���� ���ҿ� ���� : " <<r_index+1<< std::endl;
	std::cout << "���� �� : " << i_Vec[r_index] << std::endl;

	std::cout << "i_Vec�� 0��° ���ҿ� ���� : " << i_Vec[0] << std::endl;
	
	std::cout << "private�� ������ vec�� ���� ���� : " << i_Vec.GetVector()[0] << std::endl;


	// ������ ��������
	// Vector�� Ư¡. ������ ���ҿ� �����ϴ� �ð��� 0(1);
	// Vector ���� ���ҿ� �����ϴ� ��� ����
	// int randomNumber = << srand(); rand() % 100 + 1;  ���� seed


}