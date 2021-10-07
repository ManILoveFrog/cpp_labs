#pragma once
#include <iostream>
#include <iomanip>
#include "Vector.h"
using namespace std;
const size_t rows = 5;
const size_t cols = 5;

class Matrix{
public:

	double** arr2D;
	
	Matrix();//Конструктор 

	double** remakeArray2D();
	void printArray2D();


	void setAt(int i, int j, double val);
	double at(int i, int j) const;

	double** operator++ (); //Перегрузка: префиксный инкремент
	double** operator-- (); //Перегрузка: префиксный декремент
	Matrix& operator++(int N); //Перегрузка: постфиксный инкремент
	Matrix& operator--(int N); //Перегрузка: постфиксный декремент

	~Matrix(); //Деконструктор
};

