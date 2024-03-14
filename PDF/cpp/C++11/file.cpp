#include<iostream>
#include<memory>

using namespace std;
int getValue(){
 return 22;
}

class MyClass{
	private:
  constexpr int a;
  public:
  constexpr MyClass(int x): a(x) {

   }

   int getValue(){
    return a;
   }
};

int main(){

	std::unique_ptr<MyClass> ptr{new MyClass(2)};
	cout << ptr->getValue() << endl;
	
return 0;
}
int main1(){
const int a = getValue();
constexpr int b = 32;
cout << b << endl;
cout << a << endl;
return 0;
}
