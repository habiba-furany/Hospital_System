#include "Patient.h"
#include "DataManager.h"
#include "Doctor.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
using namespace std;
Patient::Patient(string name, char gender, int age, int id, string disease, DataManager& dm)
    : Person(name, gender, age, id), dataManager(dm), disease(disease) {
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

void Patient::addReport(Patient* patient, Doctor* doctor) {
    cout << "Add the prescription for the patient." << endl;
    string line;
    vector<string> medications;

    /*cout << "Time: ";
    cin >> line;
    string time = line;*/

    //add the current time 
    time_t now = time(0); 
    tm ltm;
    localtime_s(&ltm, &now);
    ostringstream timeStream;
    timeStream << put_time(&ltm, "%Y-%m-%d %H:%M");  
    string time = timeStream.str();

    cout << "\t\t\t\tEnter medications for the patient (type 'done' to finish):\n";
    while (true) {
        cout << "\t\t\t\tMedication: ";
        cin >> line;
        if (line == "done") break;
        medications.push_back(line);
    }

    string prescription = "PatientID:" + to_string(patient->getId()) +
        ",Time:" + time +
        ",Doctor:" + doctor->getName()+",Medicien:";

    for (const auto& med : medications) {
        prescription += "," + med;
    }

    cout << "\t\t\t\tThe prescription is recorded successfully." << endl;
    dataManager.saveMedicalHistory(int(patient->getId()), prescription);
}

void Patient::showHistory(int Patient_id) {
    vector<string> history = dataManager.loadMedicalHistory(Patient_id);

    if (history.empty()) {
        cout << "\t\t\t\tNo medical history found for patient ID: " << Patient_id << endl;
    }
    else {
        cout << "\t\t\t\tMedical history for patient ID " << Patient_id << ":\n";
        for (const auto& entry : history) {
            cout << entry << endl;
        }
    }
}
