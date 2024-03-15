#include<iostream>
using namespace std;

void fun(){
    int a = 10;
    int *b = new int(10);
    throw 1;    
    delete b;

}

int main()
{
    try{
        fun();
    }catch(...){
        cout << "Handled" << endl;
    }
    return 0;
}