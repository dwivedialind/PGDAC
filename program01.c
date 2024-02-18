#include<stdio.h>
#include<limits.h>

int main(){
    printf("Enter the number of inputs: ");
    int n; // no. of inputs
    scanf("%d",&n);
    int a = INT_MIN;
    while(n!=0){
        int b;
        scanf("%d",&b);
        if(b>a)
            a = b;
            n--;
    }
    printf("Maximum is: %d",a);
    return 0;
}