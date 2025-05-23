/*A university administration is developing a system to display student marks in a structured and visually
appealing format. The goal is to ensure clarity in academic reports by properly aligning names and
scores while also demonstrating the use of currency formatting for tuition fees or other financial data.
To achieve this, built-in stream manipulators such as endl, setw, setfill, and setprecision must be used
to create a neatly formatted output.
The system first reads student names and their corresponding marks, ensuring that the data is aligned
in tabular form. Proper spacing between columns enhances readability, preventing misalignment
issues caused by varying name lengths or mark values. Additionally, numerical values must be
displayed with controlled decimal precision for consistency.
Beyond academic scores, the university also wants to format financial figures, such as tuition fees, in
a standardized manner. To achieve this, the system includes a user-defined manipulator, currency(),
which prepends a specified currency symbol (₹, $, etc.) before displaying monetary values. This custom
formatting ensures that financial data is both readable and professionally presented.*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Function to return a user-defined manipulator for currency formatting
ostream& currency(ostream& os) {
    os << "rupees ";
    return os;
}

// Structure to store student data
struct Student {
    string name;
    float marks;
    float tuitionFee;
};

// Function to display a formatted table of students
void displayStudents(Student students[], int count) {
    cout << "\n======= Student Academic Report =======\n";
    cout << left << setw(20) << "Name"
         << setw(10) << "Marks"
         << setw(15) << "Tuition Fee" << endl;
    cout << string(45, '-') << endl;

    for (int i = 0; i < count; ++i) {
        cout << left << setw(20) << students[i].name
             << setw(10) << fixed << setprecision(2) << students[i].marks
             << currency << setw(14) << fixed << setprecision(2) << students[i].tuitionFee << endl;
    }
}

int main() {
    // Updated data: name, marks, tuition fee
    Student students[] = {
        {"siya", 90.5f, 49000.00f},
        {"vrinda", 91.0f, 47500.50f},
        {"Bansari", 90.25f, 44000.75f},

    };

    int studentCount = sizeof(students) / sizeof(students[0]);

    displayStudents(students, studentCount);

    return 0;
}
