#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    printf("Enter a string: \n");
    char* input = (char *)malloc(sizeof(char)*100);
    fgets(input,100,stdin);//safer input
    char* reversedString = (char *)calloc(100, sizeof(char));
    int j = 0;
    for(int i = strlen(input)-1; i>=0; i--){
        reversedString[j] = input[i];
        j++;
    }
    puts(reversedString);
    free(input);
    free(reversedString);
    return 0;
}