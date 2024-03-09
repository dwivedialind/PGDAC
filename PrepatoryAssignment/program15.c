#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
 int letter[26] = {0};
  
 char stringInput[200];
 printf("Enter a String: \n");
 gets(stringInput);

 for(int i = 0; i < strlen(stringInput); i++){
    char c = stringInput[i];
    if(c==32)
        continue;
    c = toupper(c); //convert character to upper
    letter[c-65]++ ;//update in array
}

for(int i = 0; i < 26; i++){
    if(letter[i]==0)
        continue;
    printf("%c %d\n",i+65, letter[i]);
}

 
 return 0;
}