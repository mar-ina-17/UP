#include "iostream"
#include "cmath"
using namespace std;
int main(){
   int f_num, s_num;
   cin>>f_num>>s_num;
   bool is=  (s_num < f_num ) ? true:false;
    int if_first= (is == 1) ? pow(f_num,3) : pow(s_num,3);
   cout<<if_first;
return 0;
}
