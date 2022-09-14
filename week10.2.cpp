#include <iostream>

void printArray(int arr[], int s)
{
    for(int i = 0; i < s; i++)
    {
        std::cout<<arr[i]<<" ";
    }
}
int * createArray(int size)
{
    int* arr = new int[size];
    for(int i = 0; i < size; i++)
    {
        std::cin>>arr[i];
    }
    return arr;
}
int main(){

    int s;
    std::cin>>s;
    int* ar = createArray(s); 
    printArray(ar, s);
    return 0;
}