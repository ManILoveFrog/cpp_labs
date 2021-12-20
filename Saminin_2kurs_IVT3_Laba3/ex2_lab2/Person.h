#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    string gender;
    string birthday;
public:
    Person();
    Person(string name, string gender, string birthday);
    void setName(string name);
    void setGender(string gender);
    void setBirthday(string birthday);
    virtual void print() const = 0;
    string getName();
    string getGender();
    string getBirthday();
};