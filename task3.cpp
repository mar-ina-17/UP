#include <iostream>
const int FIXED_SIZE = 2;

size_t inputSize()
{
    size_t size = 0;

    while (size <= 0)
    {
        std::cin>>size;
    }

    return size;
}

int** createArray(size_t size)
{
    int** array = new (std::nothrow) int*[size];
    for(size_t i = 0; i < size; i++)
    {
        array[i] = new (std::nothrow) int[FIXED_SIZE];
    }

    if(!array)
    {
        std::cout<<"!ERROR! Memory allocation failed!"<<std::endl;
        exit(1); 
    } 

    return array;
} 

int input(int num)
{
    while(num < 0)
    {
        std::cin >>num;
    }
    return num;
}

void inputArray(int**arr, size_t size)
{
    int value = -1;
    for(size_t i = 0; i < size; i++)
    {
        for(size_t j = 0; j < FIXED_SIZE; j++)
        {
            arr[i][j] = input(value);
        }
    }
}

void print(int**arr, size_t size)
{
    for(size_t i = 0; i < size; i++)
    {
        for(size_t j = 0; j < FIXED_SIZE; j++)
        {
            std::cout<<arr[i][j];
            if(j == 0) std::cout<<"-";
        }
        std::cout<<" ";
    }
}

void dominoe(int**arr, size_t size)
{
    for(size_t i = 0; i < size; i++)
    {
        if(arr[i][0] == arr[i++][0] && (i++) < size) std::cout<<arr[i][1]<<"-"<<arr[i][0]<<" "<<arr[i++][0]<<"-"<<arr[i++][1]<<" ";

    }
}

int main()
{
    size_t size = inputSize();
    int** arr = createArray(size);
    inputArray(arr, size);
    print(arr, size);
    std::cout<<std::endl;
    dominoe(arr, size);

    return 0;
}