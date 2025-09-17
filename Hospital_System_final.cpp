#include <iostream>
#include "hospital.h"
#include "DataManager.h"
#include <Windows.h>
using namespace std;

void displayMainMenu() {
    cout << "\t\t\t\t===================================" << endl;
    cout << "\t\t\t\t===  Hospital Management System ===" << endl;
    cout << "\t\t\t\t===================================" << endl;
    cout << "\t\t\t\t|  1. Add Patient\t\t  |" << endl;
    cout << "\t\t\t\t|  2. Add Doctor\t\t  |" << endl;
    cout << "\t\t\t\t|  3. Add Staff\t\t\t  |" << endl;
    cout << "\t\t\t\t|  4. Update Patient\t\t  |" << endl;
    cout << "\t\t\t\t|  5. Update Doctor\t\t  |" << endl;
    cout << "\t\t\t\t|  6. Update Staff\t\t  |" << endl;
    cout << "\t\t\t\t|  7. Search Patient\t\t  |" << endl;
    cout << "\t\t\t\t|  8. Search Employee\t \t  |" << endl;
    cout << "\t\t\t\t|  9. Remove Patient from Doctor  |" << endl;
    cout << "\t\t\t\t| 10. View Medical History\t  |" << endl;
    cout << "\t\t\t\t| 11. Add Specialization\t  |" << endl;
    cout << "\t\t\t\t| 12. Exit\t\t\t  |" << endl;
    cout << "\t\t\t\t===================================" << endl;
    cout << "\t\t\t\t  Enter your choice: ";
}

int main() {

    DataManager dm;
    hospital h(dm);
    Patient p(dm);
    dm.loadData();
    dm.loadCurrentPatients(dm.listOfDoctors, dm.listOfPatient);

    int choice;
    do {
        try {
            displayMainMenu();
            cin >> choice;
            if (!cin) {
                throw runtime_error("\t\t\t\tInvalid input. Please enter a number.");
            }

            switch (choice) {
            case 1: {
                system("cls");
                cout << "\t\t\t\t*** Add Patient ***" << endl;
                try {
                    h.addPatient();
                }
                catch (const exception& e) {
                    cout << "\t\t\t\t Add Patient Error " << e.what() << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                Sleep(2000);
                system("cls");
                break;
            }
            case 2: {
                system("cls");
                cout << "\t\t\t\t*** Add Doctor ***" << endl;
                try {
                    h.addDoctor();
                    cout << "\t\t\t\tDoctor added succesfully" << endl;
                }
                catch (const exception& e) {
                    cout << "\t\t\t\t Add Doctor Error " << e.what() << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                Sleep(2000);
                system("cls");
                break;
            }
            case 3: {
                system("cls");
                cout << "\t\t\t\t*** Add Staff ***" << endl;
                try {
                    h.addStaff();
                    cout << "\t\t\t\t=============================\n";
                    cout << "\t\t\t\t  Staff added successfully \n";
                    cout << "\t\t\t\t=============================\n";
                }
                catch (const exception& e) {
                    cout << "\t\t\t\t Add Staff Error  " << e.what() << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                Sleep(2000);
                system("cls");
                break;
            }
            case 4: {
                system("cls");
                cout << "\t\t\t\t*** Update Patient ***" << endl;
                int id = h.getInt("\t\t\t\tEnter Patient ID: ");
                h.updatePatient(id);
                cout << "\t\t\t\tPatient updated succesfully" << endl;
                Sleep(2000);
                system("cls");
                break;
            }
            case 5: {
                system("cls");
                cout << "\t\t\t\t*** Update Doctor ***" << endl;
                int id = h.getInt("\t\t\t\tEnter Doctor ID: ");
                h.updateDoctor(id);
                cout << "\t\t\t\tDoctor updated succesfully" << endl;
                Sleep(2000);
                system("cls");
                break;
            }
            case 6: {
                system("cls");
                cout << "\t\t\t\t*** Update Staff ***" << endl;
                int id = h.getInt("\t\t\t\tEnter Staff ID: ");
                h.updateStaff(id);
                cout << "\t\t\t\tStaff updated succesfully" << endl;
                Sleep(2000);
                system("cls");
                break;
            }
            case 7: {
                system("cls");
                cout << "\t\t\t\t*** Search Patient ***" << endl;
                string att;
                cout << "\t\t\t\tEnter Patient Name or ID: ";
                cin.ignore(); 
                getline(cin, att);
                bool found = h.searchPatient(att);
                if (!found) cout << "\t\t\t\tPatient not found." << endl;
                cout << "\t\t\t\tPress enter to return...";
                cin.get();
                system("cls");
                break;
            }
            case 8: {
                system("cls");
                cout << "\t\t\t\t*** Search Employee ***" << endl;
                string att;
                cout << "\t\t\t\tEnter Employee Name or ID: ";
                cin.ignore();
                getline(cin, att);
                h.searchEmployee(att);
                cout << "\t\t\t\tPress enter to return...";
                cin.get();
                system("cls");
                break;
            }
            case 9: {
                system("cls");
                cout << "\t\t\t\t*** Dequeue Patient ***" << endl;
                int docId = h.getInt("\t\t\t\tEnter Doctor ID: ");
                h.dequeuePatient(docId);
                Sleep(2000);
                system("cls");
                break;
            }
            case 10: {
                system("cls");
                cout << "\t\t\t\t*** View Medical History ***" << endl;
                int id = h.getInt("\t\t\t\tEnter Patient ID: ");
                if (!h.searchPatient(to_string(id))) cout << "\t\t\t\tPatient not found" << endl;
                else p.showHistory(id);
                cout << "\t\t\t\tPress enter to return...";
                cin.ignore();
                cin.get();
                system("cls");
                break;
            }
            case 11: {
                system("cls");

                string nameOfClinic;
                cout << "\t\t\t\tEnter The name of the clinic: ";
                getline(cin >> ws, nameOfClinic);

                if (h.addClinic(nameOfClinic)) {
                    cout << "\t\t\t\tUpdated Specializations:\n";
                    for (auto& spec : h.specializations) {
                        cout << "\t\t\t\t- " << spec << endl;
                    }
                    cout << "\t\t\t\tClinic added successfully.\n";
                }
                else {

                    cout << "\t\t\t\tClinic already exists.\n";
                }

                cout << "\t\t\t\tPress enter to return...";
                cin.get();
                system("cls");
                break;

            }
            case 12: {
                cout << "\t\t\t\tExiting system, Good Bye!" << endl;
                break;
            }
            default: {
                cout << "\t\t\t\tInvalid choice. Try again." << endl;
                Sleep(2000);
                system("cls");
            }
            }
        }
        catch (const exception& e) {
            cout << "\t\t\t\tError  " << e.what() << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            Sleep(2000);
            system("cls");
        }
    } while (choice != 12);
    dm.saveCurrentPatients(dm.listOfDoctors);

    return 0;
}