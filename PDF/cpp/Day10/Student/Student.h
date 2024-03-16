#ifndef STUDENT_H
#define STUDENT_H
#endif

#include<vector>
#include "Course.h"

#include<list>

#include<sstream>
#include<fstream>


class Student{
    private:
        int rollNo;
        string name;
        //int standard;
        //vector<int> marks;
        Course *course;
        void writeToFile();
            
            
    
    public:
        Student();
        Student(int rollNo, string name, Course *c);
        void addCourse();
        void accept();
        void display();
        ~Student();
};