#include "hospital.h"
#include "Doctor.h"
#include <string>
#include <algorithm> // for transform
#include <cctype>    // for tolower
using namespace std;

//validate the intger input
int hospital::getInt(string prompt) {
    int value;
    while (true) {  
        cout << prompt;
        cin >> value;
        //stop if the input is valid
        if (cin) return value;

        cin.clear();       // clear the invalid input
        cin.ignore(1000, '\n');
        cout << "\t\t\t\tInvalid input! Please enter a number.\n";
    } //keep asking for the input it is not valid
}

 //validate the double input
double hospital::getDouble(string prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        //stop if the input is valid
        if (cin) return value;

        cin.clear();     // clear the invalid input
        cin.ignore(1000, '\n');
        cout << "\t\t\t\tInvalid input! Please enter a valid number.\n";
    }//keep asking for the input it is not valid
}

 //validate the gender input
char hospital::getGender(string prompt) {
    char gender;
    while (true) {
        cout << prompt;
        cin >> gender;
        gender = toupper(gender); //accept lower & upper case

        //stop if the input is valid
        if (gender == 'M' || gender == 'F') return gender;

        cout << "\t\t\t\tInvalid input! Please enter M or F only.\n";
    }//keep asking for the input it is not valid
}

int hospital::choiseRange(int a, int b , string prompt) {
    int choice;

    while (true) {
        //get the choise
        choice = getInt(prompt);

        //stop if the input in range
        if (choice >= a && choice <= b) return choice;
        
        cout << "\t\t\t\tInvalid choice.Enter a number between "<< a <<" and "<< b <<endl;

    }//keep asking for the input it is not valid
}

// add a patient .......
void hospital::addPatient() {
    int age, id;
    string name;
    char gender;
    cout << "\t\t\t\tEnter information" << endl;

    id=getInt( "\t\t\t\tID: ");
    
    //add a new patient if it is not exist 
    if (!searchPatient(to_string(id))) {
        cout << "\t\t\t\tName : ";
        cin.ignore(); // Clear input buffer
        getline(cin, name);
        age=getInt( "\t\t\t\tAge : ");
        gender = getGender("\t\t\t\tGender (M/F) : ");

        patient->setName(name);
        patient->setAge(age);
        patient->setId(id);
        patient->setGender(gender);
        
    }
    // Assign patient to a doctor based on specialization
    system("cls");           
    int i = 1;
    for (auto& spec : specializations) {
        cout <<"\t\t\t\t"<<i << "." << spec << "." << endl;
        i++;
    }
    int choice = choiseRange(1,i-1,"\t\t\t\tEnter your choice (1- " + to_string (i - 1) + "):");
    system("cls");

    //search for available doctors
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
   
    int docChoice= choiseRange(1, (int)availableDoctors.size(),"\t\t\t\tSelect a doctor by number: ");

    Doctor* reqDoctor = availableDoctors[docChoice - 1];
    cout << "\t\t\t\tPatient assigned to Dr. " << reqDoctor->getName()
        << " (" << reqDoctor->getSpecialization() << ")" << endl;

    //add patient to doctor's queue.....
    reqDoctor->enqueue(patient);
    dataManager.listOfPatient.push_back(patient);
    dataManager.saveData();
    dataManager.saveCurrentPatients(dataManager.listOfDoctors);
}

void hospital::addDoctor() {
    string name, specialization;
    int id, age;
    double salary;
    char gender;
    cout << "\t\t\t\tEnter doctor's name: ";
    cin.ignore(); 
    getline(cin, name);
    id = getInt("\t\t\t\tEnter doctor's ID: ");
    age=getInt( "\t\t\t\tEnter doctor's Age: ");
    gender= getGender( "\t\t\t\tEnter doctor's Gender (M/F): ");

    cout << "\t\t\t\tEnter doctor's specialization: " << endl;
    cout << "\t\t\t\t=============================\n";
    for (int i = 0; i < specializations.size(); i++) {
        cout << "\t\t\t\t" << i + 1 << ". " << specializations[i] << endl;
    }
    cout << "\t\t\t\t=============================\n";
    int specChoice = choiseRange(1, specializations.size(),
        "\t\t\t\tEnter your choice (1-" + to_string(specializations.size()) + "): ");
    
     specialization = specializations[specChoice - 1];
    
    salary=getDouble( "\t\t\t\tEnter doctor's salary: ");
   

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
    cout << "\t\t\t\tEnter staff's name: ";
    cin.ignore(); 
    getline(cin, name);
    id=getInt( "\t\t\t\tEnter staff's ID: ");
    age=getInt( "\t\t\t\tEnter staff's Age: ");
    gender=getGender( "\t\t\t\tEnter staff's Gender (M/F): ");
    cout << "\t\t\t\tEnter staff's Position: ";
    cin.ignore(); 
    getline(cin, position);
    salary=getDouble( "\t\t\t\tEnter staff's salary: ");

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

            choice = choiseRange(1, 3, "\t\t\t\tEnter your choice (1-3): ");
            
            switch (choice)
            {
            case 1:
            {
                string name;
                cout << "\t\t\t\tEnter new name (current: " << patient->getName() << "): ";
                cin.ignore(); // Clear input buffer
                std::getline(cin, name);
                patient->setName(name);
                cout << "\t\t\t\tName updated successfully." << endl;
                break;
            }
            case 2:
            {
                int age = getInt("\t\t\t\tEnter new age (current: " + to_string(patient->getAge() )+ "): ");
                cout << "\t\t\t\tAge updated successfully." << endl;
                break;
            }
            case 3:
            {
                char gender = getGender("\t\t\t\tEnter new gender (current: " +to_string( patient->getGender())+ "): ");
                cout << "\t\t\t\tGender updated successfully." << endl;
                break;
            }
            default:
                cout << "\t\t\t\tInvalid choice." << endl;
            }
            dataManager.saveData();
            
            return;
        }
    }

    cout << "\t\t\t\tPatient not found." << endl;
   
}



void hospital::updateDoctor(int id)
{
    for (auto& doc : dataManager.listOfDoctors)
    {
        if (doc && doc->getId() == id)
        {
            
            cout << "\t\t\t\tUpdating information for doctor ID: " << id << endl;
            cout << "\t\t\t\tSelect what you want to update:\n";
            cout << "\t\t\t\t1. Name\n";
            cout << "\t\t\t\t2. Age\n";
            cout << "\t\t\t\t3. Gender\n";
            cout << "\t\t\t\t4. Specialization\n";
            cout << "\t\t\t\t5. Salary\n";

            int choice= choiseRange(1,5, "\t\t\t\tEnter your choice (1-5): ");
            
            switch (choice)
            {
            case 1:
            {
                string name;
                cout << "\t\t\t\tEnter new name (current: " << doc->getName() << "): ";
                cin.ignore();
                getline(cin, name);
                doc->setName(name);
                cout << "\t\t\t\tName updated successfully." << endl;
                break;
            }
            case 2:
            {
                int age = getInt("\t\t\t\tEnter new age (current: " +to_string( doc->getAge()) + "): ");
                doc->setAge(age);
                cout << "\t\t\t\tAge updated successfully." << endl;
                break;
            }
            case 3:
            {
                char gender = getGender("\t\t\t\tEnter new gender (current: " +to_string( doc->getGender())+ "): ");
                doc->setGender(gender);
                cout << "\t\t\t\tGender updated successfully." << endl;
                break;
            }
            case 4:
            {
                cout << "\t\t\t\tSelect new specialization (current: " << doc->getSpecialization() << "): "<<endl;
                for (int i = 0; i < specializations.size(); i++) {
                    cout << "\t\t\t\t" << i + 1 << ". " << specializations[i] << endl;
                }

                int specChoice = choiseRange(1, specializations.size(),
                    "\t\t\t\tEnter your choice (1-" + to_string(specializations.size()) + "): ");

                string specialization = specializations[specChoice - 1];


                doc->setSpecialization(specialization);
                cout << "\t\t\t\tSpecialization updated successfully." << endl;
                break;
            }
            case 5:
            {
                double salary= getDouble( "\t\t\t\tEnter new salary (current: " +to_string( doc->getSalary())+ "): ");
                
                doc->setSalary(salary);
                cout << "\t\t\t\tSalary updated successfully." << endl;
                break;
            }
            default:
                cout << "\t\t\t\tInvalid choice." << endl;
            }
            dataManager.saveData();
           
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
            cout << "\t\t\t\tUpdating information for staff ID: " << id << endl;
            cout << "\t\t\t\tSelect what you want to update:\n";
            cout << "\t\t\t\t1. Name\n";
            cout << "\t\t\t\t2. Age\n";
            cout << "\t\t\t\t3. Gender\n";
            cout << "\t\t\t\t4. Position\n";
            cout << "\t\t\t\t5. Salary\n";

            int choice= choiseRange(1,5, "\t\t\t\tEnter your choice (1-5): ");
            
            switch (choice)
            {
            case 1:
            {
                string name;
                cout << "\t\t\t\tEnter new name (current: " << staff->getName() << "): ";
                cin.ignore();
                getline(cin, name);
                staff->setName(name);
                cout << "\t\t\t\tName updated successfully." << endl;
                break;
            }
            case 2:
            {
                int age= getInt( "\t\t\t\tEnter new age (current: " +to_string(staff->getAge())+ "): ");
                
                staff->setAge(age);
                cout << "\t\t\t\tAge updated successfully." << endl;
                break;
            }
            case 3:
            {
                char gender = getGender( "\t\t\t\tEnter new gender (current: " +to_string( staff->getGender() )+ "): ");
                staff->setGender(gender);
                cout << "\t\t\t\tGender updated successfully." << endl;
                break;
            }
            case 4:
            {
                string position;
                cout << "\t\t\t\tEnter new position (current: " << staff->getPosition() << "): ";
                cin.ignore();
                getline(cin, position);
                staff->setPosition(position);
                cout << "\t\t\t\tPosition updated successfully." << endl;
                break;
            }
            case 5:
            {
                double salary = getDouble( "\t\t\t\tEnter new salary (current: " +to_string( staff->getSalary()) + "): ");
                
                staff->setSalary(salary);
                cout << "\t\t\t\tSalary updated successfully." << endl;
                break;
            }
            default:
                cout << "\t\t\t\tInvalid choice." << endl;
            }
            dataManager.saveData();
            
            return;
        }
    }
    cout << "\t\t\t\tStaff not found." << endl;
}

//search for a patient
bool hospital::searchPatient(string att)
{
    vector<Patient*> found;
    // Check if att is numeric 
    bool isNumeric = true;
    try {
        stoi(att);
    }
    catch (const exception& e) {
        isNumeric = false;
    }

    for (const auto& patient : dataManager.listOfPatient)
    {
        // ID search exact match
        if (isNumeric && patient->getId() == stoi(att)){
            found.push_back(patient);
        }
        // Name search partial case insensitive match
        else if (!isNumeric){
            string patientName = patient->getName();
            string searchAtt = att;

            // Convert both to lowercase for case insensitive comparison
            transform(patientName.begin(), patientName.end(), patientName.begin(), ::tolower);
            transform(searchAtt.begin(), searchAtt.end(), searchAtt.begin(), ::tolower);

            // Check if patient name contains the search string
            if (patientName.find(searchAtt) != string::npos){
                found.push_back(patient);
            }
        }
    }

    if (found.empty()) {
        return false;

    }else {
        cout << "\t\t\t\t------------- " << endl;
        cout << "\t\t\t\t" << found.size() << " Patients found " << endl;
        cout << "\t\t\t\t------------- " << endl;
        for (int i = 0; i < found.size();i++) {
            cout << "\t\t\t\tPatient number " << i + 1 << endl;
            found[i]->display();
            cout << "\t\t\t\t------------- " << endl;
        }
        return true;
    }
}



void hospital::searchEmployee(string att)
{
    vector<Employee*> found;
    dataManager.loadData();
    vector<Employee*> employees = dataManager.getEmployees();

    bool isNumeric = true;
    try {
        stoi(att);
    }
    catch (const exception& e) {
        isNumeric = false;
    }

    for (const auto& emp : employees)
    {
        // ID search exact match
        if (isNumeric && emp->getId() == stoi(att)) {
            found.push_back(emp);
        }
        // Name search partial case insensitive match
        else if (!isNumeric) {
            string empName = emp->getName();
            string searchAtt = att;

            // Convert both to lowercase for case insensitive comparison
            transform(empName.begin(), empName.end(), empName.begin(), ::tolower);
            transform(searchAtt.begin(), searchAtt.end(), searchAtt.begin(), ::tolower);

            // Check if patient name contains the search string
            if (empName.find(searchAtt) != string::npos) {
                found.push_back(emp);
            }
        }
    }

    if (found.empty()) {
        cout << "\t\t\t\tEmployee not found." << endl;
        return;

    }else {
        cout << "\t\t\t\t------------- " << endl;
        cout << "\t\t\t\t" << found.size() << " Employees found " << endl;
        cout << "\t\t\t\t------------- " << endl;
        for (int i = 0; i < found.size();i++) {
            cout << "\t\t\t\tEmployee number " << i + 1 << endl;
            found[i]->display();
            cout << "\t\t\t\t------------- " << endl;
        }
        return;
    }
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
    //if the doctor not found

    if (!doctor) {   
        cout << "\t\t\t\tDoctor with ID " << Doc_ID << " not found." << endl;
        return;
    }
    //if there is no patients on queue
    Patient* patient = doctor->dequeue();
    if (!patient) { 
        cout << "\t\t\t\tThe doctor doesn't have patients to remove." << endl;
        
        return;
    }
    else
    patient->addReport(patient, doctor);

}
// for adding a new clinc (Specialization).
bool hospital::addClinic(string nameClinic) {

    for (const auto& spec : specializations) {
        if (spec == nameClinic) {
            return false; 
        }
    }
    specializations.push_back(nameClinic);
    dataManager.saveSpecializations(specializations);
    return true;
}


