#include "Exception.h"

Exception::Exception(int fees){
    this->fees = fees;
}

void Exception::negativeFees(){
        cout << "Negative Fees not allowed " << endl;

}