#include "iostream"


using namespace std;

int main(){
    double x,y;
    cout<<"(x,y)= ";
    cin>>x;
    cin>>y;
    if(x<0 && y<0) cout<<"3-ti kv";
    if(x<0 && y>0) cout<<"4-ti kv";
    if(x>0 && y>0) cout<<"1-vi kv";
    if(x>0 && y<0) cout<<"2-ri kv";
    if(x==0 || y==0) cout<<"Leji na nqkoq os";
    else {cout<<"0,0";}
return 0;
}
