#include<stdio.h>
typedef struct StudentGrade{
    char* subject[5];
    char* grade[5];
} StudentData;


int main(){
    StudentData st;
    st.subject[0] = "English";
    st.subject[1] = "Hindi";
    st.subject[2] = "Maths";
    st.subject[3] = "Physcis";
    st.subject[4] = "Chemistry";
    int n = 0;
    while(n<5){
        int numberObtained = 0; //number Obtained
        printf("what is score in %s ",st.subject[n]);
        scanf("%d",&numberObtained);
        //As we can't use variable in switch case expression so better we're using if else
        if(numberObtained>=90){
            st.grade[n] = "Ex";
        }
        else if(numberObtained < 90 && numberObtained >= 80){
            st.grade[n] = "A";
        }
        else if(numberObtained < 80 && numberObtained >= 70){ 
            st.grade[n] = "B";
        }
        else if(numberObtained < 70 && numberObtained >= 60){
            st.grade[n] = "C";
        }
        else if(numberObtained < 60){
            st.grade[n] = "F";
        }
        printf("Subject %s Grade %s\n",st.subject[n], st.grade[n]);
        n++;
    }
    return 0;
}