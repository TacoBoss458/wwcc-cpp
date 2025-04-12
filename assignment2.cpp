#include <iostream>
#include <string> 
using namespace std;
int main (){
    int num1;
    double num2;
    double quotient = num1 / num2;
    cout << "Enter a number: " << endl;
    cin >> num1;
    cout << "Enter another number: " << endl;
    cin >> num2;
    cout << "Sum: " << num1 + num2 << endl;
    cout << "Difference: " << num1 - num2 << endl;
    cout << "Product: " << num1 * num2 << endl;
    if (num2 = 0){
        cout << "Divided by 0, UNDEFINED." << endl;
    }
    else {
        cout << "Quotient: " << quotient << endl;
    }
    return 0;
}