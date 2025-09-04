#pragma once
#include <iostream>
#include "Person.h"

class Employee : public Person
{
private:
    double salary;

public:
    // constructors & destructor
    Employee();
    Employee(std::string name, char gender, int age, int id, double salary);
    ~Employee();

    // setters & getters
    double getSalary() const;
    void setSalary(double s);

    // display function
    void display() const override;
};
