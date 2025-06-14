#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <limits>

using namespace std;

// Structure to hold student information
struct Student {
    string id;
    string name;
    map<string, int> courses; // course name -> numeric grade
    double gpa = 0.0;
};

// Convert numeric grade to GPA scale
double gradeToGPA(int grade) {
    if (grade >= 90) return 4.0;
    if (grade >= 80) return 3.0;
    if (grade >= 70) return 2.0;
    if (grade >= 60) return 1.0;
    return 0.0;
}

// Read student records from input file
bool readStudentData(const string& filename, vector<Student>& students, int& totalCourses, double& totalGPA) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error: Could not open input file.\n";
        return false;
    }

    string line;
    int lineNumber = 0;
    totalCourses = 0;
    totalGPA = 0.0;

    while (getline(infile, line)) {
        lineNumber++;
        if (line.empty() || line[0] == '#') continue;

        istringstream iss(line);
        Student s;
        string firstName, lastName;
        if (!(iss >> s.id >> firstName >> lastName)) {
            cerr << "Warning: Skipping malformed line " << lineNumber << ": " << line << "\n";
            continue;
        }
        s.name = firstName + " " + lastName;

        string token;
        int courseCount = 0;
        double gpaSum = 0.0;

        while (iss >> token) {
            size_t colonPos = token.find(':');
            if (colonPos == string::npos) {
                cerr << "Warning: Invalid course format on line " << lineNumber << ": " << token << "\n";
                continue;
            }
            string course = token.substr(0, colonPos);
            int grade;
            try {
                grade = stoi(token.substr(colonPos + 1));
            } catch (...) {
                cerr << "Warning: Invalid grade on line " << lineNumber << ": " << token << "\n";
                continue;
            }
            if (grade < 0 || grade > 100) {
                cerr << "Warning: Grade out of range on line " << lineNumber << ": " << token << "\n";
                continue;
            }
            s.courses[course] = grade;
            gpaSum += gradeToGPA(grade);
            courseCount++;
        }

        if (courseCount == 0) {
            cerr << "Warning: No valid courses for student on line " << lineNumber << ": " << line << "\n";
            continue;
        }

        s.gpa = gpaSum / courseCount;
        totalCourses += courseCount;
        totalGPA += s.gpa;
        students.push_back(s);
    }

    infile.close();
    return true;
}

// Write formatted report to output file
void writeReport(const string& filename, const vector<Student>& students, int totalCourses, double totalGPA) {
    ofstream outfile(filename);
    if (!outfile) {
        cerr << "Error: Could not open output file.\n";
        return;
    }

    outfile << "STUDENT ACADEMIC RECORD PROCESSOR\n";
    outfile << "---------------------------------\n\n";
    outfile << "Reading student records from input file...\n\n";
    outfile << "STUDENT GRADE REPORT\n";
    outfile << "-------------------\n";
    outfile << left << setw(8) << "ID"
            << setw(20) << "Name"
            << right << setw(17) << "Courses Taken"
            << setw(8) << "GPA" << "\n";
    outfile << "-----   ----------------   -------------    ----\n";

    for (const auto& s : students) {
        outfile << left << setw(8) << s.id
                << setw(20) << s.name
                << right << setw(17) << s.courses.size()
                << setw(8) << fixed << setprecision(2) << s.gpa << "\n";
    }

    outfile << "\nCLASS STATISTICS\n";
    outfile << "----------------\n";
    outfile << "Total Students: " << students.size() << "\n";
    outfile << "Total Courses Taken: " << totalCourses << "\n";
    double classAvgGPA = students.empty() ? 0.0 : totalGPA / students.size();
    outfile << "Class Average GPA: " << fixed << setprecision(2) << classAvgGPA << "\n\n";

    if (!students.empty()) {
        const Student* highest = &students[0];
        const Student* lowest = &students[0];
        for (const auto& s : students) {
            if (s.gpa > highest->gpa) highest = &s;
            if (s.gpa < lowest->gpa) lowest = &s;
        }
        outfile << "Highest GPA: " << highest->name << " (" << fixed << setprecision(2) << highest->gpa << ")\n";
        outfile << "Lowest GPA: " << lowest->name << " (" << fixed << setprecision(2) << lowest->gpa << ")\n";
    }

    outfile << "\nSummary report written to output file successfully.\n";
    outfile.close();
}

// Main function
int main() {
    string inputFile = "student_data.txt";
    string outputFile = "student_report.txt";

    vector<Student> students;
    int totalCourses = 0;
    double totalGPA = 0.0;

    if (readStudentData(inputFile, students, totalCourses, totalGPA)) {
        writeReport(outputFile, students, totalCourses, totalGPA);
        cout << "Report generated successfully in '" << outputFile << "'.\n";
    } else {
        cerr << "Failed to generate report due to input errors.\n";
    }

    return 0;
}
