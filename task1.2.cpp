#include "iostream"

using namespace std;
int main(){
    double first,second, empt;
    cin>>first;
    cin>>second;
    empt=first;
    first=second;
    second=empt;
    cout<<"F: "<<first<<" S: "<<second;
return 0;
}
