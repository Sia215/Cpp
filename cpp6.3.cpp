/*A financial analytics company is working on a system that processes large volumes of sorted numerical
data from different sources. The challenge is to efficiently combine two independently sorted datasets
into a single, fully sorted dataset while ensuring optimal memory management. Since the size of the
datasets varies dynamically based on incoming data streams, the solution must be flexible and manage
memory efficiently without relying on built-in container libraries.
To achieve this, the development team needs to implement a mechanism that accepts two sorted
arrays of different sizes and merges them into a new dynamically allocated array while maintaining
the sorted order. The system should read input values specifying the sizes of both datasets, followed
by the elements of each array. After merging, the final sorted array should be displayed as output.
Efficient memory handling is crucial in this implementation, requiring the use of new and delete
operators for dynamic allocation and deallocation of memory.*/

#include <iostream>
using namespace std;

int main() {
    int m, n;

    cout << "Enter the size of the first sorted array: ";
    cin >> m;
    cout << "Enter the size of the second sorted array: ";
    cin >> n;

    int* arr1 = new int[m];
    int* arr2 = new int[n];

    cout << "Enter " << m << " sorted elements for the first array: ";
    for (int i = 0; i < m; ++i) {
        cin >> arr1[i];
    }


    cout << "Enter " << n << " sorted elements for the second array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr2[i];
    }

    int* merged = new int[m + n];

    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    while (i < m) {
        merged[k++] = arr1[i++];
    }

    while (j < n) {
        merged[k++] = arr2[j++];
    }

    cout << "Merged sorted array: ";
    for (int idx = 0; idx < m + n; ++idx) {
        cout << merged[idx] << " ";
    }
    cout << endl;

    delete[] arr1;
    delete[] arr2;
    delete[] merged;


    return 0;
}
