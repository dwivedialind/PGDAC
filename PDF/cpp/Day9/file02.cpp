#include<iostream>
using namespace std;

void fun(){
    throw 1;
}
int main()
{
    try{
try{
throw ArithmeticException("/ by zero");
}
catch( ArithmeticException &ex)
{
cout<<"Inside inner catch"<<endl;
throw; //throw ex;
}
}
catch( ArithmeticException &ex){
cout<<"Inside outer catch"<<endl;
}
catch(...){
cout<<"Inside generic catch block"<<endl;
}
    return 0;
}