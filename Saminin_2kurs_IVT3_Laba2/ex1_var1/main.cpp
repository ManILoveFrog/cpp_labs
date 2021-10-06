//Написать классы Vector и Matrix для хранения и обработки одномерных и двумерных массивов, соответственно.
//Реализовать задание 2 лабораторной работы №1 с помощью созданных классов.
//Все функции оформить в виде методов классов.
//В коде отразить следующее :
//	* Выделение и освобождение динамической памяти производить в конструкторах и деструкторах классов, соответственно.
//	* В классе Vector перегрузить оператор индексации[].В классе Matrix добавить 
//методы T at(int i, int j) const и setAt(int i, int j, T val), которые позволяют 
//получить и установить значение элемента массива с индексом[i][j], T – это тип элементов 
//массива по варианту(int или double).
//	* Перегрузить операторы инкремента и декремента(как префиксного, так и постфиксного).
//Смысл инкремента / декремента всего массива заключается в инкременте / декременте каждого элемента массива.

#include <iostream>
using namespace std;
#include "Vector.h"
#include "Matrix.h"
#include <conio.h> // for using getch()
static int i, j;

int main() {
	Vector arr1D;
	arr1D.initArray();
	arr1D.printArray1D();
	arr1D.~Vector();

	Matrix arr2D;
	arr2D.makeArray2D();
	
	cout << "  ++value : \n";
	arr2D.operator++(); //Перегрузка: префиксный инкремент
	arr2D.printArray2D(); 
	arr2D.makeArray2D();

	cout << "  --value : \n";
	arr2D.operator--(); //Перегрузка: префиксный декремент
	arr2D.printArray2D();
	arr2D.makeArray2D();

	cout << "  value++ : \n";
	arr2D.operator++(25); //Перегрузка: постфиксный инкремент
	arr2D.printArray2D();
	arr2D.makeArray2D();

	cout << "  value-- : \n";
	arr2D.operator--(25); //Перегрузка: постфиксный декремент
	arr2D.printArray2D();
	arr2D.makeArray2D();

	cout << "  Original array : \n";
	arr2D.printArray2D();


	//Ожидание нажатия Enter(код - 13)
	while (true) {
		
		cout << "Enter i = ";
		cin >> i;
		cout << "Enter j = ";
		cin >> j;
		cout << "Element of array[" << i << "][" << j << "] = ";

		cout << arr2D.at(i, j) << "\n";
		arr2D.setAt(i, j, 0);
		cout << "\n";
		arr2D.remakeArray2D();
		arr2D.printArray2D();

		cout << "Press 'ENTER' to EXIT, press ANY KEY to continue\n\n";
		int x = _getch();
		if (x == 13) {
			exit(0);
		}
	}

	
	arr2D.~Matrix();

	system("pause");
	return 0;
}