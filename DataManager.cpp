#include "DataManager.h"
#include "Patient.h"
#include "Doctor.h"
#include "Staff.h"
#include "Employee.h"
#include <fstream>
#include <sstream>
#include <iostream>

void DataManager::loadData() {
    try {
        listOfPatient.clear();
        for (auto d : listOfDoctors) delete d;
        listOfDoctors.clear();
        for (auto s : listOfStaff) delete s;
        listOfStaff.clear();
        // Load patient data
        ifstream inFile("Patients.txt");
        if (!inFile) throw runtime_error("Error opening Patients.txt");

        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            Patient* p = new Patient(*this);
            string temp;
            getline(ss, temp, ','); p->setId(stoi(temp));
            getline(ss, temp, ','); p->setName(temp);
            getline(ss, temp, ','); p->setAge(stoi(temp));
            getline(ss, temp, ','); p->setGender(temp[0]);
            listOfPatient.push_back(p);
        }
        inFile.close();

        // Load employee data
        ifstream EmpFile("Employees.txt");
        if (!EmpFile) throw runtime_error("Error opening Employees.txt");

        while (getline(EmpFile, line)) {
            stringstream ss(line);
            string type, temp, name,text;
            int id, age;
            char gender;
            double salary;

            getline(ss, type, ',');    // to know the type of employee and insert into the correct vector.
            getline(ss, temp, ','); id = stoi(temp);
            getline(ss, name, ',');
            getline(ss, temp, ','); age = stoi(temp);
            getline(ss, temp, ','); gender = temp[0];
            getline(ss, text, ',');
            getline(ss, temp, ','); salary = stod(temp);

            // check the type of employee....
            if (type == "Doctor") {
                Doctor* d = new Doctor();
                d->setId(id); d->setName(name); d->setAge(age);
                d->setGender(gender); d->setSpecialization(text);
                d->setSalary(salary);
                listOfDoctors.push_back(d);
            }
            else if (type == "Staff") {
                Staff* s = new Staff();
                s->setId(id); s->setName(name); s->setAge(age);
                s->setGender(gender); s->setSalary(salary); s->setPosition(text);
                listOfStaff.push_back(s);
            }
        }
        EmpFile.close();
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
}

void DataManager::saveData() {
    try {
        // Save patient data
        ofstream outFile("Patients.txt");
        if (!outFile) throw runtime_error("Error opening Patients.txt");

        for (const auto& p : listOfPatient) {
            outFile << p->getId() << "," << p->getName() << ","
                << p->getAge() << "," << p->getGender() << endl;
        }
        outFile.close();

        // Save employee data
        ofstream EmpFile("Employees.txt");
        if (!EmpFile) throw runtime_error("Error opening Employees.txt");

        for (const auto& d : listOfDoctors) {
            EmpFile << "Doctor," << d->getId() << "," << d->getName() << ","
                << d->getAge() << "," << d->getGender() << ","
                << d->getSpecialization() << "," << d->getSalary() << endl;
        }
        for (const auto& s : listOfStaff) {
            EmpFile << "Staff," << s->getId() << "," << s->getName() << ","
                << s->getAge() << "," << s->getGender() << ","
                << s->getPosition() << "," << s->getSalary() << endl;
        }
        EmpFile.close();

    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
}

// important for getting all employees in one vector.........
vector<Employee*> DataManager::getEmployees() {
    vector<Employee*> Employees;
    Employees.insert(Employees.end(), listOfDoctors.begin(), listOfDoctors.end());
    Employees.insert(Employees.end(), listOfStaff.begin(), listOfStaff.end());
    return Employees;
}





// for Medical History ......

vector<string> DataManager::loadMedicalHistory(int patientId) {
    ifstream inFile("MedicalHistory.txt");
    if (!inFile) {
        cerr << "Error opening MedicalHistory.txt" << endl;
        return {};
    }

    string header = "PatientID:" + to_string(patientId);
    string line;
    vector<string> history;

    while (getline(inFile, line)) {
        if (line.find(header) != string::npos) {
            size_t pos = line.find(",");
            if (pos != string::npos) {
                history.push_back(line.substr(pos + 1));
            }
            else {
                history.push_back(line);
            }
        }
    }

    inFile.close();
    return history;
}



void DataManager::saveMedicalHistory(int patientId, string history) {
    vector<string> allLines;
    ifstream inFile("MedicalHistory.txt");
    if (inFile) {
        string line;
        while (getline(inFile, line)) {
            allLines.push_back(line);
        }
        inFile.close();
    }

    ofstream outFile("MedicalHistory.txt", ios::app); 
    if (!outFile) {
        cerr << "Error opening MedicalHistory.txt" << endl;
        return;
    }

    outFile << history << endl;


    outFile.close();
}
