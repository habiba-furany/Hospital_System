#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
using namespace std;


class Person
{

protected:
	string name;
	char gender;
	int age, id;


public:
	//setter
	void setName(string name);
	void setGender(char gender);
	void setAge(int age);
	void setId(int id);

	//getter
	string getName() const;
	char getGender() const;
	int getAge() const;
	int getId() const;

	virtual void display() const;

	//constructor & destructor
	Person();
	Person(string name, char gender, int age, int id);
	virtual ~Person();
};

#endif // PERSON_H
