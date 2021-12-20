#include <iostream>
#include "Student.h"
#include "Teacher.h"
using namespace std;
const size_t NUM = 4;

int main() {

    int marks1[] = { 5,4,5,5 };
    int marks2[] = { 4,3,3,4 };
    Person* person[NUM];
    person[0] = new Student("Artem", "M", "24.04.2001", "02.10.2018", 5550, marks1);
    person[1] = new Student("Stas", "M", "02.11.1999", "12.11.2019", 4342, marks2);
    person[2] = new Teacher("Sam", "M", "02.02.1995", 10, "08.08.2020", "teacher", "CandidateSciences", "Docent");
    person[3] = new Teacher("Mira", "W", "07.01.1990", 5, "02.06.2017", "teacher", "DoctorScience", "Professor");
    
    for (int i = 0; i < NUM; i++) {
        Teacher* teacher = dynamic_cast<Teacher*>(person[i]);
        if (teacher) teacher->print();
        else {
            Student* student = dynamic_cast<Student*>(person[i]);
            if (student) student->print();
        }
    }
}