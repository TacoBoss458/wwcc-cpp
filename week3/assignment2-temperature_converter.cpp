#include <iostream>
#include <iomanip>
using namespace std;

void convertTemperature(double temp, char unit, double &tempC, double &tempF, double &tempK) { //pbr
    unit = toupper(unit);
    if (unit == 'C') {
        tempC = temp;
        tempF = (temp * 9/5) + 32;
        tempK = temp + 273.15;
    } else if (unit == 'F') {
        tempC = (temp - 32) * 5/9;
        tempF = temp;
        tempK = tempC + 273.15;
    } else if (unit == 'K') {
        tempC = temp - 273.15;
        tempF = (tempC * 9/5) + 32;
        tempK = temp;
    } else {
        cout << "Invalid unit!" << endl;
        return;
    }
}
int main() {
    double temp, tempC, tempF, tempK;
    char unit;
    cout << "Enter temperature: ";
    cin >> temp;
    cout << "Enter unit (C, F, K): ";
    cin >> unit;
    convertTemperature(temp, unit, tempC, tempF, tempK);
    if (toupper(unit) == 'C' || toupper(unit) == 'F' || toupper(unit) == 'K') { // allow lowercase to work
        cout << fixed << setprecision(2); //manipulate decimal precision
        cout << "Temperature in Celsius: " << tempC << "C" << endl;
        cout << "Temperature in Fahrenheit: " << tempF << "F" << endl;
        cout << "Temperature in Kelvin: " << tempK << "K" << endl;
    }
    return 0;
}
