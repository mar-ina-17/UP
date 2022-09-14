#include "iostream"
#include "cmath"
using namespace std;
int main(){
    int a,m;
    int n=0;
    int a1=(a/1000);
    int a2=(a/100)%10;
    int a3=(a/10)%10;
    int a4=a%10;
    if(a>2211 && a<8999 ){
        cout<<"Error"<<endl;
        cin>>m;
        if(a1==m) n++;
        if(a2==m) n++;
        if(a3==m) n++;
        if(a4==m) n++;
        else cout<<"ne se sudurja";
        cout<<"sudurja se " <<n<<" puti"<<endl;
    }
    return 0;
}
