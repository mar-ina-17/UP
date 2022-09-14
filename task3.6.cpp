#include "iostream"

using namespace std;
int main(){
   int num;
   cin>>num;
   if(num>0 && (num%7==0 || num%9==0)) cout<<"true";
   else cout<<"false";
return 0;
}
