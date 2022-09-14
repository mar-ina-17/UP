#include "iostream"

using namespace std;
int main(){
    int a;
    cin>>a;
    
    double a1=(a/100)%10;
    double a2=(a/10)%10;
    double a3=a%10;
    cout<<a1<<" "<<a2<<" "<<a3<<endl;
    cout<<a1+a2+a3;
    return 0;
}