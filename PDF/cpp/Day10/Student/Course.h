#ifndef COURSE_H
#define COURSE_H
#endif
#include "Exception.h"
#include<iostream>
using namespace std;

class Course{
    int cid;
    string course_name;
    double fees;
 public:
    Course();
    Course(int cid, string course_name, double fees);
    void acceptCourse();
    void displayCourse();
    int get_CouseId() const;
    string get_CourseName() const;
    double get_fees() const;

};