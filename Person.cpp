#include "person.h"

void Person::setName(string name) { this->name = name; }
void Person::setGender(char gender) { this->gender = gender; }
void Person::setAge(int age) { this->age = age; }
void Person::setId(int id) { this->id = id; }

string Person::getName() const { return name; }
char Person::getGender() const { return gender; }
int Person::getAge() const { return age; }
int Person::getId()  const { return id; }

void Person::display() const
{
	cout << "information about" << name << endl;
	cout << "Name is : " << name << endl;
	cout << "Gender is : " << gender << endl;
	cout << "Age is : " << age << endl;
	cout << "ID is : " << id << endl;
}

Person::Person()
{
	name = "UnKnown";
	gender = '*';
	age = 0;
	id = 0;
}

Person::Person(string name, char gender, int age, int id)
	:name(name), gender(gender), age(age), id(id) {
}


Person::~Person() {}
