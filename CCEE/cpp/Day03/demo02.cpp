#include <iostream>

using namespace std;

class Point{
public:
        int c, d;
  public:
    Point(int a , int b){
        c =a;
        d = b;
    }
    Point(int a): Point(a,a){

    }
};

int main(){
    Point *p;
    p = new Point(1);
    cout<<p->c<<" "<<p->d<<endl;
}