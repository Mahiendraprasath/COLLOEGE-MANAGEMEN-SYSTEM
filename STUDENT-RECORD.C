#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of students
#define MAX_STUDENTS 100

// Structure to store student details
typedef struct {
    int id;
    char name[50];
    int age;
    char department[50];
} Student;

// Global array to store student records
Student students[MAX_STUDENTS];
int studentCount = 0;

// Function prototypes
void addStudent();
void displayStudents();
void deleteStudent();

int main() {
    int choice;
    
    while (1) {
        printf("\nCollege Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Delete Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Cannot add more students. Maximum limit reached.\n");
        return;
    }

    Student newStudent;
    printf("Enter student ID: ");
    scanf("%d", &newStudent.id);
    printf("Enter student name: ");
    scanf("%s", newStudent.name);
    printf("Enter student age: ");
    scanf("%d", &newStudent.age);
    printf("Enter student department: ");
    scanf("%s", newStudent.department);

    students[studentCount++] = newStudent;
    printf("Student added successfully.\n");
}

void displayStudents() {
    if (studentCount == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\nStudent Records:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d, Name: %s, Age: %d, Department: %s\n", 
               students[i].id, students[i].name, students[i].age, students[i].department);
    }
}

void deleteStudent() {
    if (studentCount == 0) {
        printf("No students to delete.\n");
        return;
    }

    int id;
    printf("Enter student ID to delete: ");
    scanf("%d", &id);

    int index = -1;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Student not found.\n");
        return;
    }

    for (int i = index; i < studentCount - 1; i++) {
        students[i] = students[i + 1];
    }

    studentCount--;
    printf("Student deleted successfully.\n");
}
