#include <iostream>
#include <iomanip>
using namespace std;

// UUSD converters
double dollarToEuro(double usd) {
    return (usd * 0.85);
}

double dollarToPound(double usd) {
    return (usd * 0.74);
}
double dollarToYen(double usd) {
    return (usd * 110.33);
}


int main (){
    static int conversionCounter = 0;
    int choice;
    double amount;
    while (true){
        cout << "\n[CURRENCY CONVERTER MENU]\nWelcome to the Currency Converter Program!\n";
        cout << "1. Convert USD to EUR.\n";
        cout << "2. Convert USD to GBP.\n";
        cout << "3. Convert USD to JPY.\n";
        cout << "4. Exit.\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        if (choice == 4){
            break;
        }
        cout << "\nEnter an amount in USD: ";
        cin >> amount;
        switch (choice) {
            case 1: {
                cout << amount << " USD is " << dollarToEuro(amount) << " EUR.\n";
                break;
            }
            case 2: {
                cout << amount << " USD is " << dollarToPound(amount) << " GBP.\n";
                break;
            }
            case 3: {
                cout << amount << " USD is " << dollarToYen(amount) << " JPY.\n";
                break;
            }
            default: {
                cout << "Invalid option! Try again!\n";
                continue;
            }
        }
        conversionCounter++;
        cout << "Total conversions made: " << conversionCounter << "\n";
    }
    cout << "\nExiting the Conversion Counter Program. Total conversions made: " << conversionCounter << "\nHave a fantastic day!\n\n";
    return 0;
}