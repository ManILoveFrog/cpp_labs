#pragma once
#include "Fraction.h"
#include <iostream>
using namespace std;
static int s_gcd = 1;


int Fraction::s_counter(){
	static int cntr = 0;
	++cntr;
	return cntr;
}

void Fraction::reduce() { //Сокращение дроби
	int k = 2;
	
	for (size_t i = 0; i < 500; i++) {
		if ((x % k == 0) and (y % k == 0)) {
			x = x / k;
			y = y / k;
			//cout << " Reduced by " << k <<" fraction: " << x << " / " << y << "\n";
			s_gcd *= k;
		}
		else {
			k++;
		}
	}
}

int Fraction::gcd() { //нахождение наибольшего общего делителя чисел n и m
	return s_gcd;
}
int Fraction::gcdNull() { // Так как элемент статичный, то нам нужно вручную его сбросить
	s_gcd = 1;
	return s_gcd;
}

//Перегрузка операторов, начало
double Fraction::operator+() {
	Fraction fr0;
	fr0.x = x * y1 + x1 * y;
	fr0.y = y * y1;
	fr0.reduce();
	cout << fr0.x << " / " << fr0.y << endl;
	double val = fr0.x / fr0.y;
	return (double)(val);
}
double Fraction::operator-() {
	Fraction fr0;
	fr0.x = x * y1 - x1 * y;
	fr0.y = y * y1;
	fr0.reduce();
	cout << fr0.x << " / " << fr0.y << endl;
	double val = fr0.x / fr0.y;
	return (double)(val);
}
double Fraction::operator*() {
	Fraction fr0;
	fr0.x = x * x1;
	fr0.y = y * y1;
	fr0.reduce();
	cout << fr0.x << " / " << fr0.y << endl;
	double val = fr0.x / fr0.y;
	return (double)(val);
}
double Fraction::operator/(double div) {
	Fraction fr0;
	fr0.x = x * y1;
	fr0.y = y * x1;
	fr0.reduce();
	cout << fr0.x << " / " << fr0.y << endl;
	double val = fr0.x / fr0.y;
	return (double)(val);
}	
//Перегрузка операторов, конец

void Fraction::printAsFraction(double decimal_fraction) {
	int numerator; //числитель
	int denominator = 1; // знаманетель 

	for (size_t i = 0; i < 7; i++) {
		decimal_fraction *= 10;
		denominator *= 10;
	}
	numerator = (int)decimal_fraction;
	//cout << numerator << " / " << denominator << "\n";
	
	Fraction fr;
	fr.x = numerator;
	fr.y = denominator;
	fr.reduce();
	cout << "\n\n\tOrdinary fraction : " << fr.x << " / " << fr.y << "\n\n";
}

void Fraction::printAsFraction(char* decimal_fraction) {
	char fr[255]; 
	
	size_t j = 0;
	int den = 1;


	for (size_t i = 0; i < 255; i++) {
		fr[j] = decimal_fraction[i];
		if (decimal_fraction[i] == '.') continue;
		j++;
	}


	for (size_t i = 1; i < 255; i++) {	
		if ((fr[i] == '0') or (fr[i] == '1') or (fr[i] == '2') or
			(fr[i] == '3') or (fr[i] == '4') or (fr[i] == '5') or
			(fr[i] == '6') or (fr[i] == '7') or (fr[i] == '8') or
			(fr[i] == '9') or (fr[i] == '0')) {
			den *= 10;
		}
	}
	for (size_t i = 1; i < 255; i++) {
		if (fr[0] == '0') fr[0] = ' ';
	}
	cout << "\n\n\tOrdinary fraction: " << fr << " / " << den << "\n\n";
	
}