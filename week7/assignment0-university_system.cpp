#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Student {
private:
    string name;
    int ID;
    float GPA;

public:
    Student(string name, int ID, float GPA) : name(name), ID(ID), GPA(GPA) {}

    string getName() const { return name; }
    int getID() const { return ID; }
    float getGPA() const { return GPA; }

    void updateGPA(float newGPA) {
        if (newGPA >= 0.0 && newGPA <= 4.0) {
            GPA = newGPA;
        } else {
            cout << "Invalid GPA. Must be between 0.0 and 4.0.\n";
        }
    }

    void display() const {
        cout << "Name: " << name << "\nID: " << ID << "\nGPA: " << GPA << "\n";
    }
};


class Course {
private:
    string code;
    string title;
    int creditHours;

public:
    Course(string code, string title, int creditHours)
        : code(code), title(title), creditHours(creditHours) {}

    string getCode() const { return code; }
    string getTitle() const { return title; }
    int getCreditHours() const { return creditHours; }

    void display() const {
        cout << "Course Code: " << code
             << "\nTitle: " << title
             << "\nCredit Hours: " << creditHours << "\n";
    }
};

void showMenu() {
    cout << "\n--- Student Management Menu ---\n";
    cout << "1. Add Student\n";
    cout << "2. Remove Student\n";
    cout << "3. Edit Student GPA\n";
    cout << "4. Display All Students\n";
    cout << "5. Display All Courses\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    vector<Student> students = {
        Student("Alice", 101, 3.6),
        Student("Bob", 102, 3.8),
        Student("Charlie", 103, 3.2)
    };

    vector<Course> courses = {
        Course("CS101", "Intro to Programming", 3),
        Course("MATH201", "Calculus II", 4)
    };

    int choice;
    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                int id;
                float gpa;
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter GPA: ";
                cin >> gpa;
                students.emplace_back(name, id, gpa);
                cout << "Student added.\n";
                break;
            }
            case 2: {
                int id;
                cout << "Enter ID of student to remove: ";
                cin >> id;
                auto it = remove_if(students.begin(), students.end(),
                                    [id](const Student& s) { return s.getID() == id; });
                if (it != students.end()) {
                    students.erase(it, students.end());
                    cout << "Student removed.\n";
                } else {
                    cout << "Student not found.\n";
                }
                break;
            }
            case 3: {
                int id;
                float newGPA;
                cout << "Enter student ID to update GPA: ";
                cin >> id;
                bool found = false;
                for (auto& s : students) {
                    if (s.getID() == id) {
                        cout << "Enter new GPA: ";
                        cin >> newGPA;
                        s.updateGPA(newGPA);
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Student not found.\n";
                break;
            }
            case 4: {
                cout << "\n--- Student List ---\n";
                for (const auto& s : students) {
                    s.display();
                    cout << "------------------\n";
                }
                break;
            }
            case 5: {
                cout << "\n--- Course List ---\n";
                for (const auto& c : courses) {
                    c.display();
                    cout << "------------------\n";
                }
                break;
            }
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
