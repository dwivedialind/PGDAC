#include<iostream>
using namespace std;

class Base{
	public:
	  static int a;
};
int Base::a = 1000;

class Derived : public Base{
	
};

int main(void){
 Base b;
 cout << Base::a << endl;
 cout << Derived::a << endl;
	
 return 0;
}

