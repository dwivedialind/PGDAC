#include<iostream>
using namespace std;

int main(void){

int *a = new int;
cout << *a << endl;

delete a;
a = NULL;
	
return 0;	
}
