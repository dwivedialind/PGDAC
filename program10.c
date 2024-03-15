#include<stdio.h>

void readStudents(char* student[]){

    printf("Please enter name of Students: ");
    int i = 0;
    while(i < 10){
        scanf("%49s",student[i]);
    }

}

int main(void){
    char nameOfStudents[10][50];

    readStudents(&nameOfStudents);

}