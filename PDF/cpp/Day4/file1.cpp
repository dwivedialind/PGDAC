#include <iostream>
using namespace std;

int main(void){
try{
	int *arrptr = new int[100000000000000000000000];//this is likely to fail	
	delete[] arrptr;
}catch(const bad_alloc& e){
	//catch the bad_alloc exception and handle it
	cerr << "Memory allocation failed: " << e.what() << endl;
}

return 0;	
}
