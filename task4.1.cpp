#include <iostream>

using namespace std;
int main(){
    int num;
    cin>>num;
    bool isEven = (num%2==0) ? true : false;
    if(isEven == 1) cout<<"The numer is  chetno";
    else cout<<"The numer is  nechetno";
    return 0;
}