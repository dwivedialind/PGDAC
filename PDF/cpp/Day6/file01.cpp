#include<iostream>
using namespace std;

class A{
	public:
	virtual void fun(){
	  cout << "A" << endl;
	 }

};

class B: public A{
	public:
	// void fun(){
	 // cout << "B" << endl;
	// }

};

class C : public B{
	public:
	// void fun(){
	 // cout << "C" << endl;
	// }
};


int main(void)
{
	B *ptr = new C;
	ptr->fun();
	return 0;
}
