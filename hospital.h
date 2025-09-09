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
	DataManager& dataManager;

private:
	Doctor doctor;
	Patient* patient;
	vector<string> specializations = {
		"Cardiology",
		"Neurology",
		"Orthopedics",
		"Pediatrics",
		"Dermatology",
		"Gastroenterology",
		"Radiology",
		"Nephrology",
		"Cardiothoracic Surgery",
		"Ophthalmology",
		"Psychiatry"
	};

public:
	hospital(DataManager& dm) : dataManager(dm) {
		patient= new Patient (dm);
	}

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

	// Remove a patient from doctor's queue
	void dequeuePatient(int Doc_ID);

};

