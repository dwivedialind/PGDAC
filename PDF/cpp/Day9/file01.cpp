#include<iostream>
using namespace std;
void fun() throw(double){
    throw 1;
}
int main()
{   

    try{
        fun();
    }catch(int e){
        cout << "Exception generated!" << endl;
    }
    return 0;
}