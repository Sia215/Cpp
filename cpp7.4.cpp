/*An educational institution requires a system to generate well-structured student performance reports
from raw data stored in a file. The system should read student records, including their name, marks,
and grade, and present the information in a neatly formatted tabular format. Since the institution

handles large datasets, the report generation must be efficient, ensuring clear alignment and
readability while allowing for future enhancements such as sorting and filtering.
To achieve this, the system must first handle file input operations, reading student data while ensuring
error handling if the file is missing or inaccessible. The program should then format and display the
information in a structured manner, making use of a user-defined manipulator to align columns
properly. This ensures that names, marks, and grades are clearly visible in the report, regardless of
data length variations.
For implementation, two approaches are explored. The first method processes the data directly from
the file, formatting and displaying each entry without storing it in memory. This minimizes memory
usage but limits additional processing, such as sorting or filtering. The alternative approach
dynamically stores student records using a manually managed data structure, allowing further
modifications, such as sorting by marks or filtering based on grades, before presenting the final
formatted report.*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

// Structure to store student data
struct Student {
    char name[50];
    float marks;
    char grade;
};

// User-defined manipulator for setting a fixed width (like setw)
ostream& alignColumn(ostream& os) {
    return os << setw(15) << left;
}

// Function to generate the formatted student report
void generateReport(const char* filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Could not open file \"" << filename << "\" for reading.\n";
        return;
    }

    Student student;

    cout << "\n======= Student Performance Report =======\n";
    cout << alignColumn << "Name"
         << alignColumn << "Marks"
         << alignColumn << "Grade" << endl;
    cout << string(45, '-') << endl;

    // Read and display data from the file line by line
    while (file >> student.name >> student.marks >> student.grade) {
        cout << alignColumn << student.name
             << alignColumn << fixed << setprecision(2) << student.marks
             << alignColumn << student.grade << endl;
    }

    file.close();
}

int main() {
    const char* filename = "students.txt";

    cout << "=== Student Report Generator ===\n";

    generateReport(filename);

    return 0;
}
