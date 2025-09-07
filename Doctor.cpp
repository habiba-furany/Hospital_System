#include "Doctor.h"
#include "Patient.h"
#include <iostream>
using namespace std;

// Default constructor
Doctor::Doctor() : Employee(), specialization("unknown"), patient_number(0) {}

// Parameterized constructor
Doctor::Doctor(string name, char gender, int age, int id, double salary, string spec, int patient_num)
    : Employee(name, gender, age, id, salary), specialization(spec), patient_number(patient_num) {
}

// Destructor
Doctor::~Doctor() {}

// Setters
void Doctor::setSpecialization(string spec) { specialization = spec; }
void Doctor::setPatient_number(int n) { patient_number = n; }

// Getters
string Doctor::getSpecialization() const { return specialization; }
int Doctor::getPatient_number() const { return patient_number; }

// Display function
void Doctor::display() const {
    Employee::display();
    cout << "Specialization is " << specialization << endl;
    cout << "Number of patients is " << patient_number << endl;
}

// Queue operations
void Doctor::enqueue(Patient patient) {
    if (patient_number < MAX_PATIENTS) {
        patient_queue.push(patient);
        patient_number++;
    }
    else {
        cout << "The doctor can't take more patients." << endl;
    }
}

Patient Doctor::dequeue() {
    if (patient_queue.empty()) {
        cout << "The doctor doesn't have patients to remove." << endl;
        return Patient();  // Return a default Patient object
    }
    else {
        Patient patient = patient_queue.front();
        patient_queue.pop();
        patient_number--;
        return patient;
    }
}

bool Doctor::Appointments() {
    if (patient_number < MAX_PATIENTS) {
        return true;
    }
    return false;
}

