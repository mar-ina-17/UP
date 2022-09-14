#include "iostream"

bool isPlindrome(int n)
{
    if((n/100 == n%10) || ((n/1000 == n%10) && (n/100 == n%100)))
    {
        return true;
    }
    else
    {
        return false;
    } 
}
int printN(int k, int l)
{
    int i;
    for(i=k; i <= l; i++)
    {
       if(isPlindrome(i))
       {
           std::cout<<i<<" ";
       }
    }
    return i;
}
int main()
{
    int k,l;
    std::cin>>k>>l;
    printN(k,l);
    return 0;
}