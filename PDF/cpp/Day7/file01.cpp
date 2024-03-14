#include<iostream>
using namespace std;
class A{

    public:
        virtual void fun(){}

};
class B: public A{

};
class C: public A{

};
int main()
{
    A *ptr = new C;
    B* bptr = dynamic_cast<B *>(ptr);
    if(bptr == NULL)
        cout << "Wrong" << endl;

    A* p = new B;
    try{
        B& b = dynamic_cast<B&>(*p);
    }catch(const bad_cast &e){
        cout << "caugh " << e.what() << endl;
    }
    return 0;
}