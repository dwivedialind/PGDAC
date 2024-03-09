#include<stdio.h>
#include<string.h>
#define SIZE 4

int main(void){
    
   char* arr[] = {"apple", "banana", "apple", "banana"};



    for(int i = 0 ; i < SIZE; i++){
        for(int j = i+1; j <SIZE; j++){
            if(!strcmp(arr[i],arr[j])){
                printf("%s ",arr[j]);
                break;
            }
        }
    }



    return 0;
}