#include <iostream>

const int N = 100;

void inputBoardDimensions(int &height,int &width)
{	
	while(height < 4 || height > 20)
	{
		std::cout<<"Please, enter height: ";
		std::cin>> height;
	}

	while(width < 4 || width > 40)
	{
		std::cout<<"Please, enter width: ";
		std::cin>> width;
	}

	std::cout<<height<<" "<<width<<std::endl;
}

void visualizeBoard(char arr[][N], int h, int w)
{
	for(int i = 0; i < h; i++)
	{
		std::cout<<"|";
		for(int a = 0; a < w; a++)
		{
			std::cout<<arr[i][a]<<" |";
		}
		std::cout<<std::endl;
	}
}
void game(int h, int w, int playerCol, char init, char arr[][N])
{
	for(int i = h-1; i >= 0; i--)
    {
        if(arr[i][playerCol-1] != 'X' && arr[i][playerCol-1] != 'O')
        {
            arr[i][playerCol-1] = init;
            break;
        }
    }
	
    visualizeBoard(arr, h, w);
}
/* isArrayFull(int height, int width, char arr[][N])
{
	bool isFull = true;
		if(arr[height - 1][width - 1] != ' ')
		{
			isFull = false;
		}
		else
		{
			isFull = true;
		}
	return isFull;
}*/
bool isWinner(int height, int width, char arr[][N], char init, int playerCol)
{
	int timesPerSym = 0;
	for(int i = height; i >= 0; i--)
	{
		if(arr[i][playerCol-1] == init)
		{
			timesPerSym ++;
		}
		/*for(int e = playerCol; e < width; e++)
		{
			if(arr[i][e] == init)
			{
				timesPerSym ++;
			}
		}*/
	}
	if(timesPerSym != 4)
	{
		return true;
	}
	else{
		return false;
	}
}
void playerMovement(int height, int width, char arr[][N], int &counter)
{
	bool isThereWinner = true;
	//bool isFull = true;

	while(isThereWinner) //|| isFull)
	{
		int playerColumn = 0;
		while(playerColumn <= 0 || playerColumn > width)
		{
			std::cout<<"Please, enter column: ";
			std::cin>> playerColumn;
		}
	counter ++;

		if(counter % 2 == 0)
		{
			char init  = 'X';
			game(height, width,  playerColumn, init , arr);
			isThereWinner = isWinner(height, width, arr, init, playerColumn);
		}

		else
		{
			char init  = 'O';
			game(height, width,  playerColumn, init , arr);
			isThereWinner = isWinner(height, width, arr, init, playerColumn);
		}
		//isFull = isArrayFull(height, width, arr);
	}
	std::cout<<counter<<std::endl;
}
int main(){

	int height = 0, width = 0, counter = 0;
	char arr[N][N] = {};
	inputBoardDimensions(height, width);
	visualizeBoard(arr, height, width);
	playerMovement(height, width, arr, counter);
	return 0;
}