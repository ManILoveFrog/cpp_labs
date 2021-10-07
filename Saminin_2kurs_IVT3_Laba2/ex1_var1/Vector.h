#pragma once
#include <iostream>
using namespace std;



class Vector{
public:

	double* arr1D;

	Vector(size_t n); //Конструктор 
	
	void printArray1D();

	double** transform();

	~Vector(); //Деконструктор

	double& operator[] (const int index) { //Перегрузка оператора индекцсации
		return arr1D[index];
	}

};

