#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <algorithm>
#include <cctype>

using namespace std;

// Helper function to get current timestamp
string getCurrentTimestamp() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", ltm);
    return string(buffer);
}

// Add a new journal entry
void addEntry() {
    string content;
    string timestamp = getCurrentTimestamp();

    cout << "Enter your journal entry:\n";
    getline(cin, content);

    ofstream file("journal.txt", ios::app); // Append mode
    if (file.is_open()) {
        file << "Timestamp: " << timestamp << "\n";
        file << "Entry: " << content << "\n";
        file << "--------------------------\n";
        file.close();
        cout << "Entry saved successfully!\n";
    } else {
        cout << "Error: Could not open journal.txt\n";
    }
}

// View all journal entries
void viewEntries() {
    ifstream file("journal.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << "\n";
        }
        file.close();
    } else {
        cout << "No journal entries found.\n";
    }
}

// Search for entries containing a keyword (partial, case-insensitive)
void searchEntries() {
    string keyword;
    cout << "Enter keyword to search: ";
    getline(cin, keyword);

    // Convert keyword to lowercase
    for (char& c : keyword) {
        c = tolower(c);
    }

    ifstream file("journal.txt");
    if (!file.is_open()) {
        cout << "No journal entries found.\n";
        return;
    }

    string line;
    bool found = false;
    while (getline(file, line)) {
        string lowerLine = line;
        for (char& c : lowerLine) {
            c = tolower(c);
        }

        if (lowerLine.find(keyword) != string::npos) {
            cout << line << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No entries matched your search.\n";
    }

    file.close();
}

// Display the main menu
void showMenu() {
    cout << "\n--- Personal Journal Menu ---\n";
    cout << "1. Add Entry\n";
    cout << "2. View Entries\n";
    cout << "3. Search Entries\n";
    cout << "4. Exit\n";
    cout << "Choose an option: ";
}

// Main program loop
int main() {
    string choice;
    while (true) {
        showMenu();
        getline(cin, choice);
        if (choice == "1") {
            addEntry();
        } else if (choice == "2") {
            viewEntries();
        } else if (choice == "3") {
            searchEntries();
        } else if (choice == "4") {
            cout << "Exiting journal. Goodbye!\n";
            break;
        } else {
            cout << "Invalid option. Please try again.\n";
        }
    }
    return 0;
}
