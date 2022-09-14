#include "iostream"

const int N = 100;

void input(int array[], int n)
{
    std::cout<<"Input array:";
        for(int i = 0; i < n; i++)
        {
            std::cin>>array[i];
        }
}

void outputAndSwap(int array[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = n - 1; j < n; j--)
        {
            array[j] = array[i];
            std::cout<<array[j];
        }
    }
}

int main()
{
    int n, array[N];
    std::cin>>n;

    input(array, n);
    outputAndSwap(array, n);
    return 0;
}