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

void output(int array[], int n)
{
    for(int i = 0; i < n; i++)
    {
        std::cout<<array[i];
    }
}

void movePositions(int array[],int n, int position)
{
    for(int i = 0; i < n; i++)
    {
       &array[position] = array[i];
    }
}

int main()
{
    int n, array[N], position;
    std::cin>>n;
    std::cin>>position;

     input(array, n);
     movePositions(array, n, position);
     output(array, n);
    return 0;
}