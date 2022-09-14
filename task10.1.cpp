#include <iostream>

const int N = 100;

void printMatrix(int copyArray[N][N])
{
     for(int i = 0; i < 4; i++)
    {
        for(int j = 3; j >= 0 ;j--)
        {
             std::cout<<copyArray[i][j]<<" ";
        }
        std::cout<<std::endl;
    }   
}

void walkThroughArray(int input[N][N], int copyArray[N][N], int size)
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 3; j >= 0 ;j--)
        {
             std::cout<<input[i][j]<<" ";
             copyArray[i][j] = input[i][j];
             std::cout<<copyArray[i][j]<<std::endl;
        }
        std::cout<<std::endl;
    }
}

int main()
{
    int input[N][N] = 
    {
        { 1,  2,  3,  4}, 
        { 5,  6,  7,  8}, 
        { 9, 10, 11, 12}, 
        {13, 14, 15, 16}
    };
    int size = 0;

    do
    {
        std::cout<<"Input size:";
        std::cin>>size;

    }while (size <= 0 || size > 100);
    
    int copyArray[N][N] = {};

    walkThroughArray(input, copyArray, size);
    printMatrix(copyArray);

    return 0;
}