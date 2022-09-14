#include "iostream"
const int N=6;

void inputArray(int array[N][N]){
    for(int i = 0; i < N; i++)
    {  
        for(int j = 0; j < N; j++)
        {
            std::cin>>array[i][j];
        }
    }
}

int printArray(int array[N][N])
{
    int sum = 0;
        for(int i = 0; i < N; i++)
        {  
            sum = 0;

            for(int j = 0; j < N; j++)
            {
                if(i % 2 == 0)
                {
                    sum += array[j][i];
                }
            }
        }
        return sum;
}

int main(){
   int array[N][N] = {
	{11, 12, 13, 14, 15, 16}, 
	{21, 22, 23, 24, 25, 26}, 
	{31, 32, 33, 34, 35, 36}, 
	{41, 42, 43, 44, 45, 46}, 
	{51, 52, 53, 54, 55, 56}, 
	{61, 62, 63, 64, 65, 66}
};
   // inputArray(array);
    int sum = printArray(array);
    std::cout<<sum<<std::endl;
    return 0;
}