#include <stdio.h>
#include <string.h>

// Define a structure for student
struct Student {
    char name[50];
    int roll_no;
    char grade;
};

// Function to read student information
void readStudents(struct Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]%*c", students[i].name);  // Read string with spaces
        printf("Roll Number: ");
        scanf("%d", &students[i].roll_no);
        printf("Grade: ");
        scanf(" %c", &students[i].grade);
    }
}

// Function to display student information
void displayStudents(struct Student students[], int n) {
    printf("\nStudent Information:\n");
    printf("Name\tRoll Number\tGrade\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t\t%c\n", students[i].name, students[i].roll_no, students[i].grade);
    }
}

// Function to sort students by roll number
void sortStudentsByRollNo(struct Student students[], int n) {
    struct Student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].roll_no > students[j + 1].roll_no) {
                // Swap students[j] and students[j + 1]
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student students[n];  // Array of Student structures

    readStudents(students, n);
    printf("\nBefore Sorting:\n");
    displayStudents(students, n);

    sortStudentsByRollNo(students, n);

    printf("\nAfter Sorting by Roll Number:\n");
    displayStudents(students, n);

    return 0;
}
