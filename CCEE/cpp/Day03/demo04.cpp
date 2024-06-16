#include<iostream>

using namespace std;

class Parent{
    int x;
    int y;
    public:
        Parent(){
            cout<<"Parent constructor" << endl;
        }
        Parent (int a){
            cout<<"Parent param constructor"<<endl;
        }
        virtual ~ Parent(){
            cout << "Parent destructor"<<endl;
        }
};
class Child: public Parent{
    public:
        Child(){
            cout<<"Child constructor" << endl;
        }
        ~ Child(){
            cout<<"Child destructor" << endl;
        }
       
};

int main(){

   // Parent p;
    Child c;
    c.~Child();
    return 0;
}