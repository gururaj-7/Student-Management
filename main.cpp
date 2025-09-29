#include <iostream>
#include <string>
using namespace std;

// Structure to store student details
struct Student {
    int id;
    string name;
    int age;
    float percentage;
};


class StudentManager {
private:
    Student students[100]; 
    int count;             

public:
    StudentManager(); 
    void addStudent();
    void showStudents();
};


StudentManager::StudentManager() {
    count = 0; // Initially no students
}

// This function adds a new student
void StudentManager::addStudent() {
    cout << "Enter Student ID: ";
    cin >> students[count].id;

    cin.ignore();
    
    cout << "Enter Student Name: ";
    getline(cin, students[count].name);

    cout << "Enter Student Age: ";
    cin >> students[count].age;

    cout << "Enter Student Percentage: ";
    cin >> students[count].percentage;

    count++;
    cout << "Student added successfully!\n";
}

// This function displays all students
void StudentManager::showStudents() {
    if (count == 0) {
        cout << "No students added yet.\n";
        return;
    }

    cout << "\n--- Student List ---\n";
    for (int i = 0; i < count; i++) {
        cout << "ID: " << students[i].id << "\n";
        cout << "Name: " << students[i].name << "\n";
        cout << "Age: " << students[i].age << "\n";
        cout << "Percentage: " << students[i].percentage << "%\n";
    }
}

int main() {
    StudentManager manager; 
    int choice;

    do {
        cout << "1. Add Student\n";
        cout << "2. Show Students\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            manager.addStudent();
        } else if (choice == 2) {
            manager.showStudents();
        } else if (choice != 0) {
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
