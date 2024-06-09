#include <iostream>
inline void mySwap(int a, int b){
    int t = a;
    a = b;
    b = t;
}
using namespace std;

int main(){
    int a = 4;
    int b = 5;
    mySwap(a,b);
    cout << a << " " << b;

    return 0;
}