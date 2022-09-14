#include <iostream>
#include <math.h>
const int N = 8193;

//function for number input using getline
void inputNumber(char arr[N])
{	
	std::cout<<"Please, input your number: ";
	std::cin.getline(arr, N);
}

//convert character to integer using the ASCII code of each char and substract the ASCII of '0' from it so we can get the int value;
//when we get the integer of the digit, we use pow (10 , positionOfNum), to multiply it and get a number which we add each time to get the final result of the conversion;
int convertToInt(char arr[N],int size, unsigned long long int &number)
{
	int digitInt;
	unsigned long long int numAsInt; 
	int power = size-1;

		for(int i = 0; i< size; i++)
		{
			digitInt = arr[i] - '0';
			numAsInt = digitInt*pow(10, power);
			number += numAsInt;
			power--;
		}

	return number;
}

//function to output in which we call convertToInt
void outputNumber(char arr[N], int &size, unsigned long long int&number)
{
	int i = 0;
	int num;

	std::cout<<"Your number is: ";
		while(arr[i] != '\0')
		{
			std::cout<<arr[i];
			i++;
		}

	size = i;	

	convertToInt(arr,size, number);

	std::cout<<std::endl;
}

//function to check if numbers are equal
void areNumbersEqual(unsigned long long int&number1, unsigned long long int&number2)
{
	if(number1 != number2)
	{
		std::cout<<number1<<" != "<<number2<<std::endl;
	}

	if(number1 == number2)
	{
		std::cout<<number1<<" = "<<number2<<std::endl;
	}
}

//function to compare numbers
void compareNumbers(unsigned long long int&number1, unsigned long long int&number2)
{
	if(number1 > number2)
	{
		std::cout<<number1<<" > "<<number2<<std::endl;
	}
	
	if(number1 < number2)
	{
		std::cout<<number1<<" < "<<number2<<std::endl;
	}
}

unsigned long long int sumNumbers(unsigned long long int&number1, unsigned long long int&number2)
{
	return number1+number2;
}

unsigned long long int substractNumbers(unsigned long long int&number1, unsigned long long int&number2)
{
	return number1-number2;
}

unsigned long long int multiplyNumbers(unsigned long long int&number1, unsigned long long int&number2)
{
	return (unsigned long long)(number1*number2);
}

unsigned long long int divideNumbers(unsigned long long int&number1, unsigned long long int&number2)
{
	return number1/number2;
}

unsigned long long int remainderNumbers(unsigned long long int&number1, unsigned long long int&number2)
{
	return number1%number2;
}

int main()
{
	char num1[N];
	char num2[N];
	int sizeNum1, sizeNum2;
	unsigned long long int number1 = 0, number2 = 0, sum, multi, sub, div, rem;

	inputNumber(num1);
	inputNumber(num2);

	outputNumber(num1, sizeNum1, number1);
	outputNumber(num2, sizeNum2, number2);

	areNumbersEqual(number1, number2);
	compareNumbers(number1, number2);

	sum = sumNumbers(number1, number2);
	sub = substractNumbers(number1, number2);
	multi = multiplyNumbers(number1, number2);
	div = divideNumbers(number1, number2);
	rem = remainderNumbers(number1, number2);

	std::cout<<number1<<" + "<<number2<< " = "<<sum<<std::endl;
	std::cout<<number1<<" - "<<number2<< " = "<<sub<<std::endl;
	std::cout<<number1<<" * "<<number2<< " = "<<multi<<std::endl;
	std::cout<<number1<<" / "<<number2<< " = "<<div<<std::endl;
	std::cout<<number1<<" % "<<number2<< " = "<<rem<<std::endl;

	return 0;
}