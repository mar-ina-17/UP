#include "iostream"

using namespace std;
int main(){
   int fac_num;
   bool isEven;
   cin>>fac_num;
   if(fac_num%2==0) isEven= true;
   else isEven= false;
    cout<<"Is my fn even? : "<<boolalpha<<isEven;
return 0;
}
