#include "iostream"

int main(){

    int num=0,i;

    do
    {

        std::cin>>i;

        if(i%2==0)
        {
            num++;
        }

    } while(i > 0);

    std::cout<<num<<std::endl;

    return 0;
}
