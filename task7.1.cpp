#include "iostream"

void minEl(int el, int &minNum){
    if(el < 0 && minNum < el)
    {
        minNum = el;
    }    
}

int main()
{
    int n, num, minNum = 0;
    std::cin>>n;
    for(int i=0; i < n; i++)
    {
        std::cin>>num;
        minEl(num, minNum);
    }
    std::cout<<minNum<<std::endl;
    return 0;
}