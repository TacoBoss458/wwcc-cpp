#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;

// Function to format number with commas
string formatWithCommas(int number) { 
    string numStr = to_string(number); //int to string
    int insertPosition = numStr.length() - 3; //initial comma
    while (insertPosition > 0) {
        numStr.insert(insertPosition, ",");
        insertPosition -= 3;
    }//every 3 didgits is a comma
    return numStr;//should return the formmatted string
}
string formatWithPrecisionTwo(double number2) {
    ostringstream stream;
    stream << fixed << setprecision(2) << number2;
    return stream.str();
}

string formatWithPrecisionFour(double number3, int precision) {
    ostringstream out;
    out << fixed << setprecision(precision) << number3;
    return out.str();
}
//??






int main() {
    int commas = 1234567;
    double precision = 1000.995;
    double preFour = 23456.77;
    int precisionFour = 4;
    string caps;

    string formatted1 = formatWithCommas(commas);
    cout << "\nPrint Formatter\n\nOriginal: 1234567\nFormatted: "<< formatted1;
    string formatted2 = formatWithPrecisionTwo(precision);
    cout << "\nOriginal: 1000.995\nFormatted to 2 decimal places: "<< formatted2;
    string formatted3 = formatWithPrecisionFour(preFour, precisionFour);
    cout << "\nOriginal: 23456.77\nFormatted with 4 decimal places: "<< formatted3 <<endl << endl;
}
