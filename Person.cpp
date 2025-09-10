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
	cout << "\t\t\t\tinformation about " << name << endl;
	cout << "\t\t\t\tName is : " << name << endl;
	cout << "\t\t\t\tGender is : " << gender << endl;
	cout << "\t\t\t\tAge is : " << age << endl;
	cout << "\t\t\t\tID is : " << id << endl;
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
