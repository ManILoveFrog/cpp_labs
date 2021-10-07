#pragma once
#include <iostream>
#include <iomanip>
#include "Matrix.h"
#include "Vector.h"
using namespace std;


//Конструктор 
Matrix::Matrix() {
	arr2D = new double* [rows];
	for (size_t i = 0; i < rows; i++) {
		arr2D[i] = new double[cols];
	}

}

double** Matrix::remakeArray2D() {
	double sum = 0;
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

void Matrix::printArray2D() {
	cout << "\n";
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			cout << setw(10) << arr2D[i][j] ;
		}
		cout << "\n";
	}
	cout << "\n";
}

void Matrix::setAt(int i, int j, double val){
	cout << "Enter value of element of array = ";
	cin >> val;
	arr2D[i][j] = val;
}

double Matrix::at(int i, int j) const {
	return arr2D[i][j];
}


double** Matrix::operator++() {

	double sum;

	for (size_t i = 0; i < rows; ++i) {
		arr2D[i][0] = 0;
		sum = arr2D[i][0];
		for (size_t j = 0; j < cols; ++j) {
			if (j != 0) {
				arr2D[i][j] ++;
			}
			sum += arr2D[i][j];
		}
		arr2D[i][0] = sum;
	}

	return arr2D;
}

double** Matrix::operator--(){

	double sum;

	for (size_t i = 0; i < rows; ++i) {
		arr2D[i][0] = 0;
		sum = arr2D[i][0];
		for (size_t j = 0; j < cols; ++j) {
			if (j != 0) {
				arr2D[i][j] --;
			}
			sum += arr2D[i][j];
		}
		arr2D[i][0] = sum;
	}

	return arr2D;
}

Matrix& Matrix::operator++(int N) {
	double sum;

	for (size_t i = 0; i < rows; ++i) {
		arr2D[i][0] = 0;
		sum = arr2D[i][0];
		for (size_t j = 0; j < cols; ++j) {
			if (j != 0) {
				arr2D[i][j]++;
			}
			sum += arr2D[i][j];
		}
		arr2D[i][0] = sum;
	}
	return *this;
}

Matrix& Matrix::operator--(int N) {
	double sum;

	for (size_t i = 0; i < rows; ++i) {
		arr2D[i][0] = 0;
		sum = arr2D[i][0];
		for (size_t j = 0; j < cols; ++j) {
			if (j != 0) {
				arr2D[i][j]--;
			}
			sum += arr2D[i][j];
		}
		arr2D[i][0] = sum;
	}
	return *this;
}

//Деконструктор
Matrix::~Matrix() {
	for (size_t i = 0; i < rows; ++i) {
		delete[] arr2D[i];
	}
	delete[] arr2D;
}