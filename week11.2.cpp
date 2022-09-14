#include <iostream>
const int N = 200;

void inputArray(char array[N])
{
    std::cin.getline(array, N);
}
void outputArray(char array[N])
{
    int i = 0, e  = 0;
    while(array[i] != '.')
    {
        while(array[e] != ' ')
        {
            std::cout<<array[e];
            e+2;
        }
        std::cout<<"  ---- "<<std::endl;
        i++;
    }
}
int main()
{
    char array[N];
    inputArray(array);
    outputArray(array);
    return 0;
}