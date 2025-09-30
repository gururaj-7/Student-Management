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
    void searchStudent();  
    void updateStudent();   
    void deleteStudent(); 
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
        cout << "\n-----------------------\n";
    }
}

// This function searches for a student by ID
void StudentManager::searchStudent()
{
    int id;

    cout << "Enter Student ID to search: ";
    cin >> id;

    for (int i = 0; i < count; i++)
    {
        if(students[i].id == id)
        {
            cout << "Student found:\n";
            cout << "ID: " << students[i].id << "\n";
            cout << "Name: " << students[i].name << "\n";
            cout << "Age: " << students[i].age << "\n";
            cout << "Percentage: " << students[i].percentage << "%\n";
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

    for (int i = 0; i < count; i++)
    {
        if(students[i].id == id)
        {
            cout << "Enter new name: ";
            getline(cin, students[i].name);

            cout << "Enter new age: ";
            cin >> students[i].age;

            cout << "Enter new percentage: ";
            cin >> students[i].percentage;

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

    for (int i = 0; i < count; i++)
    {
        if(students[i].id == id)
        {
            for (int j = i; j < count - 1; j++)
            {
                students[j] = students[j + 1];
            }
            count--;
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
