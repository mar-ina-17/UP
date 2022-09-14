#include "iostream"

using namespace std;
int main(){
int n,form;
cin>>n;
for(int i=1; i<n; i++){
    form=((i+1)*(i+1))+(i*i);
    if(n==form){
        cout<<i++<<" "<<i<<endl;
    }
}
return 0;
}
