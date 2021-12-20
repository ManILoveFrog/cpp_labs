#pragma once
#include <string>
using namespace std;
#include "Person.h"
#include "ISalaryCalculation.h"

class Student : public Person, public ISalaryCalculation {
public:
    Student();
    Student(string name, string gender, string birthday, string dateOfEntrance, int numberOfcard, int marks[]);
    void print() const override;
    void setDateOfEntrance(string dateOfEntrance);
    void setnNumberOfCard(int numberOfCard);
    void setMarks(int* marks);
    void calculateAverageMark(int marks[]);
    void serialize();
    void serialize(const string& filename);
    void deserialize();
    void deserialize(const string& filename);
    double getAverageMark();
    double calculate() const override;
private:
    static int count;
    int rowNumber;
    string name;
    string gender;
    string birthday;
    string dateOfEntrance;
    int numberOfCard;
    int marks[4];
    double averageMark;
};