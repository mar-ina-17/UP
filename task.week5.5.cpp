#include "iostream"

int main(){

    int num=0,i,counter=0;

    do{
        std::cin>>i;

        num=num+i;

        std::cout<<num<<std::endl;

        counter++;

    }while(i!= 0);

    std::cout<<counter;

    return 0;
}
