#include <iostream>

void switchNumbers(int *n1, int  *n2)
{
    int num;
    num = *n1;
    *n1 = *n2;
   *n2 = num;
}
int main(){
    int firstvalue, secondvalue;
    std::cin>>firstvalue>>secondvalue;
    switchNumbers(&firstvalue, &secondvalue);
    std::cout<<firstvalue<<" "<<secondvalue;
    return 0;
}