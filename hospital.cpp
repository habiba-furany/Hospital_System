#include "hospital.h"
#include "Doctor.h"
//#include <windows.h>
// add a patient .......
void hospital::addPatient() {
    int age, id;
    string name;
    char gender;
    cout << "\t\t\t\tEnter information" << endl;
    cout << "\t\t\t\tName : ";
    /*cin >> name;*/
    cin.ignore(); // Clear input buffer
    getline(cin, name);
    cout << "\t\t\t\tAge : ";
    cin >> age;
    cout << "\t\t\t\tID : ";
    cin >> id;
    cout << "\t\t\t\tGender (M/F) : ";
    cin >> gender;
    patient->setName(name);
    patient->setAge(age);
    patient->setId(id);
    patient->setGender(gender);
    // Assign patient to a doctor based on specialization
    system("cls");           
    cout << "\t\t\t\twhich clinic do you want to assign the patient to? "<<endl; 
    cout << "\t\t\t\t=============================\n";
    cout << "\t\t\t\t1.(Cardiology)\n";
    cout << "\t\t\t\t2.(Neurology)\n";
    cout << "\t\t\t\t3.(Orthopedics)\n";
    cout << "\t\t\t\t4.(Pediatrics)\n";
    cout << "\t\t\t\t5.(Dermatology)\n";
    cout << "\t\t\t\t6.(Gastroenterology)\n";
    cout << "\t\t\t\t7.(Radiology)\n";
    cout << "\t\t\t\t8.(Nephrology)\n";
    cout << "\t\t\t\t9.(Cardiothoracic Surgery)\n";
    cout << "\t\t\t\t10.(Ophthalmology)\n";
    cout << "\t\t\t\t11.(Psychiatry)\n";
    cout << "\t\t\t\t-----------------------------\n";
    cout << "\t\t\t\tEnter your choice (1-11): ";
    int choice;
    cin >> choice;
    system("cls");
    // check if choice is valid
    if (choice < 1 || choice > 11) {
        cout << "\t\t\t\tInvalid choice. Please select a valid clinic." << endl;
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
        cout << "\t\t\t\tNo available doctor found for the selected clinic." << endl;
        return;
    }

    // show all available doctors so the patient can choose....
    cout << "\t\t\t\tAvailable doctors:\n";
    cout << "\t\t\t\t=============================\n";
    for (int i = 0; i < availableDoctors.size(); i++) {
        cout << "\t\t\t\t" << i + 1 << ". Dr. " << availableDoctors[i]->getName()
            << " (Patients: " << availableDoctors[i]->getPatient_number() << ")\n";
    }
    cout << "\t\t\t\t=============================\n";

    // the patient selects a doctor ....
    cout << "\t\t\t\tSelect a doctor by number: ";
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
    reqDoctor->enqueue(patient);

    dataManager.listOfPatient.push_back(patient);
    dataManager.saveData();
}

void hospital::addDoctor() {
    string name, specialization;
    int id, age;
    double salary;
    char gender;
    cout << "\t\t\t\tEnter doctor's name: ";
    cin.ignore(); 
    getline(cin, name);
    cout << "\t\t\t\tEnter doctor's ID: ";
    cin >> id;
    cout << "\t\t\t\tEnter doctor's Age: ";
    cin >> age;
    cout << "\t\t\t\tEnter doctor's Gender (M/F): ";
    cin >> gender;
    cout << "\t\t\t\tEnter doctor's specialization: " << endl;
    cout << "\t\t\t\t=============================\n";
    for (int i = 0; i < specializations.size(); i++) {
        cout << "\t\t\t\t" << i + 1 << ". " << specializations[i] << endl;
    }
    cout << "\t\t\t\t=============================\n";
    int specChoice;
    cout << "\t\t\t\tEnter your choice (1-" << specializations.size() << "): ";
    cin >> specChoice;

    if (specChoice < 1 || specChoice > specializations.size()) {
        cout << "\t\t\t\tInvalid choice. Using default specialization (General)." << endl;
        specialization = "General";
    }
    else {
        specialization = specializations[specChoice - 1];
    }
    
    cout << "\t\t\t\tEnter doctor's salary: ";
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
    cout << "\t\t\t\tDoctor added succesfully" << endl;
}

void hospital::addStaff() {
    string name , position;
    int id, age;
    double salary;
    char gender;
    cout << "\t\t\t\tEnter staff's name: ";
    cin.ignore(); 
    getline(cin, name);
    cout << "\t\t\t\tEnter staff's ID: ";
    cin >> id;
    cout << "\t\t\t\tEnter staff's Age: ";
    cin >> age;
    cout << "\t\t\t\tEnter staff's Gender (M/F): ";
    cin >> gender;
    cout << "\t\t\t\tEnter staff's Position: ";
    cin.ignore(); 
    getline(cin, position);
    cout << "\t\t\t\tEnter staff's salary: ";
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
    cout << "\t\t\t\t=============================\n";
    cout << "\t\t\t\t  Staff added successfully \n";
    cout << "\t\t\t\t=============================\n";
}


// update a person .....
void hospital::updatePatient(int id)
{
    for (auto& patient : dataManager.listOfPatient)
    {
        if (patient->getId() == id)
        {
            int choice;
            cout << "\t\t\t\tUpdating information for patient ID: " << id << endl;
            cout << "\t\t\t\tSelect what you want to update:\n";
            cout << "\t\t\t\t1. Name\n";
            cout << "\t\t\t\t2. Age\n";
            cout << "\t\t\t\t3. Gender\n";
            cout << "\t\t\t\tEnter your choice (1-3): ";
            cin >> choice;

            switch (choice)
            {
            case 1:
            {
                string name;
                cout << "\t\t\t\tEnter new name (current: " << patient->getName() << "): ";
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
                std::getline(cin, name);
                patient->setName(name);
                cout << "\t\t\t\tName updated successfully." << endl;
                break;
            }
            case 2:
            {
                int age;
                cout << "\t\t\t\tEnter new age (current: " << patient->getAge() << "): ";
                cin >> age;
                patient->setAge(age);
                cout << "\t\t\t\tAge updated successfully." << endl;
                break;
            }
            case 3:
            {
                char gender;
                cout << "\t\t\t\tEnter new gender (current: " << patient->getGender() << "): ";
                cin >> gender;
                patient->setGender(gender);
                cout << "\t\t\t\tGender updated successfully." << endl;
                break;
            }
            default:
                cout << "\t\t\t\tInvalid choice." << endl;
            }
            dataManager.saveData();
            cout << "\t\t\t\tPatient updated succesfully" << endl;
            return;
        }
    }

    cout << "\t\t\t\tPatient not found." << endl;
    //Sleep(3000);
}



void hospital::updateDoctor(int id)
{
    for (auto& doc : dataManager.listOfDoctors)
    {
        if (doc && doc->getId() == id)
        {
            int choice;
            cout << "\t\t\t\tUpdating information for doctor ID: " << id << endl;
            cout << "\t\t\t\tSelect what you want to update:\n";
            cout << "\t\t\t\t1. Name\n";
            cout << "\t\t\t\t2. Age\n";
            cout << "\t\t\t\t3. Gender\n";
            cout << "\t\t\t\t4. Specialization\n";
            cout << "\t\t\t\t5. Salary\n";
            cout << "\t\t\t\tEnter your choice (1-5): ";
            cin >> choice;

            switch (choice)
            {
            case 1:
            {
                string name;
                cout << "\t\t\t\tEnter new name (current: " << doc->getName() << "): ";
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(cin, name);
                doc->setName(name);
                cout << "\t\t\t\tName updated successfully." << endl;
                break;
            }
            case 2:
            {
                int age;
                cout << "\t\t\t\tEnter new age (current: " << doc->getAge() << "): ";
                cin >> age;
                doc->setAge(age);
                cout << "\t\t\t\tAge updated successfully." << endl;
                break;
            }
            case 3:
            {
                char gender;
                cout << "\t\t\t\tEnter new gender (current: " << doc->getGender() << "): ";
                cin >> gender;
                doc->setGender(gender);
                cout << "\t\t\t\tGender updated successfully." << endl;
                break;
            }
            case 4:
            {
                string specialization;
                cout << "\t\t\t\tEnter new specialization (current: " << doc->getSpecialization() << "): ";
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(cin, specialization);
                doc->setSpecialization(specialization);
                cout << "\t\t\t\tSpecialization updated successfully." << endl;
                break;
            }
            case 5:
            {
                double salary;
                cout << "\t\t\t\tEnter new salary (current: " << doc->getSalary() << "): ";
                cin >> salary;
                doc->setSalary(salary);
                cout << "\t\t\t\tSalary updated successfully." << endl;
                break;
            }
            default:
                cout << "\t\t\t\tInvalid choice." << endl;
            }
            dataManager.saveData();
            cout << "\t\t\t\tDoctor updated succesfully" << endl;
            return;
        }
    }
    cout << "\t\t\t\tDoctor not found." << endl;
}



void hospital::updateStaff(int id)
{
    for (auto& staff : dataManager.listOfStaff)
    {
        if (staff && staff->getId() == id)
        {
            int choice;
            cout << "\t\t\t\tUpdating information for staff ID: " << id << endl;
            cout << "\t\t\t\tSelect what you want to update:\n";
            cout << "\t\t\t\t1. Name\n";
            cout << "\t\t\t\t2. Age\n";
            cout << "\t\t\t\t3. Gender\n";
            cout << "\t\t\t\t4. Position\n";
            cout << "\t\t\t\t5. Salary\n";
            cout << "\t\t\t\tEnter your choice (1-5): ";
            cin >> choice;

            switch (choice)
            {
            case 1:
            {
                string name;
                cout << "\t\t\t\tEnter new name (current: " << staff->getName() << "): ";
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(cin, name);
                staff->setName(name);
                cout << "\t\t\t\tName updated successfully." << endl;
                break;
            }
            case 2:
            {
                int age;
                cout << "\t\t\t\tEnter new age (current: " << staff->getAge() << "): ";
                cin >> age;
                staff->setAge(age);
                cout << "\t\t\t\tAge updated successfully." << endl;
                break;
            }
            case 3:
            {
                char gender;
                cout << "\t\t\t\tEnter new gender (current: " << staff->getGender() << "): ";
                cin >> gender;
                staff->setGender(gender);
                cout << "\t\t\t\tGender updated successfully." << endl;
                break;
            }
            case 4:
            {
                string position;
                cout << "\t\t\t\tEnter new position (current: " << staff->getPosition() << "): ";
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(cin, position);
                staff->setPosition(position);
                cout << "\t\t\t\tPosition updated successfully." << endl;
                break;
            }
            case 5:
            {
                double salary;
                cout << "\t\t\t\tEnter new salary (current: " << staff->getSalary() << "): ";
                cin >> salary;
                staff->setSalary(salary);
                cout << "\t\t\t\tSalary updated successfully." << endl;
                break;
            }
            default:
                cout << "\t\t\t\tInvalid choice." << endl;
            }
            dataManager.saveData();
            cout << "\t\t\t\tStaff updated succesfully" << endl;
            return;
        }
    }
    cout << "\t\t\t\tStaff not found." << endl;
}

//search for a patient
void hospital::searchPatient(int id)
{
    for (const auto& patient : dataManager.listOfPatient)
    {
        if (patient->getId() == id)
        {
            cout << "\t\t\t\tPatient found: " << patient->getName() << endl;
            patient->display();
            return;
        }
    }
    cout << "\t\t\t\tPatient not found." << endl;
}

void hospital::searchEmployee(int id)
{
    dataManager.loadData();
    vector<Employee*> employees = dataManager.getEmployees();
    for (const auto& emp : employees)
    {
        if (emp->getId() == id)
        {
            cout << "\t\t\t\tEmployee found: " << emp->getName() << endl;
            emp->display();
            return;
        }
    }
    cout << "\t\t\t\tEmployee not found." << endl;
}

// Remove a patient
void hospital::dequeuePatient(int Doc_ID)
{
    Doctor* doctor = nullptr;
    for (const auto& Doc : dataManager.listOfDoctors)
    {
        if (Doc && Doc->getId() == Doc_ID)
        {
            doctor = Doc;
            break;
        }
    }
    Patient* patient = doctor->dequeue();
    if (patient->getId() == 0)
        return;
    else
    patient->addReport(patient, doctor);

}


