#include "iostream"

int main(){

    int k,num,i,counter=0;

    std::cin>>k;

    do
    {

        std::cin>>i;
        num+=i;
        counter++;

    }while(num<k);

    std::cout<<counter<<std::endl;

    return 0;
}
