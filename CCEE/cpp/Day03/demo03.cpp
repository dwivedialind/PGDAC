#include<iostream>
using namespace std;

class Point{
    int x;
    int y;
    const int num;
    public:
        Point(int value): y(value++), x(++value), num(++value){
           // x=4 y=4 num=6 
        }
    void display(){
        cout << "x: "<<x<<" y: "<<y<<" num: "<<num<<endl;
    }
};

int main(){
    Point *p = new Point(3);
    p->display();
}