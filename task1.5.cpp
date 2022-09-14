#include "iostream"

using namespace std;
int main(){
    int number[3]={};
    for(int i=0; i<4; i++){
        cin>>number[i];
    }
    if(number[0]==number[3] && number[1]==number[2]){cout<<"Simetriq"<<endl;}
    else cout<<"NE Simetriq"<<endl;

return 0;
}
