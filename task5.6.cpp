#include "iostream"
using namespace std;
int main(){
    int a;
    cin>>a;
    int a1= a%10;
    int a2= (a/10)%10;
    int a3= (a/100)%10;
    if(a1>a2&& a1>a3 && a2>a3) cout<<a1<<a2<<a3;
    if(a2>a1 && a2>a3 && a1>a3) cout<<a2<<a1<<a3;
    if(a3>a1 && a3>a2 && a2>a1) cout<<a3<<a2<<a1;
    /*i oshte nqkolko if-a koito me murzi da pisha*/
    return 0;
}