#include <iostream>

void createArray(int size)
{
    int sum = 0, max, min;
    int* arr = new int[size];
    for(int i = 0; i < size; i++)
    {
        std::cin>>arr[i];
        sum+= arr[i];
        if(arr[i] < min || i == 0) min = arr[i];
        if(arr[i] > max || i == 0) max = arr[i];
    }
    std::cout<<sum<<" " <<max<<" - "<<min;
    delete [] arr;
}
int main(){

    int size;
    std::cin>>size;
    createArray(size);
    return 0;
}