#pragma once
#include<iostream>
#include<vector>
#include "Patient.h"
#include "Employee.h"
#include "DataManager.h"
#include "Doctor.h"
#include "Staff.h"
class hospital
{
private:
	DataManager dataManager;
	Doctor doctor;
	Patient patient;
	vector<string> specializations = {
	"Cardiology","Neurology","Orthopedics","Pediatrics","Dermatology",
	"Gastroenterology","Radiology","Oncology","Endocrinology","Nephrology",
	"Cardiothoracic Surgery"
	};

public:

	// Add a person
	void addPatient();
	void addDoctor();
	void addStaff();

	// Update a person
	void updateStaff(int id);
	void updateDoctor(int id);
	void updatePatient(int id);

	// Search for a person
	void searchEmployee(int id);
	void searchPatient(int id);

	// Remove a person
	void removePatient(int Doc_ID);
	void removeEmployee(int emp_ID);


};

