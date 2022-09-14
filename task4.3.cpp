#include <iostream>

using namespace std;
int main(){
    int num;
    cin>>num;
    if(num/100 == (num/10)%10 || (num/10)%10==num%10) cout<<"ima";
    else cout<<"nema";
    return 0;
}