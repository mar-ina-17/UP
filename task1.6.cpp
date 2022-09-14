#include "iostream"
#include "math.h"
using namespace std;
int main(){
    double a,b,c,D,x1,x2;
    cout<<"a:, b:,c:"<<endl;
    cin>>a;
    cin>>b;
    cin>>c;
    D= b*b-(4*a*c);
    cout<<"D= "<<D<<endl;
    if(D>0) {
        x1=(-b+sqrt(D))/2*a;
        x2=(-b-sqrt(D))/2*a;
        cout<<"rounded x1= "<<round(x1)<<"rounded x2= "<<round(x2)<<endl;
    }
    else cout<<"Nqma realni koreni"<<endl;

return 0;
}
