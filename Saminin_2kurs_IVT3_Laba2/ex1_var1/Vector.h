#pragma once
#include <iostream>
using namespace std;
const size_t LENGTH = 25;


class Vector{
public:

	double* arr1D;

	Vector(); //����������� 

	void initArray(); 

	void printArray1D();

	~Vector(); //�������������

	double& operator[] (const int index) //���������� ��������� �����������
	{
		return arr1D[index];
	}

};

