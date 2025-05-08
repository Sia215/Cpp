/*A data analytics firm is developing a tool to process numerical sequences efficiently. One of the key
requirements is to reverse a given sequence of integers while ensuring optimized performance using
modern C++ techniques. The system should allow users to input a sequence of numbers, process the
reversal using iterators, and display the transformed output.
To accomplish this, two approaches are explored. The first method leverages the built-in std::reverse()
function, which efficiently reverses elements within a dynamically managed sequence. The second
approach involves manually implementing the reversal using iterators, providing deeper insight into
how iterators navigate and modify data structures.
The system uses a dynamic storage mechanism to handle sequences of varying sizes efficiently.
Iterators facilitate traversal and modification, ensuring that elements are manipulated without direct
indexing.*/

#include <iostream>
#include <vector>
#include <algorithm>  // for std::reverse
using namespace std;

int main() {
    vector<int> sequence;
    int n, input;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        cin >> input;
        sequence.push_back(input);
    }

    // Using std::reverse
    reverse(sequence.begin(), sequence.end());

    cout << "Reversed sequence:\n";
    for (const int& num : sequence) {
        cout << num << " ";
    }

    // Manual reversal using iterators
    auto front = sequence.begin();
    auto back = sequence.end() - 1;

    while (front < back) {
        iter_swap(front, back);  // Swaps values pointed to by the iterators
        ++front;
        --back;
    }

    cout << "\n\nReversed sequence:\n";
    for (const int& num : sequence) {
        cout << num << " ";
    }

        return 0;
}


