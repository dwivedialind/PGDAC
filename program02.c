#include<stdio.h>

int factorial(int);

int main(){
    //we have to write a program to find factorial of a number
    /*
    Edge case: i. input = 0
    */
   int value; //value factorial of which we have to find
   printf("Enter a Value to find factorial of: ");
   scanf("%d",&value);
   printf("Factorial is: %d",factorial(value));
   
    return 0;
}

int factorial(int n){
    if(n==0)
        return 1;
    return n * factorial(n-1);
}