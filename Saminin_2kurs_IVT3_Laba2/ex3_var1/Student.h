#pragma once
#include <string>
using namespace std;

class Student{
public:
	Student();
	Student(string fullName, string gender, size_t yearOfBirth,
		size_t yearOfEntrance, long numOfCreditBook, double avarageMark);

	//setters
	void setFio(const string& fio);
	void setGender(const string& gender);
	void setYearOfBirth(const size_t& yearOfBirth);
	void setYearOfEntrance(const size_t& yearOfEntrance);
	void setNumOfCreditBook(const long& numOfCreditBook);
	void setAvarageMark(const double& avarageMark);

	//getters
	string getFio() const;
	string getGender() const;
	size_t getYearOfBirth() const;
	size_t getYearOfEntrance() const;
	long getNumOfCreditBook() const;
	double getAvarageMark() const;

	//lab's metod
	void serialize();
	void serialize(const string& filename);
	void deserialize();
	void deserialize(const string& filename);

	//my metod
	double sessionSimulation();
	double calculAvarageMark();
	void printInfo();

private:
	string fio_;
	string gender_;
	size_t yearOfBirth_;
	size_t yearOfEntrance_;
	long numOfCreditBook_;
	double avarageMark_;
};

