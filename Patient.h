
#pragma once
#include "Person.h"
#include <iostream>
#include <string>
#include <vector>
#include "DataManager.h"
class Doctor;

using namespace std;


class Patient : public Person {
    DataManager& dataManager;

private:
    string disease;
    vector<string> medicalHistory;

public:
    Patient(string name, char gender, int age, int id, string disease, DataManager& dm);


    Patient(DataManager& dm)
        : Person("", ' ', 0, 0), dataManager(dm), disease("") {
    }


    void setDisease(string d);
    string getDisease() const;

    void addReport(Patient* patient, Doctor* doctor);
    void showHistory(int Patient_id);

    void display() const override;
};
