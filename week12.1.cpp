#include "iostream" 
const int size = 100;

void inputNumbers(int N[size], int &num)
{
    std::cin>>num;
    for(int i = 0; i < num; i++)
    {
        std::cin>>N[i];
    }

}
void outputNums(int N[size], int num)
{
         
    if(num >= 0)
    {
        std::cout<<N[num]<<" ";
        num = num - 1;
        outputNums(N,num);
    }
    
}
int main()
{
    int num;
    int N[size];
    inputNumbers(N,num);
    outputNums(N,num-1);
    return 0;
}