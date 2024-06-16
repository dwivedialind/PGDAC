#include <iostream>

using namespace std;

int main(){
    string s = "This string has some non-ASCII characters: ¡Hola!";
    cout << sizeof(s) << endl;
    return 0;
}