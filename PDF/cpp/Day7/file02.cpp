#include<iostream>
using namespace std;
class A{

    virtual void fun(){}

};
class B : public A{

};
int main()
{   
    A *a = new A;

    B *b = dynamic_cast<B*>(a);


    return 0;
}