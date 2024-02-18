#include <stdio.h>
#include <stdlib.h>

typedef struct StudentData {
    char *studentName; // name of Student
    char *rollNo;      // ex: 0601ME171007 alphanumeric
    int marks;         // (total Marks Obtained)
} Student;

void readStudentName(Student *s) {
    printf("Enter Student Name: \n");
    s->studentName = (char*)malloc(100 * sizeof(char)); // Allocating memory
    gets(s->studentName);
    fflush(stdin);
    printf("Student Name: %s\n", s->studentName);
}

void readRollNo(Student *s) {
    printf("Enter Roll No: \n");
    s->rollNo = (char*)malloc(20 * sizeof(char)); // Allocating memory
    scanf("%s", s->rollNo);
    printf("Student Roll No: %s\n", s->rollNo);
}

void readMarks(Student *s) {
    printf("Enter Total marks: \n");
    scanf("%d", &(s->marks));
    printf("Student Total Marks: %d\n", s->marks);
}


void freeStudent(Student *s) {
    free(s->studentName);
    free(s->rollNo);
}

int main() {
    Student s;

    readStudentName(&s);
    readRollNo(&s);
    readMarks(&s);

    // Perform other operations

    freeStudent(&s); // Free allocated memory

    return 0;
}
