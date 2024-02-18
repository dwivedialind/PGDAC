#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){

    char* strInput;
    strInput = (char *)malloc(100*sizeof(char));

    if(strInput == NULL)
    {
        printf("NO memory allocated");
        return 0;
    }

    puts("Type an input string: \n");
    gets(strInput);
    
    //we will check for no. of lower case , no. of upper case and no. of other characcter, no. of digits

    int lowercaseLetters = 0; //no. of lowercase letters
    int uppercaseLetters = 0; //no. of uppercase letters
    int digits = 0; //no. of digits
    int otherCharacters = 0; // no. of other characters
    int i = 0;
    while(i<strlen(strInput)){

        if(strInput[i]>=48 && strInput[i]<=57) //digit
            digits++;
        else if(strInput[i]>=65 && strInput[i]<=90)
            uppercaseLetters++;
        else if(strInput[i]>=97 && strInput[i]<=122)
            lowercaseLetters++;
        else
            otherCharacters++;
        
        i++;
    }

    printf("Lowercase-Letters: %d Uppercase-Letters: %d other-characters: %d digits: %d", lowercaseLetters, uppercaseLetters, otherCharacters, digits);
    free(strInput);

    return 0;
}