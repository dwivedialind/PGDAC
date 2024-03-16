#include "Course.h"

Course::Course(){

}
Course::Course(int cid, string course_name, double fees){
    this->cid = cid;
    this->course_name = course_name;
    this->fees = fees;
}

void Course::acceptCourse(){
    cout << "Enter Course Id: ";
    cin >> cid;
    cin.ignore();
    cout << "Enter Course Name: ";
    getline(cin, course_name);
    cout << "Enter Course Fees: ";
    cin >> fees;
    if(fees<0)
        throw Exception(fees);
}

void Course::displayCourse(){
    cout << "Course Name: " << course_name << endl;
    cout << "Course Id: " << cid << endl;
    cout << "Course Fees: " << fees << endl;
}

int Course::get_CouseId() const{
    return cid;
}

string Course::get_CourseName() const{
    return course_name;
}

double Course::get_fees() const{
    return fees;
}