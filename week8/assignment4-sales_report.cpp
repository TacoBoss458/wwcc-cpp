#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

struct Product {
    string name;
    string category;
    double unitPrice;
    int unitsSold = 0;
    double totalRevenue = 0.0;

    void addSale(int quantity) {
        unitsSold += quantity;
        totalRevenue += quantity * unitPrice;
    }
};

// Time Function
string getCurrentDateTime() {
    time_t now = time(nullptr);
    char buf[100];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&now));
    return string(buf);
}


int main() {
    ifstream inputFile("sales_data.txt");
    ofstream reportFile("sales_summary.txt");

    if (!inputFile) {
        cerr << "Error: Could not open input file.\n";
        return 1;
    }

    map<string, vector<Product>> categoryMap;
    map<string, Product> productMap;

    string line;
    int totalUnits = 0;
    double totalRevenue = 0.0;
    int transactionCount = 0;
    int lineNumber = 0;

    // Data Reading and Validation
    while (getline(inputFile, line)) {
        lineNumber++;
        istringstream iss(line);
        if (line.empty() || line[0] == '#') continue;

        string date, name, category;
        int quantity;
        double price;

        if (!(iss >> date >> name >> category >> quantity >> price)) {
            cerr << "Warning: Skipping malformed line " << lineNumber << ": " << line << "\n";
            continue;
        }

        if (quantity <= 0 || price <= 0) {
            cerr << "Warning: Invalid quantity or price on line " << lineNumber << ": " << line << "\n";
            continue;
        }

        string key = name + "|" + category + "|" + to_string(price);

        if (productMap.find(key) == productMap.end()) {
            productMap[key] = {name, category, price};
        }

        productMap[key].addSale(quantity);
        totalUnits += quantity;
        totalRevenue += quantity * price;
        transactionCount++;
    }

    // Data Organization
    for (const auto& [key, product] : productMap) {
        categoryMap[product.category].push_back(product);
    }

    // Best-Selling Product Calculation
    Product bestProduct;
    for (const auto& [key, product] : productMap) {
        if (product.totalRevenue > bestProduct.totalRevenue) {
            bestProduct = product;
        }
    }

    // Report Generation
    reportFile << "SALES SUMMARY REPORT\n";
    reportFile << "Generated: " << getCurrentDateTime() << "\n";
    reportFile << "=====================================\n\n";

    reportFile << left << setw(20) << "Product"
               << "  " << setw(15) << "Category"
               << right << setw(11) << "Units Sold"
               << setw(13) << "Unit Price"
               << setw(15) << "Total Revenue" << "\n";

    reportFile << string(20, '-') << "  "
               << string(15, '-') << "  "
               << string(11, '-') << "  "
               << string(11, '-') << "  "
               << string(13, '-') << "\n";

    for (const auto& [category, products] : categoryMap) {
        int catUnits = 0;
        double catRevenue = 0.0;

        for (const auto& product : products) {
            reportFile << left << setw(20) << product.name
                       << "  " << setw(15) << product.category
                       << right << setw(11) << product.unitsSold
                       << setw(13) << fixed << setprecision(2) << product.unitPrice
                       << setw(15) << product.totalRevenue << "\n";

            catUnits += product.unitsSold;
            catRevenue += product.totalRevenue;
        }

        reportFile << setw(38) << " " << "  -----------  -------------\n";
        reportFile << category << " Subtotal:" << setw(11) << " "
                   << setw(11) << catUnits
                   << setw(15) << fixed << setprecision(2) << catRevenue << "\n\n";
    }

    // Summary Statistics
    reportFile << "=====================================\n";
    reportFile << "SUMMARY STATISTICS\n";
    reportFile << "=====================================\n";
    reportFile << "Total Products Sold: " << productMap.size() << "\n";
    reportFile << "Total Units Sold: " << totalUnits << "\n";
    reportFile << "Total Revenue: $" << fixed << setprecision(2) << totalRevenue << "\n";
    reportFile << "Average Sale Value: $" << (transactionCount ? totalRevenue / transactionCount : 0.0) << "\n";
    reportFile << "Best-Selling Product: " << bestProduct.name << " ($" << bestProduct.totalRevenue << ")\n";

    inputFile.close();
    reportFile.close();

    cout << "Formatted report generated: sales_summary.txt\n";
    return 0;
}
