#include "hospital.h"
#include "Doctor.h"
// add a patient .......
void hospital::addPatient() {
    int age, id;
    string name;
    char gender;
    cout << "Enter information" << endl;
    cout << "Name : ";
    /*cin >> name;*/
    cin.ignore(); // Clear input buffer
    getline(cin, name);
    cout << "Age : ";
    cin >> age;
    cout << "ID : ";
    cin >> id;
    cout << "Gender (M/F) : ";
    cin >> gender;
    Patient p;
    p.setName(name);
    p.setAge(age);
    p.setId(id);
    p.setGender(gender);
    // Assign patient to a doctor based on specialization
    system("cls");
    cout << "which clinic do you want to assign the patient to? "<<endl;
    cout << "1.  (Cardiology)\n";
    cout << "2.  (Neurology)\n";
    cout << "3.  (Orthopedics)\n";
    cout << "4.  (Pediatrics)\n";
    cout << "5.  (Dermatology)\n";
    cout << "6.  (Gastroenterology)\n";
    cout << "7.  (Radiology)\n";
    cout << "8.  (Nephrology)\n";
    cout << "9.  (Cardiothoracic Surgery)\n";
    cout << "10. (Ophthalmology)\n";
    cout << "11. (Psychiatry)\n";

    cout << "Enter your choice (1-11): ";
    int choice;
    cin >> choice;
    system("cls");
    // check if choice is valid
    if (choice < 1 || choice > 11) {
        cout << "Invalid choice. Please select a valid clinic." << endl;
        return;
    }


    string selectedSpec = specializations[choice - 1];

    vector<Doctor*> availableDoctors;
    for (auto& doctor : dataManager.listOfDoctors) {
        if (doctor->getSpecialization() == selectedSpec && doctor->Appointments()) {
            availableDoctors.push_back(doctor);
        }
    }

    if (availableDoctors.empty()) {
        cout << "No available doctor found for the selected clinic." << endl;
        return;
    }

    // show all available doctors to the patient can choose....
    cout << "Available doctors:\n";
    for (int i = 0; i < availableDoctors.size(); i++) {
        cout << i + 1 << ". Dr. " << availableDoctors[i]->getName()
            << " (Patients: " << availableDoctors[i]->getPatient_number() << ")\n";
    }

    // the patient selects a doctor ....
    cout << "Select a doctor by number: ";
    int docChoice;
    cin >> docChoice;

    if (docChoice < 1 || docChoice >(int)availableDoctors.size()) {
        cout << "Invalid choice." << endl;
        return;
    }

    Doctor* reqDoctor = availableDoctors[docChoice - 1];
    cout << "Patient assigned to Dr. " << reqDoctor->getName()
        << " (" << reqDoctor->getSpecialization() << ")" << endl;

    //add patient to doctor's queue.....
    reqDoctor->enqueue(p);

    dataManager.listOfPatient.push_back(p);
    dataManager.saveData();
}

void hospital::addDoctor() {
    string name, specialization;
    int id, age;
    double salary;
    char gender;
    cout << "Enter doctor's name: ";
    cin.ignore(); 
    getline(cin, name);
    cout << "Enter doctor's ID: ";
    cin >> id;
    cout << "Enter doctor's Age: ";
    cin >> age;
    cout << "Enter doctor's Gender (M/F): ";
    cin >> gender;
    cout << "Enter doctor's specialization: " << endl;

    for (int i = 0; i < specializations.size(); i++) {
        cout << i + 1 << ". " << specializations[i] << endl;
    }

    int specChoice;
    cout << "Enter your choice (1-" << specializations.size() << "): ";
    cin >> specChoice;

    if (specChoice < 1 || specChoice > specializations.size()) {
        cout << "Invalid choice. Using default specialization (General)." << endl;
        specialization = "General";
    }
    else {
        specialization = specializations[specChoice - 1];
    }
    
    cout << "Enter doctor's salary: ";
    cin >> salary;


    Doctor* d = new Doctor();
    d->setName(name);
    d->setId(id);
    d->setSpecialization(specialization);
    d->setAge(age);
    d->setSalary(salary);
    d->setGender(gender);

    dataManager.listOfDoctors.push_back(d);
    dataManager.saveData();
}

void hospital::addStaff() {
    string name , position;
    int id, age;
    double salary;
    char gender;
    cout << "Enter staff's name: ";
    cin.ignore(); 
    getline(cin, name);
    cout << "Enter staff's ID: ";
    cin >> id;
    cout << "Enter staff's Age: ";
    cin >> age;
    cout << "Enter staff's Gender (M/F): ";
    cin >> gender;
    cout << "Enter staff's Position: ";
    cin.ignore(); 
    getline(cin, position);
    cout << "Enter staff's salary: ";
    cin >> salary;


    Staff* s = new Staff();
    s->setName(name);
    s->setId(id);
    s->setAge(age);
    s->setSalary(salary);
    s->setPosition(position);
    s->setGender(gender);

    dataManager.listOfStaff.push_back(s);
    dataManager.saveData();
}


// update a person .....
void hospital::updatePatient(int id)
{
    dataManager.loadData();
    for (auto& patient : dataManager.listOfPatient)
    {
        if (patient.getId() == id)
        {
            int choice;
            cout << "Updating information for patient ID: " << id << endl;
            cout << "Select what you want to update:\n";
            cout << "1. Name\n";
            cout << "2. Age\n";
            cout << "3. Gender\n";
            cout << "Enter your choice (1-3): ";
            cin >> choice;

            switch (choice)
            {
            case 1:
            {
                string name;
                cout << "Enter new name (current: " << patient.getName() << "): ";
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
                std::getline(cin, name);
                patient.setName(name);
                cout << "Name updated successfully." << endl;
                break;
            }
            case 2:
            {
                int age;
                cout << "Enter new age (current: " << patient.getAge() << "): ";
                cin >> age;
                patient.setAge(age);
                cout << "Age updated successfully." << endl;
                break;
            }
            case 3:
            {
                char gender;
                cout << "Enter new gender (current: " << patient.getGender() << "): ";
                cin >> gender;
                patient.setGender(gender);
                cout << "Gender updated successfully." << endl;
                break;
            }
            default:
                cout << "Invalid choice." << endl;
            }
            dataManager.saveData();
            return;
        }
    }

    cout << "Patient not found." << endl;
}



void hospital::updateDoctor(int id)
{
    dataManager.loadData();
    for (auto& doc : dataManager.listOfDoctors)
    {
        if (doc && doc->getId() == id)
        {
            int choice;
            cout << "Updating information for doctor ID: " << id << endl;
            cout << "Select what you want to update:\n";
            cout << "1. Name\n";
            cout << "2. Age\n";
            cout << "3. Gender\n";
            cout << "4. Specialization\n";
            cout << "5. Salary\n";
            cout << "Enter your choice (1-5): ";
            cin >> choice;

            switch (choice)
            {
            case 1:
            {
                string name;
                cout << "Enter new name (current: " << doc->getName() << "): ";
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(cin, name);
                doc->setName(name);
                cout << "Name updated successfully." << endl;
                break;
            }
            case 2:
            {
                int age;
                cout << "Enter new age (current: " << doc->getAge() << "): ";
                cin >> age;
                doc->setAge(age);
                cout << "Age updated successfully." << endl;
                break;
            }
            case 3:
            {
                char gender;
                cout << "Enter new gender (current: " << doc->getGender() << "): ";
                cin >> gender;
                doc->setGender(gender);
                cout << "Gender updated successfully." << endl;
                break;
            }
            case 4:
            {
                string specialization;
                cout << "Enter new specialization (current: " << doc->getSpecialization() << "): ";
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(cin, specialization);
                doc->setSpecialization(specialization);
                cout << "Specialization updated successfully." << endl;
                break;
            }
            case 5:
            {
                double salary;
                cout << "Enter new salary (current: " << doc->getSalary() << "): ";
                cin >> salary;
                doc->setSalary(salary);
                cout << "Salary updated successfully." << endl;
                break;
            }
            default:
                cout << "Invalid choice." << endl;
            }
            dataManager.saveData();
            return;
        }
    }
    cout << "Doctor not found." << endl;
}



void hospital::updateStaff(int id)
{
    dataManager.loadData();
    for (auto& staff : dataManager.listOfStaff)
    {
        if (staff && staff->getId() == id)
        {
            int choice;
            cout << "Updating information for staff ID: " << id << endl;
            cout << "Select what you want to update:\n";
            cout << "1. Name\n";
            cout << "2. Age\n";
            cout << "3. Gender\n";
            cout << "4. Position\n";
            cout << "5. Salary\n";
            cout << "Enter your choice (1-5): ";
            cin >> choice;

            switch (choice)
            {
            case 1:
            {
                string name;
                cout << "Enter new name (current: " << staff->getName() << "): ";
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(cin, name);
                staff->setName(name);
                cout << "Name updated successfully." << endl;
                break;
            }
            case 2:
            {
                int age;
                cout << "Enter new age (current: " << staff->getAge() << "): ";
                cin >> age;
                staff->setAge(age);
                cout << "Age updated successfully." << endl;
                break;
            }
            case 3:
            {
                char gender;
                cout << "Enter new gender (current: " << staff->getGender() << "): ";
                cin >> gender;
                staff->setGender(gender);
                cout << "Gender updated successfully." << endl;
                break;
            }
            case 4:
            {
                string position;
                cout << "Enter new position (current: " << staff->getPosition() << "): ";
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(cin, position);
                staff->setPosition(position);
                cout << "Position updated successfully." << endl;
                break;
            }
            case 5:
            {
                double salary;
                cout << "Enter new salary (current: " << staff->getSalary() << "): ";
                cin >> salary;
                staff->setSalary(salary);
                cout << "Salary updated successfully." << endl;
                break;
            }
            default:
                cout << "Invalid choice." << endl;
            }
            dataManager.saveData();
            return;
        }
    }
    cout << "Staff not found." << endl;
}

//search for a patient
void hospital::searchPatient(int id)
{
    dataManager.loadData();
    for (const auto& patient : dataManager.listOfPatient)
    {
        if (patient.getId() == id)
        {
            cout << "Patient found: " << patient.getName() << endl;
            patient.display();
            return;
        }
    }
    cout << "Patient not found." << endl;
}

void hospital::searchEmployee(int id)
{
    dataManager.loadData();
    vector<Employee*> employees = dataManager.getEmployees();
    for (const auto& emp : employees)
    {
        if (emp->getId() == id)
        {
            cout << "Employee found: " << emp->getName() << endl;
            emp->display();
            return;
        }
    }
    cout << "Employee not found." << endl;
}

// Remove a patient
void hospital::dequeuePatient(int Doc_ID)
{
    dataManager.loadData();
    Doctor* doctor = nullptr;
    for (const auto& Doc : dataManager.listOfDoctors)
    {
        if (Doc && Doc->getId() == Doc_ID)
        {
            doctor = Doc;
            break;
        }
    }
    Patient patient = doctor->dequeue();
    patient.addReport(patient, doctor);

}


