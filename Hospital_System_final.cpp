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
    cout << "\t\t\t\t| 11. Exit\t\t\t  |" << endl;
    cout << "\t\t\t\t===================================" << endl;
    cout << "\t\t\t\t  ===============================" << endl;
    cout << "\t\t\t\t  Enter your choice: ";
}

int main() {
    DataManager dm;
    hospital h(dm);
    Patient p(dm);
    dm.loadData();

    int choice;
    do {
        try {
            displayMainMenu();
            cin >> choice;
            if (!cin) {
                throw runtime_error("Invalid input. Please enter a number.");
            }

            switch (choice) {
            case 1: {
                system("cls");
                cout << "\t\t\t\t*** Add Patient ***" << endl;
                h.addPatient();
                Sleep(2000);
                system("cls");
                break;
            }
            case 2: {
                system("cls");
                cout << "\t\t\t\t*** Add Doctor ***" << endl;
                h.addDoctor();
                Sleep(2000);
                system("cls");
                break;
            }
            case 3: {
                system("cls");
                cout << "\t\t\t\t*** Add Staff ***" << endl;
                h.addStaff();
                Sleep(2000);
                system("cls");
                break;
            }
            case 4: {
                system("cls");
                cout << "\t\t\t\t*** Update Patient ***" << endl;
                int id;
                cout << "Enter Patient ID: ";
                cin >> id;
                if (!cin) throw runtime_error("Invalid ID format.");
                h.updatePatient(id);
                Sleep(2000);
                system("cls");
                break;
            }
            case 5: {
                system("cls");
                cout << "\t\t\t\t*** Update Doctor ***" << endl;
                int id;
                cout << "Enter Doctor ID: ";
                cin >> id;
                if (!cin) throw runtime_error("Invalid ID format.");
                h.updateDoctor(id);
                Sleep(2000);
                system("cls");
                break;
            }
            case 6: {
                system("cls");
                cout << "\t\t\t\t*** Update Staff ***" << endl;
                int id;
                cout << "Enter Staff ID: ";
                cin >> id;
                if (!cin) throw runtime_error("Invalid ID format.");
                h.updateStaff(id);
                Sleep(2000);
                system("cls");
                break;
            }
            case 7: {
                system("cls");
                cout << "\t\t\t\t*** Search Patient ***" << endl;
                int id;
                cout << "Enter Patient ID: ";
                cin >> id;
                if (!cin) throw runtime_error("Invalid ID format.");
                bool found = h.searchPatient(id);
                if (!found) cout << "Patient not found." << endl;
                cout << "Press enter to return...";
                cin.ignore();
                cin.get();
                system("cls");
                break;
            }
            case 8: {
                system("cls");
                cout << "\t\t\t\t*** Search Employee ***" << endl;
                int id;
                cout << "Enter Employee ID: ";
                cin >> id;
                if (!cin) throw runtime_error("Invalid ID format.");
                h.searchEmployee(id);
                cout << "Press enter to return...";
                cin.ignore();
                cin.get();
                system("cls");
                break;
            }
            case 9: {
                system("cls");
                cout << "\t\t\t\t*** Dequeue Patient ***" << endl;
                int docId;
                cout << "Enter Doctor ID: ";
                cin >> docId;
                if (!cin) throw runtime_error("Invalid ID format.");
                h.dequeuePatient(docId);
                Sleep(2000);
                system("cls");
                break;
            }
            case 10: {
                system("cls");
                cout << "\t\t\t\t*** View Medical History ***" << endl;
                int id;
                cout << "Enter Patient ID: ";
                cin >> id;
                if (!cin) throw runtime_error("Invalid ID format.");
                if (!h.searchPatient(id)) cout << "Patient not found" << endl;
                else p.showHistory(id);
                cout << "Press enter to return...";
                cin.ignore();
                cin.get();
                system("cls");
                break;
            }
            case 11: {
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
            cout << "\t\t\t\t[Error] " << e.what() << endl;
            cin.clear();             
            cin.ignore(10000, '\n'); 
            Sleep(2000);
            system("cls");
        }
    } while (choice != 11);

    return 0;
}
