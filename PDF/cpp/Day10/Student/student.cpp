#include "Student.h"


Student::Student(){

}
Student::Student(int rollNo, string name, Course *c){
    this->name = name;
    this->rollNo = rollNo;
    course = c;
    
}
void Student::writeToFile(){
    ofstream fout("studentData.txt", ios::app);
    fout << rollNo << "," << name << ",";
    fout << course->get_CouseId() << "," <<
        course->get_CourseName() << "," << course->get_fees() ;

    fout << endl;
    fout.close();
}

void Student::addCourse(){
        course = new Course;
        course->acceptCourse();
        
   
}

void Student::accept(){
    cout << "Student Roll No: " << endl;
    cin >> rollNo;
    cout << "Student Name: " << endl;
    cin.ignore();
    getline(cin, name);
    addCourse();        
    writeToFile();
}

void Student::display(){
    cout << "Student Roll No: " << rollNo << endl;
    cout << "Student Name: " << name << endl;
    cout << course->get_CouseId() << "," <<
        course->get_CourseName() << "," << course->get_fees() << endl;
 
    
}

Student::~Student(){
    delete course;
    course = NULL;
}
