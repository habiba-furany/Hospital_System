#include <iostream>
#include "hospital.h"
#include "DataManager.h"
#include<Windows.h>
using namespace std;

void displayMainMenu() {
    cout << "\n=== Hospital Management System ===" << endl;
    cout << "1. Add Patient" << endl;
    cout << "2. Add Doctor" << endl;
    cout << "3. Add Staff" << endl;
    cout << "4. Update Patient" << endl;
    cout << "5. Update Doctor" << endl;
    cout << "6. Update Staff" << endl;
    cout << "7. Search Patient" << endl;
    cout << "8. Search Employee" << endl;
    cout << "9. Remove Patient from Doctor" << endl;
    cout << "10. View Medical History" << endl;
    cout << "11. Display All Data" << endl;
    cout << "12. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    hospital h;
    DataManager dm;
    dm.loadData(); 

    int choice;
    do {
        displayMainMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            system("cls");
            cout << "*** Add Patient ***" << endl;
            h.addPatient();
            Sleep(2000);
            system("cls");
            break;
        }
        case 2: {
            system("cls");
            cout << "*** Add Doctor ***" << endl;
            h.addDoctor();
            system("cls");
            cout << "=============================\n";
            cout << "  Doctor added successfully \n";
            cout << "=============================\n";
            Sleep(2000);
            system("cls");
            break;
        }
        case 3: {
            system("cls");
            cout << "*** Add Doctor ***" << endl;
            h.addStaff();
            system("cls");
            cout << "=============================\n";
            cout << "  Staff added successfully \n";
            cout << "=============================\n";
            Sleep(2000);
            system("cls");
            break;
        }
        case 4: {
            int id;
            cout << "Enter Patient ID to update: ";
            cin >> id;
            h.updatePatient(id);
            break;
        }
        case 5: {
            int id;
            cout << "Enter Doctor ID to update: ";
            cin >> id;
            h.updateDoctor(id);
            break;
        }
        case 6: {
            int id;
            cout << "Enter Staff ID to update: ";
            cin >> id;
            h.updateStaff(id);
            break;
        }
        case 7: {
            int id;
            cout << "Enter Patient ID to search: ";
            cin >> id;
            h.searchPatient(id);
            break;
        }
        case 8: {
            int id;
            cout << "Enter Employee ID to search: ";
            cin >> id;
            h.searchEmployee(id);
            break;
        }
        case 9: {
            int docId;
            cout << "Enter Doctor ID to remove a patient from: ";
            cin >> docId;
            h.dequeuePatient(docId);
            break;
        }
        case 10: {
            cout << "Exiting system. Goodbye!" << endl;
            break;
        }
        default: {
            cout << "Invalid choice. Please try again." << endl;
        }
        }
    } while (choice != 10);

    return 0;
}