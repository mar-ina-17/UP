#include <iostream>

const int N = 1000;
void inputArray(char array[N])
{
   std::cin.getline(array, N);
}
void outputArrayAndCopy(char array[N], char arrayOfChars[N])
{
    int i = 0;
    while(array[i] != '\0')
    {
        if(array[i] == ' ')
        {
            int j = i+1, e = 0;
            while (array[j] != '\0')
            {
                arrayOfChars[e] = array[j];
                e++;
                j++;
            }
            
        }
        i++;
    }
}

void checkForRep(char array[N], char arrayOfChars[N])
{
    int c = 0;
    for(int i = 0; i == '\0'; i++)
    {
        c++;
    }
    int j = c, e = 0, max = 1, counter = 0;
    char a;
    while(array[j] != '\0')
    {
        while(arrayOfChars[e] != '\0')
        {
            counter = 0;
            if(array[j] == arrayOfChars[e])
            {
                counter++;
                a = arrayOfChars[e];
            }
        }
        if(counter > max)
        {
            max = counter;
        }
    }
    std::cout<<counter<<std::endl;
}
int main()
{
    char array[N], arrayOfChars[N];
    inputArray(array);
    outputArrayAndCopy(array, arrayOfChars);
    checkForRep(array, arrayOfChars);
    return 0;
}