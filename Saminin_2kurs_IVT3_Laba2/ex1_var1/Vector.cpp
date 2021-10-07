#pragma once
#include "Vector.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#define PI 3.14159265 
using namespace std;
const size_t LENGTH = 25;
const size_t rows = 5;
const size_t cols = 5;

//Конструктор 
Vector::Vector(size_t n) {
	arr1D = new double[n];
	for (size_t i = 0; i < n; i++) {
		*(arr1D + i) = i * sin((PI * i) / 25);
	}
}

void Vector::printArray1D() {
	for (size_t i = 0; i < LENGTH; i++) {
		cout << *(arr1D + i) << setw(10);	
	}
	cout << "\n\n";
}

double** Vector::transform() {
    int count = 0;
    double sum = 0;

    double** arr2D = new double* [5];
    for (int i = 0; i < 5; i++) {
        arr2D[i] = new double[5];
    }

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            arr2D[i][j] = arr1D[count++];
        }
    }

	for (size_t i = 0; i < rows; ++i) {
		arr2D[i][0] = 0;
		sum = arr2D[i][0];
		for (size_t j = 0; j < cols; ++j) {
			sum += arr2D[i][j];
		}
		arr2D[i][0] = sum;
	}

    return arr2D;
}

//Деконструктор
Vector::~Vector() {
	delete[] arr1D;
}
