#include "iostream"
#include "cmath"
#define PI 3.14159265

using namespace std;
int main()
{
    double a,b,c;
    cin>>a>>b>>c;
    cout<<a-b+ pow(b,2)*pow(a,3)-pow(c,3)<<endl;
    cout<<sqrt(b) - sqrt(pow(a,3))*sqrt(c)<<endl;
    cout<<abs(pow(c,3)-pow(a,3)*pow(b,2))+ pow(a,2)<<endl;
    cout<<cos(PI/6)*c + sin(PI/4)*log10(a)<<endl;
    cout<<sqrt(pow(a,3))*pow(c,3)+ cos(PI/4)*pow(a,3)<<endl;

    return 0;
}

