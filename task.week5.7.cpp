#include "iostream"

int main(){

    int m,n;

    std::cin>>m>>n;

    for(int i=m;i<n;i++){

        if(i%3==0)
        {
            std::cout<<i<<std::endl;
        }

    }
    return 0;
}
