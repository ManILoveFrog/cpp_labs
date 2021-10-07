/*Написать собственный класс, в соответствии с вариантом. 
Продемонстрировать в коде инкапсуляцию данных, 
применение конструкторов без параметров и с параметрами для инициализации данных. 
Класс должен содержать метод serialize() для сохранения данных класса в файл 
и метод deserialize() для чтения данных класса из файла по умолчанию в текущей директории, 
а также перегруженные методы serialize(const std::string& filename) 
и deserialize(const std::string& filename) для работы с файлом с указанным в параметре именем.*/


/*Класс СТУДЕНТ.
Данные: ФИО, пол, год рождения, год поступления, номер зачетки, средний балл.
Создать массив из 3 студентов и установить их личные данные с помощью сеттеров. 
Еще одного студента создать отдельно в куче и установить его данные в конструкторе с параметрами. 
В главной функции проимитировать три сессии – 
случайным образом сформировать по 4 новые оценки и пересчитать в отдельном методе средний балл. 
Вывести результаты студентов, отсортировав их в порядке убывания среднего балла.
*/

#include <iostream>
#include "Student.h"
using namespace std;
#include <fstream> // for using file input/output
const size_t numOfStud = 4;

void sortArray(double* arr1, string* arr2, size_t n){
	for (int i = 0; i < n; i++) {
		double zamenaDoub;
		string zamenaStr;
		for (int j = i + 1; j < n; j++) {
			if (arr1[i] < arr1[j]) {
				zamenaDoub = arr1[i];
				arr1[i] = arr1[j];
				arr1[j] = zamenaDoub;

				zamenaStr = arr2[i];
				arr2[i] = arr2[j];
				arr2[j] = zamenaStr;
			}
		}
	}
}

void printSortArray(double* arr1, string* arr2, size_t n) {
	for (size_t i = 0; i < n; i++) {
		cout << "  " << i + 1 << " - " << arr2[i] << " - " << arr1[i] << endl;
	}
	cout << "\n\n";
}

int main() {
	setlocale(LC_ALL, "rus");

	Student student1, student2, student3; //stack
	Student* student4 = new Student("Богов Иисус Христосович", "муж", 0, 2000, 151424234334, 0); //heap

	student1.setFio("Саминин Ярослав Александрович");
	student1.setGender("муж");
	student1.setYearOfBirth(2002);
	student1.setYearOfEntrance(2020);
	student1.setNumOfCreditBook(88005553535);
	student1.setAvarageMark(0);

	student2.setFio("Великий Царь Тьмы");
	student2.setGender("чёрт");
	student2.setYearOfBirth(1990);
	student2.setYearOfEntrance(2010);
	student2.setNumOfCreditBook(666666666);
	student2.setAvarageMark(0);

	student3.setFio("Бешевели Борис Иванович");
	student3.setGender("Царь Бомба");
	student3.setYearOfBirth(666);
	student3.setYearOfEntrance(1941);
	student3.setNumOfCreditBook(777000777);
	student3.setAvarageMark(0);
	

	//Имитация 3 сессий(не дай бог)
	student1.sessionSimulation();
	student2.sessionSimulation(); 
	student3.sessionSimulation(); 
	student4->sessionSimulation(); 
	
	//Высчитывание среднего балла
	student1.calculAvarageMark();
	student2.calculAvarageMark();
	student3.calculAvarageMark();
	student4->calculAvarageMark();

	//Пояснения к работе программы
	cout << "  Теперь загляните в папку с проектом\n  Там вы увидите текстовые файлы по данным класса\n" << endl;
	cout << "  Файлы, названные в виде: " << endl;
	cout << "  - цифра .txt, сохранены с помощью метода serialize()" << endl;
	cout << "  - Student + цифра .txt, сохранены с помощью перегруженного метода serialize(const string& filename)\n" << endl;
	cout << "  Демонстрация работы чтения из файла, файлы, которые названы в виде:" << endl;
	cout << "  - цифра .txt, читаются с помощью метода deserialize()" << endl;
	cout << "  - Student + цифра .txt, читаются с помощью перегруженного метода deserialize(const string& filename)\n" << endl;
	cout << "  Если вы ничего не увидели на консоли, перезапустите программу и все обязательно появится ;) \n" << endl;
	
	// Читаем из файла и выводим на консоль
	student1.deserialize();
	student2.deserialize();
	student3.deserialize();
	student4->deserialize();

	student1.deserialize("Student1.txt");
	student2.deserialize("Student2.txt");
	student3.deserialize("Student3.txt");
	student4->deserialize("Student4.txt");

	// Записываем в файл
	student1.serialize();
	student2.serialize();
	student3.serialize();
	student4->serialize();

	student1.serialize("Student1.txt");
	student2.serialize("Student2.txt");
	student3.serialize("Student3.txt");
	student4->serialize("Student4.txt");


	//До сортировки
	cout << "\n  Студенты до сортировки: " << endl;
	student1.printInfo();
	student2.printInfo();
	student3.printInfo();
	student4->printInfo();

	//Массив имен студентов
	string pitaStr[numOfStud];
	pitaStr[0] = student1.getFio();
	pitaStr[1] = student2.getFio();
	pitaStr[2] = student3.getFio();
	pitaStr[3] = student4->getFio();

	//Массив средних отметок
	double pitaDoub[numOfStud];
	pitaDoub[0] = student1.getAvarageMark();
	pitaDoub[1] = student2.getAvarageMark();
	pitaDoub[2] = student3.getAvarageMark();
	pitaDoub[3] = student4->getAvarageMark();

	//Сортировка
	cout << "\n\n  Сортировка по среднему баллу на убывание: " << endl;	
	sortArray(pitaDoub, pitaStr, numOfStud);
	printSortArray(pitaDoub, pitaStr, numOfStud);

	system("pause");
	return 0;
}