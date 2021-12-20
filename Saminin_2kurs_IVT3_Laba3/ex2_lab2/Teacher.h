#pragma once
#include "Person.h"
#include "ISalaryCalculation.h"

enum academicDegree {
    DoctorScience,
    CandidateScience,
};

enum academicTitle {
    Proffesor,
    Docent,
};

class Teacher : public Person, public ISalaryCalculation {
public:
    Teacher();
    Teacher(string name, string gender, string birthday, double workExperience, string dateWorkBegin, string post, string academicDegree, string academicTitle);
    void setWorkExperience(double workExperience);
    void setDateWorkBegin(string dateWorkBegin);
    void setPost(string post);
    void setAcademicDegree(string academicDegree);
    void setAcademicTitle(string academicTitle);
    double calculate() const override;
    void print() const override;
private:
    double workExperience;
    string dateWorkBegin;
    string post;
    string academicDegree;
    string academicTitle;
};