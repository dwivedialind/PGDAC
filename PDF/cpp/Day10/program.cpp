#include<iostream>
using namespace std;

int noOfCakes(int A, int P){
    int PA = 3*A;
    int totalPieces{PA+P};
    int noOfCakes = totalPieces/2;
    return noOfCakes;
}
int main()
{
    cout << "No of Choclate Bars: " ;
    int A;
    cin >> A;
    cout << "No of Choclate Pieces: ";
    int P;
    cin >> P;
    cout<< noOfCakes(A,P) << endl;
    return 0;
}