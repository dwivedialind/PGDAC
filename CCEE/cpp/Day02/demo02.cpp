#include<iostream>

using namespace std;

int num = 10;

int main(){
    int num = 5;

    cout << "Local " << num <<endl;
    cout << "Global " << ::num <<endl;

    return 0;
}