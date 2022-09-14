#include "iostream"

using namespace std;
int main(){
    double a,b;
    cin>>a>>b;
    if(a==b)cout<<"kvadrat e"<<endl;
    else cout<<"pravougulnik"<<endl;
    cout<<"S= "<<a*b<<" P= "<<(a+b)*2;
    return 0;
}