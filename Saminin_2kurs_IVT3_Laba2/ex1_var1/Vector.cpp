#pragma once
#include "Vector.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#define PI 3.14159265 
using namespace std;

//Конструктор 
Vector::Vector() {
	arr1D = new double[LENGTH];
}

void Vector::initArray() {
	for (size_t i = 0; i < LENGTH; i++) {
		*(arr1D + i) = i * sin((PI * i) / 25);
	}
}

void Vector::printArray1D() {
	for (size_t i = 0; i < LENGTH; i++) {
		cout << *(arr1D + i) << setw(10);	
	}
	cout << "\n\n";
}

//Деконструктор
Vector::~Vector() {
	delete[] arr1D;
}
