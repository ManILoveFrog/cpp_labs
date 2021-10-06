#pragma once
#include <iostream>
using namespace std;

class Fraction{
public:
	int x, y;
	int x1, y1;
	void reduce();

	double operator+();
	double operator-();
	double operator*();
	double operator/(double div);

	
	static int s_counter();
	static int gcd();
	static int gcdNull();
	static void printAsFraction(double decimal_fraction);
	static void printAsFraction(char* decimal_fraction);
};

