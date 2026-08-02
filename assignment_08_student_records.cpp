// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
    string name;
    int id;
    vector<double> scores;
};

double calculateAverage(const vector<double>& scores) {
    if (scores.empty()) return 0.0;
    double sum = 0.0;
    for (double score : scores) {
        sum += score;
    }
    return sum / scores.size();
}

void addStudent(vector<Student>& students) {
    Student newStudent;

    cout << "\n--- Add Student ---\n";
    cout << "Student name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear newline buffer
    getline(cin, newStudent.name);

    cout << "Student ID: ";
    while (!(cin >> newStudent.id)) {
        cout << "Invalid input. Please enter a valid numerical ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int scoreCount;
    cout << "How many scores? ";
    while (!(cin >> scoreCount) || scoreCount < 0) {
        cout << "Invalid input. Please enter a positive integer for scores count: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (int i = 0; i < scoreCount; ++i) {
        double score;
        cout << "Enter score " << (i + 1) << ": ";
        while (!(cin >> score) || score < 0 || score > 100) {
            cout << "Invalid score. Enter a number between 0 and 100: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        newStudent.scores.push_back(score);
    }

    students.push_back(newStudent);
    cout << "Student \"" << newStudent.name << "\" added successfully.\n";
}


void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "\nNo students have been added yet.\n";
        return;
    }

    cout << "\n=========================================================================\n";
    cout << left << setw(20) << "Name" 
         << setw(12) << "ID" 
         << setw(25) << "Scores" 
         << setw(10) << "Average" << "\n";
    cout << "-------------------------------------------------------------------------\n";

    for (const auto& student : students) {
        // Construct scores string
        string scoresStr = "";
        for (size_t i = 0; i < student.scores.size(); ++i) {
            
            scoresStr += to_string((int)student.scores[i]); 
            if (i < student.scores.size() - 1) scoresStr += ", ";
        }
        if (scoresStr.empty()) scoresStr = "N/A";

        double avg = calculateAverage(student.scores);

        cout << left << setw(20) << student.name
             << setw(12) << student.id
             << setw(25) << scoresStr
             << fixed << setprecision(2) << setw(10) << avg << "\n";
    }
    cout << "=========================================================================\n";
}


void calculateAverageForStudent(const vector<Student>& students) {
    if (students.empty()) {
        cout << "\nNo student records available.\n";
        return;
    }

    int searchId;
    cout << "\nEnter student ID: ";
    while (!(cin >> searchId)) {
        cout << "Invalid input. Enter a numerical ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    bool found = false;
    for (const auto& student : students) {
        if (student.id == searchId) {
            found = true;
            double avg = calculateAverage(student.scores);
            cout << fixed << setprecision(2);
            cout << student.name << "'s average score: " << avg << "\n";
            break;
        }
    }

    if (!found) {
        cout << "Error: Student with ID " << searchId << " not found.\n";
    }
}


int main() {
    vector<Student> students;
    int choice = 0;

    do {
        cout << "\n================================\n";
        cout << "   STUDENT RECORD SYSTEM MENU   \n";
        cout << "================================\n";
        cout << "1. Add student\n";
        cout << "2. Display all students\n";
        cout << "3. Calculate average score\n";
        cout << "4. Quit\n";
        cout << "Enter your choice (1-4): ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number between 1 and 4.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                calculateAverageForStudent(students);
                break;
            case 4:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please select an option from 1 to 4.\n";
        }

    } while (choice != 4);

    return 0;
}