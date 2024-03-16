#include "Student.h"



void deleteStudent(list<Student *> &studentList){
    cout << "Roll No of Student to Delete: " << endl;
    int rollNo;
    cin >> rollNo;
    for(int i=0; i<studentList.size(); i++){
        
    }
}

void loadData(list<Student *> &studentList){
    ifstream fin("studentData.txt");
    string data;
    
    while(getline(fin,data)){
      
        stringstream mydata(data);
        string rollNo, name, courseId, courseName, courseFees;

        getline(mydata,rollNo,',');
        getline(mydata,name,',');
        getline(mydata,courseId,',');
        getline(mydata,courseName,',');
        getline(mydata,courseFees,',');

        
        studentList.push_back(new Student(stoi(rollNo), name, new Course(stoi(courseId),courseName,stod(courseFees))));
        
}
    fin.close();
}

int main()
{
    list<Student *> studentList;
    loadData(studentList);
    int choice;
    Student *s = NULL;
    
    do {
        cout << "1. Add Student" << endl;
        cout << "2. Remove Student Data" << endl;
        cout << "3. Display All Students" << endl;
        cout << "0. Exit" << endl;
        cout << "Please enter your choice! ";
        cin >> choice;
    
        switch (choice) {
            case 1:
            try{
                s = new Student;
                s->accept();
                studentList.push_back(s);
            }catch(Exception &e){
                delete s;

                e.negativeFees();
            }
                break;
            case 2:
                
                break;
            case 3:
                for(Student* i:studentList)
                    i->display();
                break;
            case 0:
                cout << "Thank you for using!" << endl;
                break;
            default:
                cout << "Please enter a valid choice !" << endl;
        }
    } while (choice != 0);

    for(Student *i: studentList ){
        delete i;
    }
    s = NULL;
    
   
    return 0;
}