#pragma once
#include "Employee.h"
#include "Patient.h"
#include <queue>
#include <vector>
#include <string>

class Patient;
using namespace std;

class Doctor : public Employee {
private:
    static const int MAX_PATIENTS = 20; // Maximum number of patients a doctor can handle
   
    string specialization;
    int patient_number;
    queue<Patient> patient_queue;

public:
    // Constructors & Destructor
    Doctor();
    Doctor(string name, char gender, int age, int id, double salary, string spec, int patient_num);
    ~Doctor();

    // Setters & Getters
    void setSpecialization(string spec);
    void setPatient_number(int n);
    string getSpecialization() const;
    int getPatient_number() const;

    // Display function
    void display() const override;

    // Queue operations
    void enqueue(Patient patient);
    Patient dequeue();

    // Appointment scheduling
    // must for organizing patient ....
    bool Appointments();

};
