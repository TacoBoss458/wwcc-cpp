#include <iostream>
using namespace std;

// References
void modifyByReference(int& i, double& d, char& c) {
    i += 10;
    d *= 2.5;
    c = 'Z';
}

// Pointers
void modifyByPointer(int* i, double* d, char* c) {
    if (i) *i += 5;
    if (d) *d /= 2.0;
    if (c) *c = 'X';
}

void visualizeMemory() {
    cout << "=== Memory Visualization ===\n\n";

    // INITIAL VAARIABLES
    int intVar = 42;
    double doubleVar = 3.14;
    char charVar = 'A';

    cout << "Initial Values and Addresses:\n";
    cout << "intVar = " << intVar << ", Address: " << &intVar << endl;
    cout << "doubleVar = " << doubleVar << ", Address: " << &doubleVar << endl;
    cout << "charVar = " << charVar << ", Address: " << static_cast<void*>(&charVar) << endl;

    modifyByReference(intVar, doubleVar, charVar);
    cout << "\nAfter modifyByReference:\n";
    cout << "intVar = " << intVar << ", doubleVar = " << doubleVar << ", charVar = " << charVar << endl;

    modifyByPointer(&intVar, &doubleVar, &charVar);
    cout << "\nAfter modifyByPointer:\n";
    cout << "intVar = " << intVar << ", doubleVar = " << doubleVar << ", charVar = " << charVar << endl;

    cout << "\nTesting null pointer safety:\n";
    modifyByPointer(nullptr, nullptr, nullptr);

    int arr[5] = {10, 20, 30, 40, 50};
    int* ptr = arr;

    cout << "\nArray and Pointer Relationship:\n";
    cout << "Array name (arr) is a pointer to first element: " << arr << endl;
    cout << "ptr = " << ptr << ", *ptr = " << *ptr << endl;

    cout << "\nPointer Arithmetic:\n";
    for (int i = 0; i < 5; ++i) {
        cout << "*(ptr + " << i << ") = " << *(ptr + i) << ", Address: " << (ptr + i) << endl;
    }
}

int main() {
    visualizeMemory();
    return 0;
}
