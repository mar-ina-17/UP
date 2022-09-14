#include "iostream"


void printN(int n)
{
    for(int i = 1; i <= n; i++)
    {
        std::cout<<i<<" ";
    }
}
int main()
{
    int n;

    std::cin>>n;

    printN(n);

    return 0;
}