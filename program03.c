#include<stdio.h>

int main(){

    printf("Upto which sequence you want fibonacci series: ");
    int n; // index upto which series
    scanf("%d",&n);
    
    int a = 0 ;
    int b = 1;
    if(n==1){
        printf("%d",a);
        return 0;
    }
    if(n==2){
        printf("%d %d",a,b);
        return 0;

    }
    printf("0 1 ");
    for(int i = 2 ; i < n ; i++){
        int temp = b;
        b = a+b;
        a = temp;
        printf("%d ",b);
    }
    

    printf("\n");
    return 0;
}
