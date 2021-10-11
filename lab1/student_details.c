/*
    Program to store student data 
*/

// Header Files
#include <stdio.h>

// constants
#define MAX_SIZE 1000

// Declarations
struct Student {
    
    int id;
    int age;
    int marks;
};   
    // data for a student
void input_a_student(struct Student*);
    // prompts data for student 
void output_a_student(struct Student);
    // displays data of a student

//  Main
int main() {
    
    // data
    struct Student students[MAX_SIZE];
    int students_size;
    
    // take input
    printf("Enter the number of students: ");
    scanf("%d", &students_size);
    //
    printf("\n");
    printf("Enter the details of each student:\n");
    for (int i = 0; i < students_size; ++i) {
        input_a_student(&students[i]);
    }
    
    // display 
    printf("\n");
    printf("Here are the details of each stored student:\n");
    for (int i = 0; i < students_size; ++i) {
        output_a_student(students[i]);
    }
    
    return 0;
}

// definitions
void input_a_student(struct Student* student) {
    
    printf("Enter details of a student:\n");
    
    printf("Enter ID: ");
    scanf("%d", &student->id);
    
    printf("Enter Age: ");
    scanf("%d", &student->age);
    
    printf("Enter Marks: ");
    scanf("%d", &student->marks);
}
//
void output_a_student(struct Student student) {
    
    printf("Details of a student:\n");
    printf("ID: %d\n"
          "Age: %d\n"
          "Marks: %d\n",
          student.id, student.age, student.marks);
}
