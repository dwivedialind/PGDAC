#include<stdio.h>

struct Employee{
    char first_name[20]; // first name of an employee
    char last_name[20]; // last name of an employee
    double salary; // salary of an employee

};

void emp_init(struct Employee* s){
    printf("Enter first name: ");
    gets(s->first_name);
    printf("Enter last name: ");
    gets(s->last_name);

}

void set_salary(double salary, struct Employee* s){
    s->salary = salary;

}
void display(struct Employee* s){
    printf("Name: %s %s",s->first_name,s->last_name);
    printf("\n Salary: %.2lf\n",s->salary);
}
void increment(struct Employee* s, double n){ //increment by n%
    s->salary = (s->salary)*(1+n/100);
}
int main(){
    struct Employee e1;
    struct Employee e2;
    double salary1 = 20000.454; //salary of e1
    double salary2 = 26000.3434; //salary of e2
    emp_init(&e1);
    emp_init(&e2);
    set_salary(salary1,&e1);
    set_salary(salary2, &e2);

    display(&e1);
    display(&e2);

    increment(&e1, 10);
    increment(&e2, 10);

    display(&e1);
    display(&e2);

    //increment salary by 10%


    return 0;
}