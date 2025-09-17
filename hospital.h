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
	

public:
	vector<string> specializations;

	hospital(DataManager& dm) : dataManager(dm) {
		patient= new Patient (dm);
		specializations = dataManager.loadSpecializations();
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
	void searchEmployee(string att);
	bool searchPatient(string att);

	// Remove a patient from doctor's queue
	void dequeuePatient(int Doc_ID);

	// for adding a new clinic (Specialization).
	bool addClinic(string nameClinic);

	// input validation
	int getInt(string prompt);
	double getDouble(string prompt);
	char getGender(string prompt);
	int choiseRange(int a, int b, string prompt);
};

