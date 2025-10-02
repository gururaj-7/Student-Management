#include <iostream>
#include <string>
#include <vector>
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
    // Student students[100]; 
    // int count;
    
    vector<Student> students; 

public:
    void addStudent();
    void showStudents();
    void searchStudent();  
    void updateStudent();   
    void deleteStudent(); 
};

// This function adds a new student
void StudentManager::addStudent() {
    Student s;

    cout << "Enter Student ID: ";
    cin >> s.id;

    cin.ignore();
    
    cout << "Enter Student Name: ";
    getline(cin, s.name);

    cout << "Enter Student Age: ";
    cin >> s.age;

    cout << "Enter Student Percentage: ";
    cin >> s.percentage;

    students.push_back(s);
    cout << "Student added successfully!\n";
}

// This function displays all students
void StudentManager::showStudents() {
    if (students.empty()) {
        cout << "No students added yet.\n";
        return;
    }

    cout << "\n--- Student List ---\n";
    for (int i = 0; i < students.size(); i++) {
        Student *s = &students[i];
        cout << "ID: " << s->id << "\n";
        cout << "Name: " << s->name << "\n";
        cout << "Age: " << s->age << "\n";
        cout << "Percentage: " << s->percentage << "%\n";
        cout << "\n-----------------------\n";
    }
}

// This function searches for a student by ID
void StudentManager::searchStudent()
{
    int id;

    cout << "Enter Student ID to search: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++)
    {
        Student *s = &students[i];
        if(s->id == id)
        {
            cout << "Student found:\n";
            cout << "ID: " << s->id << "\n";
            cout << "Name: " << s->name << "\n";
            cout << "Age: " << s->age << "\n";
            cout << "Percentage: " << s->percentage << "%\n";
            cout << "\n-----------------------\n";
            return;
        }
    }
    cout << "Student with ID " << id << " not found.\n";   
}

// This function update student details by ID
void StudentManager::updateStudent()
{
    int id;

    cout << "Enter Student ID to update: ";
    cin >> id;
    cin.ignore();

    for (int i = 0; i < students.size(); i++)
    {
        Student *s = &students[i]; 
        if(s->id == id)
        {
            cout << "Enter new name: ";
            getline(cin, s->name);

            cout << "Enter new age: ";
            cin >> s->age;

            cout << "Enter new percentage: ";
            cin >> s->percentage;

            cout << "Student details updated successfully!\n";
            return;
        }
    }
    cout << "Student with ID " << id << " not found.\n"; 
}

// This function deletes a student by ID
void StudentManager::deleteStudent()
{
    int id;
    cout << "Enter Student ID to delete: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++)
    {
        Student *s = &students[i]; 
        if(s->id == id)
        {
            students.erase(students.begin() + i);
            cout << "Student deleted successfully!\n";
            return;
        }
    }
    cout << "Student with ID " << id << " not found.\n"; 
}

int main() {
    StudentManager manager; 
    int choice;

    do {
        cout << "1. Add Student\n";
        cout << "2. Show Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            manager.addStudent();
        } else if (choice == 2) {
            manager.showStudents();
        } else if (choice == 3) {
            manager.searchStudent();
        }   else if (choice == 4) {
            manager.updateStudent();
        }   else if (choice == 5) {
            manager.deleteStudent();    
        } else if (choice != 0) {
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
