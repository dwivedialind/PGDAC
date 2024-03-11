#include<iostream>

using namespace std;
void wrongSwap(int& a, int& b){
	int t = a; 
	a = b;
	b = t;
}
/*
void correctSwap(const int& a, const int& b){
	int t = a;
	a = b;
	b = t;
}
*/
int main(void){
int x = 10, y = 20;
wrongSwap(x, 20);
return 0;
}
