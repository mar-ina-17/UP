#include "iostream"

int main(){

    int sum=0,number;

    do{

        std::cin>>number;

        sum=sum+number;

        std::cout<<sum<<std::endl;

    }while(number != 0);

    return 0;
}
