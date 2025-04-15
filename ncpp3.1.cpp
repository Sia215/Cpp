/*A growing organization sought to enhance its payroll process to improve accuracy and efficiency in
calculating employee salaries. The goal was to manage details such as the employee's name, basic
salary, and bonus amount. While most employees would receive a default bonus, there was a need
for flexibility to provide customized bonuses for exceptional performers or those in specialized roles.
To ensure real-time computation of each employee's total salary, the system would dynamically
calculate the total salary by adding the basic salary and the bonus. An inline function was chosen for
this task, allowing the system to compute the total salary instantly during processing. The system was
designed to initialize employee records using a constructor, where the bonus could either be set to a
default value or adjusted according to specific employee criteria.
As the organization expanded, managing employee records efficiently became a key consideration.
The solution involved storing employee details dynamically, ensuring the system could handle a
growing number of records while maintaining scalability and flexibility. Each employee record would
include their personal details, basic salary, and bonus information, with the system displaying a
breakdown of each employee’s details along with their total salary.*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Employee
 {
    string name;
    double basicSalary;
    double bonus;

public:

    Employee(string empName, double salary, double empBonus = 1000.0)
        : name(empName), basicSalary(salary), bonus(empBonus) {}


    inline double calculateTotalSalary() const {
        return basicSalary + bonus;
    }

    void displayDetails() const {
        cout << "Name: " << name << endl;
        cout << "Basic Salary: " << basicSalary << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Total Salary: " << calculateTotalSalary() << endl;
        cout << "---------------------------------------------------"<<endl;
    }
};

int main() {
    vector<Employee> employees;

    int numEmployees;
    cout << "Enter number of employees: ";
    cin >> numEmployees;

    for (int i = 0; i < numEmployees; i++) {
        string name;
        double basicSalary, bonus;

        cout << "\nEnter details for employee " << (i + 1) << endl;
        cout << "Enter name ";
        cin >> name;
        cout << "Enter basic salary: ";
        cin >> basicSalary;
        cout << "Enter bonus (enter -1 to use default bonus of 1000): ";
        cin >> bonus;

        if (bonus == -1)
        {
            bonus = 1000.0;
        }

        employees.emplace_back(name, basicSalary, bonus);
    }

    cout << "\nEmployee Details:\n";
    for (const auto& emp : employees)
    {
        emp.displayDetails();
    }

    return 0;
}
