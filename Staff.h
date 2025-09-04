
#include "Employee.h"
#include <string>
using namespace std;
class Staff : public Employee {
private:
    string position;

public:
    // Constructors
    Staff();
    Staff(string name, char gender, int age, int id, double salary, string pos);

    // Destructor
    ~Staff();

    // Getter and Setter
    void setPosition(string pos);
    string getPosition() const;

    // Display function
    void display() const;
};
