#include <iostream>
const size_t FIXED_COLUMNS_SIZE = 2;

//This function is used to get the user's size input for the array of numbers
size_t inputSize()
{
    size_t size = 0;

    while (size < 1)
    {
        std::cin>> size;
    }

    return size;
}

//deletes array
void deleteArray(int** array, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        delete[] array[i];
    }
    delete[] array;
}

//Creates a new array from the given size otherwhise prints failure
int* createArray(size_t size)
{
    int* array = new (std::nothrow) int[size];

    if(!array)
    {
        std::cout << "ERROR! Memory allocation failed."<<std::endl;
        exit(0);
    }

    return array;
}

//Function to initialize the values in the array
void inputArray(size_t size, int* array)
{
    for(size_t i = 0; i < size; i++)
    {
        std::cin>>array[i];
    }
}

//This function prints out the array
void printArray(int**array, size_t size)
{
    for(int i = 0; i < size; i++)
    {
        std::cout<<array[i][0]<<" ";
    }
    std::cout<<std::endl;
}

//This function creates an array with three columns and
//number of rows equal to the size of the array
int** create3DArray(size_t size)
{
    int** array = new (std::nothrow) int*[size];
    if(!array)
    {
        std::cout << "ERROR! Memory allocation failed"<<std::endl;
        exit(1);
    }

    for(size_t i = 0; i < size; i++)
    {
        array[i] = new (std::nothrow) int[FIXED_COLUMNS_SIZE];
        if(!array[i])
        {
            std::cout << "ERROR! Memory allocation failed"<<std::endl;
            exit(1);
        }
    }

    return array;
}

//This function represents each number in the array as a binary number,
//then counts the bits equal to 1 on even and odd positions
int** countSetBitsInNumber(size_t size, int* array)
{
    int** newArray = create3DArray(size);

    for(size_t j = 0; j < size; j++)
    {
        size_t onEvenPosition = 0, onOddPosition = 0, shiftPos = 0;

        newArray[j][0] = array[j]; //writes the decimal value to the array in row 'j' and column 0 

        while(array[j])
        {
            if(shiftPos % 2 != 0 && array[j] % 2 == 1)
            {
                onOddPosition+=1;
            }
            if(shiftPos % 2 == 0 && array[j] % 2 == 1) 
            {
                onEvenPosition+=1;
            }

            array[j] >>= 1;
            shiftPos++;
        }

        newArray[j][1] = onEvenPosition; //writes the number of encountered bits at even positions in column [1]
        newArray[j][2] = onOddPosition; //writes the number of encountered bits at odd positions in column [2]
    }

    return newArray;
}

//This function swaps the positions of two elements in the array
void swap(int** array, size_t i, size_t j)
{
    int tmp1, tmp2, tmp3;

    tmp1 = array[i][0];
    tmp2 = array[i][1];
    tmp3 = array[i][2];

    array[i][0] = array[j][0];
    array[i][1] = array[j][1];
    array[i][2] = array[j][2];

    array[j][0] = tmp1;
    array[j][1] = tmp2;
    array[j][2] = tmp3;
}

//This function removes the repeated elements
//in regard to the equality of set bits on even and odd positions
void popRepeatedValues(int** array, size_t newSize, size_t size)
{
    int** newArray = create3DArray(newSize - 1); // creates new array for the unique elements
    
    bool found = false; //used to indicate if an element was found and should be added to the array, in order to increase the positions in the new array
    
    for(size_t i = 0, k = 0; i < size; i++)
    {
        for(size_t j=i+1; j < size; j++)
        {
            //in order for an element to be added to the array, we need to check if 
            //it fits within the standard of uniqueness, a.k.a
            //the numbers should be different from each other
            if(array[i][1] != array[j][1])
            {
                if(array[i][2] != array[j][2])
                {
                    newArray[k][0] = array[i][0];
                    newArray[k][1] = array[i][1];
                    newArray[k][2] = array[i][2];
                    found = true;
                }
            }
            else found = false;
        }
        if(found && k < newSize) k++;
    }

    printArray(newArray, newSize);// printing the new array containing only unique elements
    deleteArray(newArray, newSize);
    deleteArray(array, size);
}

//This function sorts the elements of the array by the specified criteria 
//and counts the number of equal elements in order to determine the size of the new array 
void sortArray(int** array, size_t size)
{
    size_t popCounter = 0;

    for(size_t i = 0; i < size; i++)
    {
       for(size_t j = i+1; j < size; j++)
       {
           if(array[i][1] == array[j][1])
           {
                if(array[i][2] < array[j][2] ) swap(array, j, i);
                if(array[i][2] == array[j][2]) popCounter++;
           }

           if(array[i][1] < array[j][1]) swap(array,j, i);
       }
    }

    printArray(array, size); // printing the sorted array
    
    popRepeatedValues(array, size-popCounter, size); //calling the unique array function with the new array size
}


int main()
{
    size_t size = inputSize();
    int* numbers = createArray(size);

    inputArray(size, numbers);

    int** numbersBitsArray = countSetBitsInNumber(size, numbers);
    sortArray(numbersBitsArray, size);

    delete[] numbers;
    deleteArray(numbersBitsArray, size);

    return 0;

}