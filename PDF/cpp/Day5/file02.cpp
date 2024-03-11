#include <iostream>
using namespace std;
class Base{
 public:
	Base(){
	 cout << "I am Base Parameterless" << endl;
	}
	Base(int a){
	 cout << "I am Base parameterized" << a <<  endl; 	
	}

};

class Derived : public Base{
	public:
	Derived(): Base(1){
	 cout << "I am Derived parameterless" << endl;
	}
};
int main(void){

Derived d;
return 0;
}
