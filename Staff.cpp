
#include "Staff.h"
using namespace std;

// Default constructor
Staff::Staff() : Employee(), position("unknown") {}

// Parameterized constructor
Staff::Staff(string name, char gender, int age, int id, double salary, string pos)
    : Employee(name, gender, age, id, salary), position(pos) {
}

// Destructor
Staff::~Staff() {}

// Setter and Getter
void Staff::setPosition(string pos) {
    position = pos;
}

string Staff::getPosition() const {
    return position;
}

// Display function
void Staff::display() const {
    Employee::display();
    std::cout << "Position is: " << position << endl;
}