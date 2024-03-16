#ifndef A_H
#define A_H
#endif

#include<iostream>
using namespace std;
template<class P, class Q>
class A{
 private:
  P x;
  Q y;
 public:
  A();
  
  void swap(P a, Q y);
 	

};


template<class P, class Q>
A<P,Q>::A(){}

template<class P, class Q>
void A<P,Q>::swap(P a, Q y){
    P temp = a;
	a = y;
	y = temp;
	cout << "SWAP" << endl;
}



