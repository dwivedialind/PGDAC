#include<stdio.h>
#include<limits.h>
#include<stdlib.h>


int main(int argc, const char *argv[])
{
    printf("Enter the numbers to find max of after cli arguments: \n");
    int max = INT_MIN;
    for(int i = 1; i < argc ; i++){
        int n = atoi(argv[i]);
        if(max < n)
            max = n;
    }
    printf("Max is: %d ", max);
    return 0;
}

// int main(){
//     printf("Enter the number of inputs: ");
//     int n; // no. of inputs
//     scanf("%d",&n);
//     int a = INT_MIN;
//     while(n!=0){
//         int b;
//         scanf("%d",&b);
//         if(b>a)
//             a = b;
//             n--;
//     }
//     printf("Maximum is: %d",a);
//     return 0;
// }