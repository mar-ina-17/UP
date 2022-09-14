#include <iostream>
#include <thread>         
#include <chrono> 

const int N = 100;

//function to determine if percentage is visible
bool isPercentVisible(char a)
{
	return (a == 'y')? true : false;
}

//checking if the double parameter of the progress is valid
bool isProgressValid(double p)
{
	if(p > 1.0 || p < 0.0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//function to get the user input, in which:
//1.Ask the user if they want to customise the progress bar;
//1.1.IF YES: - they get to chose the current progress of the bar, the width, left and right symbols, full and empty symbols;
//1.2.ELSE: - there are default values for all the parameters;
// in each case the user must input desired delay of progress movement;
void inputData(double &progress, int &barWidth, bool &show, char &endSym, char &startSym, char &fullSym, char &emtSym, int &time)
{
	char answerPercent, userInput;
	bool isProgress = false;

	while(userInput != 'y' && userInput != 'n')
	{
		std::cout<<"Would you like to customise your bar? (y/n): ";
		std::cin>>userInput;
	}

	if(userInput == 'y')
	{
		while(!isProgress )
		{
			std::cout<<"Please, enter progress in the interval [0;1]: ";
			std::cin>>progress;
			isProgress = isProgressValid(progress); 
		}
		
		while(barWidth < 10 || barWidth > 50)
		{
			std::cout<<"Please, enter width: ";
			std::cin>>barWidth;
		}
		
		while(answerPercent != 'y' && answerPercent != 'n')
		{
			std::cout<<"Please, tell me if you wanto to see the % symbol? (y/n): ";
			std::cin>>answerPercent;
		}

		std::cout<<"Please, enter start symbol: ";
		std::cin>>startSym;
		
		std::cout<<"Please, enter end symbol: ";
		std::cin>>endSym;

		std::cout<<"Please, enter symbol for full space: ";
		std::cin>>fullSym;

		std::cout<<"Please, enter symbol for empty space: ";
		std::cin>>emtSym;
	}

	else
	{
		barWidth = 30;
		progress = 0.3;
		answerPercent = 'y';
		startSym = '<';
		endSym = '>';
		fullSym= '=';
		emtSym = ' ';

	}
	
	while(time < 5 ||time > 10)
	{
		std::cout<<"Please, enter delay seconds: ";
		std::cin>>time;
	}
	
	time = time*100;
	
	show = isPercentVisible(answerPercent);
}

//calculating the full space of the progress
int calculateSpace(double progress, int barWidth, int &fullSpace)
{
	return fullSpace = progress * barWidth;
}

//visualising bar function - gives aech char elem a value depending of the progress, width and etc.
void visualiseBar(char bar[N], int width, double progress, char endSym, char begSym, char fullSym, char emptSym, int fullSpace, int T, bool show)
{

	bar[0] = begSym;

	for(int i = 1; i < fullSpace; i++)
	{
		bar[i] = fullSym;
	}

	for(int j = fullSpace; j < width; j++)
	{
		bar[j] = emptSym;			
	}

	bar[width] = endSym;

}

//function to print progress bar, using the function for delay to animate the progress movement;
void printBar(char bar[N], int width, int fullSpace, int T, bool show, double progress)
{
	for(int j = 0; j <= width; j++)
	{	
		if(j<=fullSpace && j > 0)
		{
			std::cout<<bar[j];		
			std::this_thread::sleep_for(std::chrono::milliseconds(T));
		}

		if(show && j == (width/2)-1)
		{
			std::cout<< progress*100;
			std::cout<<'%';
		}

		else
		{
			std::cout<<bar[j];
		}
			
	}
}

int main()
{
	char bar[N];
	char leftEndingSym, rightEndingSym, fullSym, emptySym;
	double progress;
	int barWidth, fullSpace, time = 0;
	bool showPercents;

	inputData(progress, barWidth, showPercents, leftEndingSym, rightEndingSym, fullSym, emptySym, time);
	fullSpace = calculateSpace(progress, barWidth, fullSpace);
	visualiseBar( bar, barWidth, progress, leftEndingSym, rightEndingSym, fullSym, emptySym, fullSpace, time, showPercents);
	printBar(bar, barWidth, fullSpace,time, showPercents, progress);

	return 0;
}