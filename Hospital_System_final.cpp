#include <iostream>
#include "hospital.h"
#include "DataManager.h"
#include<Windows.h>
using namespace std;

void displayMainMenu() {
    cout << "\t\t\t\t===================================" << endl;
    cout << "\t\t\t\t=== Hospital Management System ===" << endl;
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
    cout << "\t\t\t\t|  10. View Medical History\t  |" << endl;
    cout << "\t\t\t\t|  11. Display All Data\t\t  |" << endl;
    cout << "\t\t\t\t|  12. Exit\t\t\t  |" << endl;
    cout << "\t\t\t\t|  =============================" << endl;

    cout << "\t\t\t\t  Enter your choice: ";
}

int main() {
    DataManager dm;
    hospital h(dm);
    Patient p(dm);
    dm.loadData(); 
    
    
    int choice;
    do {
        displayMainMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            system("cls");
            cout << "\t\t\t\t*********************" << endl;
            cout << "\t\t\t\t***  Add Patient  ***" << endl;
            cout << "\t\t\t\t*********************" << endl;
            h.addPatient();
            Sleep(3000);
            system("cls");
            break;
        }
        case 2: {
            system("cls");
            cout << "\t\t\t\t*********************" << endl;
            cout << "\t\t\t\t***  Add  Doctor  ***" << endl;
            cout << "\t\t\t\t*********************" << endl;
            h.addDoctor();
            Sleep(2000);
            system("cls");
            //cout << "\t\t\t\t=============================\n";
            //cout << "\t\t\t\t  Doctor added successfully \n";
            //cout << "\t\t\t\t=============================\n";
            //Sleep(2000);
            //system("cls");
            break;
        }
        case 3: {
            system("cls");
            cout << "\t\t\t\t*********************" << endl;
            cout << "\t\t\t\t***   Add Staff   ***" << endl;
            cout << "\t\t\t\t*********************" << endl;
            h.addStaff();
            Sleep(2000);
            system("cls");
            break;
        }
        case 4: {
            system("cls");
            cout << "\t\t\t\t**********************" << endl;
            cout << "\t\t\t\t*** Update Patient ***" << endl;
            cout << "\t\t\t\t**********************" << endl;
            int id;
            cout << "\t\t\t\tEnter Patient ID to update: ";
            cin >> id;
            h.updatePatient(id);        
            Sleep(2000);
            system("cls");
            break;
        }
        case 5: {
            cout << "\t\t\t\t**********************" << endl;
            cout << "\t\t\t\t*** Update Doctor ***" << endl;
            cout << "\t\t\t\t**********************" << endl;
            int id;
            cout << "\t\t\t\tEnter Doctor ID to update: ";
            cin >> id;
            h.updateDoctor(id);   
            Sleep(2000);
            system("cls");
            break;
        }
        case 6: {
            int id;
            cout << "Enter Staff ID to update: ";
            cin >> id;
            h.updateStaff(id);
            Sleep(2000);
            system("cls");
            break;
        }
        case 7: {
            int id;
            cout << "Enter Patient ID to search: ";
            cin >> id;
            h.searchPatient(id);
            Sleep(2000);
            system("cls");
            break;
        }
        case 8: {
            int id;
            cout << "Enter Employee ID to search: ";
            cin >> id;
            h.searchEmployee(id);
            Sleep(2000);
            system("cls");
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
            int id;
            cout << "Enter Patient ID to search: ";
            cin >> id;
            p.showHistory(id);
            Sleep(2000);
            system("cls");
             break;
        }
        default: {
            cout << "Invalid choice. Please try again." << endl;
        }
        }
    } while (choice != 10);

    return 0;
}