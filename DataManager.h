#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Patient;
class Employee;
class Doctor;
class Staff;

class DataManager {
public:

    // make 3 vectors for patients, doctors, and staff to make it easier to use them in functions......
    vector<Patient*> listOfPatient;
    vector<Doctor*> listOfDoctors;
    vector<Staff*> listOfStaff;

    void loadData();
    void saveData();
    vector<Employee*> getEmployees();

    // very important for getting medical history easily
    vector<string> loadMedicalHistory(int patientId);
    void saveMedicalHistory(int patientId, string history);
};
