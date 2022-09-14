#include "iostream"

int main()
{
    int sec_previous = 0, fir_previous = 1;
    int current;

    std::cout<<sec_previous<<" "<<fir_previous<<std::endl;

    for(int n = 1; n <= 11; n++)
    {
        current = sec_previous + fir_previous;

        std::cout << current << std::endl;

        sec_previous = fir_previous;
        fir_previous = current;
    }
}
//1 1 2 3 5 8 13 21 34
