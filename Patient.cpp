#include "Patient.h"
#include "DataManager.h"
#include "Doctor.h"
#include <iostream>
using namespace std;

Patient::Patient(string name, char gender, int age, int id, string disease)
    : Person(name, gender, age, id), disease(disease) {
}

void Patient::setDisease(string d) { disease = d; }
string Patient::getDisease() const { return disease; }

void Patient::display() const {
    cout << "information about Patient " << endl;
    cout << "Name is : " << name << endl;
    cout << "Gender is : " << gender << endl;
    cout << "Age is : " << age << endl;
    cout << "ID is : " << id << endl;
}

void Patient::addReport(Patient& patient, Doctor* doctor) {
    vector<string> prescriptionData;
    cout << "Add the prescription for the patient." << endl;
    string line;
    prescriptionData.push_back(to_string(patient.getId()) + "\n");
    while (true) {
        cout << "Time : ";
        cin >> line;
        prescriptionData.push_back("Time : " + line);
        prescriptionData.push_back("\nDoctor :" + doctor->getName());
        cout << "Enter medications for the patient (type 'done' to finish):\n";

        while (true) {
            cout << "\nMedication: ";
            cin >> line;
            cout << "\nMedication: ";
            if (line == "done") break;
            prescriptionData.push_back("\n" + line);
        }
        prescriptionData.push_back("\n###\n");
    }
    dataManager.saveMedicalHistory(int(patient.getId()), prescriptionData);
}

void Patient::showHistory(int Patient_id) {
    dataManager.loadData();
    for (const auto& patient : dataManager.listOfPatient) {
        if (patient.getId() == Patient_id) {
            vector<string> history = dataManager.loadMedicalHistory(Patient_id);
            cout << "Medical History for Patient ID " << Patient_id << ":\n";
            for (const auto& entry : history) {
                cout << entry;
            }
            cout << endl;
            return;
        }
    }
    cout << "Patient not found." << endl;
}
