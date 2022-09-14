#include "iostream"
using namespace std;
int main(){
    int a, a1, a2;
    cin>>a;
    a1= a/100;
    a2= a%10;
    if(a1==a2) cout<<"palindrom e";
    else cout<<"ne e";
    return 0;
}