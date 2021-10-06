#pragma once
#include <iostream>
using namespace std;
const size_t LENGTH = 25;


class Vector{
public:

	double* arr1D;

	Vector(); //Конструктор 

	void initArray(); 

	void printArray1D();

	~Vector(); //Деконструктор

	double& operator[] (const int index) //Перегрузка оператора индекцсации
	{
		return arr1D[index];
	}

};

