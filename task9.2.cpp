#include "iostream"

const int N = 10;

void inputArray(int array[N][N], int &n){
    std::cin>>n;
    for(int i = 0; i < n; i++)
    {  
        for(int j = 0; j < n; j++)
        {
            std::cin>>array[i][j];
        }
    }
}

void printArray(int array[N][N], int &n)
{
    int sum1 = 0, sum2= 0;
    bool isMagic;
        for(int i = 0; i < n - 1 ; i++)
        {  
            for(int j = 0; j < n; j++)
            {
               sum1 += array[i][j];
               sum2 += array[i+1][j];

               if(sum1 == sum2)
               {
                   isMagic = true;
               }
               else
               {
                  isMagic = false;
               }
            }
        }

        if(isMagic)
        {
            std::cout<<"Magic :)"<<std::endl;
        }
        else
        {
            std::cout<<"Normal"<<std::endl;
        }
}
int main(){

    int array[N][N], n;
    inputArray(array, n);
    printArray(array, n);
    return 0;
}