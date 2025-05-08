/*An educational institution is developing a system to rank students based on their scores in an
examination. The goal is to efficiently store student names along with their respective scores, sort the
records in descending order based on scores, and display the ranked list. The system should be flexible
enough to handle varying numbers of students dynamically.
To achieve this, the system associates each student’s name with their score using a structured data
representation. A dynamically resizable sequence is chosen to store student records, allowing efficient
insertion and retrieval of entries. Each entry consists of a name-score pair, ensuring logical grouping
of related information.
Once the data is collected, a sorting operation is performed using a custom comparison function. By
leveraging an efficient sorting algorithm, the system ensures that students with the highest scores
appear at the top of the list. Iterators are then used to traverse and display the sorted data in a
structured format, highlighting rank-based ordering.*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<pair<string, int>> students;
    string name;
    int score;

    for (int i = 0; i < n; ++i) {
        cout << "Enter name and score for student " << i + 1 << ": ";
        cin >> name >> score;
        students.push_back({name, score});
    }

    sort(students.begin(), students.end(),
              [](const pair<string, int>& a, const pair<string, int>& b) {
                  return a.second > b.second;
                  });

    cout << "\nRanked Student List:\n";
    int rank = 1;
    for (auto it = students.begin(); it != students.end(); ++it) {
        cout << "Rank " << rank << ": " << it->first << " (Score: " << it->second << ")\n";
        ++rank;
    }

    return 0;
}
