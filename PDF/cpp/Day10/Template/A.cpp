
#include "A.h"

template<class P, class Q>
A<P,Q>::A(){}

template<class P, class Q>
void A<P,Q>::swap(P a, Q y){
    P temp = a;
	a = y;
	y = temp;
	cout << "SWAP" << endl;
}