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
    int sum = 0, average = 0, multiply = 1;
    int minE = array[0], maxE = array[0];
    for(int i = 0; i < n; i++)
    {
        if (array[i] < minE)
        {
            minE = array[i];
        }
        if (array[i] > maxE)
        {
            maxE = array[i];
        }
        sum += array[i];
        multiply *= array[i];
    }

    average = sum / n;
    std::cout<<minE<<" "<<maxE<<" "<<sum<<" "<<multiply<<" "<<average<<std::endl;
}

int main()
{
    int n, array[N];
    std::cin>>n;

     input(array, n);
     output(array, n);
    return 0;
}