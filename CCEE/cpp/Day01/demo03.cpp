#include<iostream>
using namespace std;

struct Time{
    int hrs;
    int min;
    void printTime(){
        cout << hrs << ":"<<min<<endl;
    }
};

int main(){

    struct Time *t = new Time();
    t->hrs = 10;
    t->min = 43;
    t->printTime();  
    return 0;
}