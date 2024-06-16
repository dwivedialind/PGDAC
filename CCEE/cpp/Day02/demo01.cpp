#include<iostream>
#include <string>
using namespace std;
namespace na{
    int num = 5;
}

namespace na{
    int num1 = 10;
    int num2 = 30;
}

int main(){
    using namespace na;
   cout << num1 << endl;
   cout << num2 << endl;
   return 0;
}