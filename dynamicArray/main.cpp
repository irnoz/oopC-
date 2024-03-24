#include <iostream>
#include "includes/dynamic_array.h"

using namespace std;

int main() {
    try {
        dynamic_array<int> dr;

        // Push elements into the array
        dr.push_back(1);
        dr.push_back(2);
        dr.push_back(3);

        cout << "araay after pushing back some elements" << endl;
        dr.print();

        // Print array size
        cout << "Size: " << dr.size() << endl;

        // Access elements using subscript operator[]
        cout << "Element at index 1: " << dr[10] << endl;

        // Insert element at index 1
        dr.push_at(1, 10);

        // Print the array
        cout << "Array after inserting element at index 1: ";
        dr.print();

        // Remove element at index 2
        dr.remove_at(2);

        // Print the array again
        cout << "Array after removing element at index 2: ";
        dr.print();

        // Pop element from the back
        dr.pop_back();

        // Print the array
        cout << "Array after popping an element: ";
        dr.print();
    } catch (const exception& e) {
        cerr << "Exception occurred: " << e.what() << endl;
    }

    return 0;
}