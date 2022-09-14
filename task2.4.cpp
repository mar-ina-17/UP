#include "iostream"
#include "math.h"
using namespace std;
int main(){
    int num,a,b,c;
    cin>>num;
    a=num%10;
    num=num/10;
    b=num%10;
    num=num/10;
    c=num%10;
    cout<<a+b+c;
return 0;
}
