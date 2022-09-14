#include <iostream>

using namespace std;
int main(){
    int num;
    cin>>num;
    if ((num/1000)%10 == num%10 && (num/100)%10 == (num/10)%10) cout<<"ima simetriq";
    else cout<<"nqma simetriq";
    return 0;
}