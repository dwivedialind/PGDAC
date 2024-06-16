#include <iostream>

using namespace std;


class Employee{
    public:
        int id;
        string name;
        double salary;
};

int main(){
    Employee e;
    e.id = 10;
    cout << e.name << endl;
    e.name = "alind";
    
}