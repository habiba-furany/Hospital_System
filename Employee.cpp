#include"Person.h"
#include "Employee.h"
#include <iostream>

// Default constructor
Employee::Employee() : Person(), salary(0.0) {}

// Parameterized constructor
Employee::Employee(std::string name, char gender, int age, int id, double salary)
    : Person(name, gender, age, id), salary(salary) {
}

// Destructor
Employee::~Employee() {}

// Getter
double Employee::getSalary() const {
    return salary;
}

// Setter
void Employee::setSalary(double s) {
    salary = s;
}

// Display
void Employee::display() const {
    Person::display();
    std::cout << "\t\t\t\tSalary is " << salary << std::endl;
}
