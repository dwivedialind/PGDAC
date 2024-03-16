#include<iostream>
#include<vector>

using namespace std;
int main()
{
     vector<int> list ;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    
    auto first = list.begin()+1;
    auto last = list.begin()+2;

    list.erase(first,last);
    for(auto it = list.begin(); it != list.end(); it++){
        cout << *it << " ";
    }
    cout << list.front() << endl;


    return 0;
}