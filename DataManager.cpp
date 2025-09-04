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
        // Load patient data
        ifstream inFile("Patients.txt");
        if (!inFile) throw runtime_error("Error opening Patients.txt");

        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            Patient p;
            string temp;
            getline(ss, temp, ','); p.setId(stoi(temp));
            getline(ss, temp, ','); p.setName(temp);
            getline(ss, temp, ','); p.setAge(stoi(temp));
            getline(ss, temp, ','); p.setGender(temp[0]);
            listOfPatient.push_back(p);
        }
        inFile.close();

        // Load employee data
        ifstream EmpFile("Employees.txt");
        if (!EmpFile) throw runtime_error("Error opening Employees.txt");

        while (getline(EmpFile, line)) {
            stringstream ss(line);
            string type, temp, name, specialization;
            int id, age;
            char gender;
            double salary;

            getline(ss, type, ',');    // to know the type of employee and insert into the correct vector.
            getline(ss, temp, ','); id = stoi(temp);
            getline(ss, name, ',');
            getline(ss, temp, ','); age = stoi(temp);
            getline(ss, temp, ','); gender = temp[0];
            getline(ss, specialization, ',');
            getline(ss, temp, ','); salary = stod(temp);

            // check the type of employee....
            if (type == "Doctor") {
                Doctor* d = new Doctor();
                d->setId(id); d->setName(name); d->setAge(age);
                d->setGender(gender); d->setSpecialization(specialization);
                d->setSalary(salary);
                listOfDoctors.push_back(d);
            }
            else if (type == "Staff") {
                Staff* s = new Staff();
                s->setId(id); s->setName(name); s->setAge(age);
                s->setGender(gender); s->setSalary(salary);
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
            outFile << p.getId() << "," << p.getName() << ","
                << p.getAge() << "," << p.getGender() << endl;
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
                << s->getAge() << "," << s->getGender() << ",,"
                << s->getSalary() << endl;
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

    vector<string> history;
    string line;
    while (getline(inFile, line)) {
        if (line.find(to_string(patientId)) != string::npos) {
            size_t endPos = line.find("###");
            if (endPos == string::npos) endPos = line.size();

            string content = line.substr(line.find(",") + 1, endPos - line.find(",") - 1);

            history.push_back(content);

            break;
        }
    }

    inFile.close();
    return history;
}


void DataManager::saveMedicalHistory(int patientId, const vector<string>& newHistory) {
    vector<string> allLines;
    ifstream inFile("MedicalHistory.txt");
    if (inFile) {
        string line;
        while (getline(inFile, line)) {
            allLines.push_back(line);
        }
        inFile.close();
    }

    ofstream outFile("MedicalHistory.txt");
    if (!outFile) {
        cerr << "Error opening MedicalHistory.txt" << endl;
        return;
    }

    bool patientFound = false;
    for (auto& line : allLines) {
        if (line.find("PatientID:" + to_string(patientId)) != string::npos) {
            patientFound = true;

            size_t pos = line.find("###");
            if (pos != string::npos) line = line.substr(0, pos);

            for (const auto& entry : newHistory) {
                line += entry;
            }

            line += "\n ###";
        }

        outFile << line << endl;
    }

    if (!patientFound) {
        string newLine = to_string(patientId) + "\n";
        for (const auto& entry : newHistory) {
            newLine += entry;
        }
        newLine += "\n###";
        outFile << newLine << endl;
    }

    outFile.close();
}
