#include <iostream>
#include <string>
using namespace std;

int main() {
    const int DAYS_IN_WEEK = 7;
    string days[DAYS_IN_WEEK] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    double sales[DAYS_IN_WEEK];
    double totalSales = 0.0;
    double averageSales;
    int daysAboveAverage = 0;
    double weekendSales = 0.0;

    // Sales for each day
    for (int i = 0; i < DAYS_IN_WEEK; ++i) {
        cout << "Enter sales for " << days[i] << ": $";
        while (!(cin >> sales[i]) || sales[i] < 0) {
            cout << "Invalid input. Please enter a non-negative number for " << days[i] << ": $";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        totalSales += sales[i];
        if (i >= 5) { // Saturday and Sunday being 6 and 7
            weekendSales += sales[i];
        }
    }

    // Average
    averageSales = totalSales / DAYS_IN_WEEK;

    // High Low
    int highestIndex = 0, lowestIndex = 0;
    for (int i = 1; i < DAYS_IN_WEEK; ++i) {
        if (sales[i] > sales[highestIndex]) highestIndex = i;
        if (sales[i] < sales[lowestIndex]) lowestIndex = i;
    }

    // Days above the sales average
    for (int i = 0; i < DAYS_IN_WEEK; ++i) {
        if (sales[i] > averageSales) ++daysAboveAverage;
    }

    // What stats to display
    cout << "\n--- This Weeks Sales Report ---\n\n";
    cout << "Total sales: $" << totalSales << endl;
    cout << "Average daily sales: $" << averageSales << endl << endl;
    cout << "Highest sales: " << days[highestIndex] << " ($" << sales[highestIndex] << ")" << endl;
    cout << "Lowest sales: " << days[lowestIndex] << " ($" << sales[lowestIndex] << ")" << endl << endl;
    cout << "Number of days above average: " << daysAboveAverage << endl;
    cout << "Weekend sales: $" << weekendSales << " (" << (weekendSales / totalSales) * 100 << "%)" << endl;
    return 0;
}