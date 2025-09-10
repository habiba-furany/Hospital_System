#include <iostream>
#include "hospital.h"
#include "DataManager.h"
#include<Windows.h>
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
    cout << "\t\t\t\t|  10. View Medical History\t  |" << endl;
    cout << "\t\t\t\t|  11. Exit\t\t\t  |" << endl;
<<<<<<< HEAD
    cout << "\t\t\t\t  ===============================" << endl;
=======
    cout << "\t\t\t\t|  =============================" << endl;
>>>>>>> e29fa8e2a7b8b8dbef75808ae3325f397587285e

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
            system("cls");
            cout << "\t\t\t\t**********************" << endl;
            cout << "\t\t\t\t*** Update Doctor  ***" << endl;
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
            system("cls");
            cout << "\t\t\t\t********************" << endl;
            cout << "\t\t\t\t*** Update Staff ***" << endl;
            cout << "\t\t\t\t********************" << endl;
            int id;
            cout << "\t\t\t\tEnter Staff ID to update: ";
            cin >> id;
            h.updateStaff(id);
            Sleep(2000);
            system("cls");
            break;
        }
        case 7: {
            system("cls");
            cout << "\t\t\t\t**********************" << endl;
            cout << "\t\t\t\t*** Search Patient ***" << endl;
            cout << "\t\t\t\t**********************" << endl;
            int id;
            cout << "\t\t\t\tEnter Patient ID to search: ";
            cin >> id;
<<<<<<< HEAD
            h.searchPatient(id);
            cout << "\t\t\t\tback to main menu [Y] : ";
            char c;
            cin >> c;
            if (c == 'Y' || c == 'y')system("cls");
=======
            bool found = h.searchPatient(id);
            if (!found) {
                cout << "\t\t\t\tPatient not found." << endl;
            }
            cout << "Press enter to finish" << endl;
            cin.ignore();
            cin.get();
            system("cls");
>>>>>>> e29fa8e2a7b8b8dbef75808ae3325f397587285e
            break;
        }
        case 8: {
            system("cls");
            cout << "\t\t\t\t***********************" << endl;
            cout << "\t\t\t\t*** Search Employee ***" << endl;
            cout << "\t\t\t\t***********************" << endl;
            int id;
            cout << "\t\t\t\tEnter Employee ID to search: ";
            cin >> id;
            h.searchEmployee(id);
<<<<<<< HEAD
            cout << "\t\t\t\tback to main menu [Y] : ";
            char c;
            cin >> c;
            if (c == 'Y' || c == 'y')system("cls");
=======
            cout << "Press enter to finish" << endl;
            cin.ignore();
            cin.get();
            system("cls");
>>>>>>> e29fa8e2a7b8b8dbef75808ae3325f397587285e
            break;
        }
        case 9: {
            system("cls");
            cout << "\t\t\t\t***************" << endl;
            cout << "\t\t\t\t*** Dequeue ***" << endl;
            cout << "\t\t\t\t***************" << endl;
            int docId;
            cout << "\t\t\t\tEnter Doctor ID to remove a patient from: ";
            cin >> docId;
            h.dequeuePatient(docId);
            Sleep(2000);
            system("cls");
            break;
        }
        case 10: {
            system("cls");
            cout << "\t\t\t\t***************" << endl;
            cout << "\t\t\t\t*** History ***" << endl;
            cout << "\t\t\t\t***************" << endl;
            int id;
<<<<<<< HEAD
            cout << "\t\t\t\tEnter Patient ID to search: ";
            cin >> id;
            p.showHistory(id);
            cout << "\t\t\t\tback to main menu [Y] : ";
            char c;
            cin >> c;
            if (c == 'Y' || c == 'y')system("cls");
=======
            cout << "Enter Patient ID to view medical history: ";
            cin >> id;
            p.showHistory(id);
            cout << "Press enter to finish" << endl;
            cin.ignore();
            cin.get();
            system("cls");
>>>>>>> e29fa8e2a7b8b8dbef75808ae3325f397587285e
             break;
        }
        case 11: {
            break;
        }
        default: {
<<<<<<< HEAD
            system("cls");
            cout << "\t\t\t\tInvalid choice. Please try again." << endl;
=======
            cout << "Invalid choice. Please try again." << endl;
            Sleep(2000);
            system("cls");
>>>>>>> e29fa8e2a7b8b8dbef75808ae3325f397587285e
        }
        }
    } while (choice != 11);

    return 0;
}