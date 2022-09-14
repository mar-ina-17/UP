#include <iostream>

const int N = 100;

//functiont to input board dimensions with validations
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

//printing the game board
void  visualiseBoard(char arr[][N], int h, int w)
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

void gameMove(int h, int w, int playerCol, char init, char arr[][N])
{
	for(int i = h-1; i >= 0; i--)
    {
        if(arr[i][playerCol-1] != 'X' && arr[i][playerCol-1] != 'O')
        {
            arr[i][playerCol-1] = init;
            break;
        }
    }
	
     visualiseBoard(arr, h, w);
}

//function to determine if there are horizontal matches
int horizontalMatches(char arr[][N], int width, int height, char init, int &times)
{
	for(int e = height; e >= 0; e--)
	{
		for(int i = 0; i < width ; i++)
		{
			if(arr[e][i] == init)
			{
				times++;
			}
		}	

		if(times < 4)
		{
			times = 0 ;
		} 
	}
		
	return times;
}

//function to determine if there are vertical matches
int verticalMatches(char arr[][N],int height, int playerCol, char init , int &times)
{
	for(int i = 0; i < height; i++)
	{
		if(arr[i][playerCol - 1] == init)
		{
			times++;
		}		
	}

	if(times < 4)
	{
		times = 0 ;
	} 

	return times;
}

//function to determine if there are diagonal matches
int diagonalMatches(char arr[][N], int width, int height, char init, int &times)
{	
		for (int i = height-1; i >=0 ; i--) 
		{
			for (int j = width-1; j >= 0; j--) 
			{
				if (i == j)
				{
					if(arr[i][j] == init)
					{
						times++;	
					}
				}
			}
		}

		if(times<4)
		{
			times = 0;
		}

	return times;
}

//function to determine if there are diagonal matches in the directions from right to left
int reverseDiagonalMatches(char arr[][N], int width, int height, char init, int &times)
{
		for (int i = height-1; i >= 0 ; i--) 
		{
			for (int j = 0; j <width; j++) 
			{
				if (i == j)
				{
					if(arr[i][j] == init)
					{
						times++;	
					}
				}
			}
		}

		if(times<4)
		{
			times = 0;
		}

	return times;
}

//function to determine if there is a winner depending on the count of vertical, hor, diagonal and reverse diagonal values
bool isWinner(int vertical, int horizontal, int diagonal, int reverseDiagonal)
{
	if(vertical == 4)
	{
		return false;
	}

	if(horizontal == 4)
	{
		return false;
	}

	if(diagonal == 4)
	{
		return false;
	}

	if(reverseDiagonal == 4)
	{
		return false;
	}

	else
	{
		 return true;;
	}
	
}

//checking if the array is full by using only the top row and its cells
bool isArrayFull(char arr[][N], int width, int height)
{
	int counter = 0;
        for (int j = 0; j < width; j++) {
 
             if(arr[0][j] == 'X' || arr[0][j] == 'O')
			 {
				counter++;
			 }
        }
   return (counter = width - 1)? false:true;
}

//function to announce the winner
void winnerAnnounce(int counter)
{
	if(counter % 2 == 0)
	{
		std::cout<<"Player 2 wins!"<<std::endl;
	}

	if(counter % 2 != 0)
	{
		std::cout<<"Player 1 wins!"<<std::endl;
	}
}

//functions that each time depending on a counter provides player 1 and 2 with a move and checks if there is a winner at each step;
void playerMovement(int height, int width, char arr[][N], int &counter, int &horForO, int &horForX, int &vertForO, int &vertForX, int &diagonalForO, int &diagonalForX, int &diagonalForORev, int &diagonalForXRev)
{
	bool isThereWinner = true;
	bool isFull = isArrayFull(arr, width, height);

	while(isThereWinner && !isFull)
	{
		int playerColumn = 0;
		
		while(playerColumn <= 0 || playerColumn > width)
		{
			std::cout<<"Please, enter column: ";
			std::cin>> playerColumn;
		}

		counter ++;
		
		if(counter % 2 != 0)
		{
			char init  = 'O';

			gameMove(height, width,  playerColumn, init , arr);
	 		verticalMatches(arr, height,  playerColumn,  init , vertForO);
			horizontalMatches(arr, width, height,  init, horForO);
			diagonalMatches(arr, width, height,  init, diagonalForO);
			reverseDiagonalMatches(arr, width, height, init, diagonalForORev);

			isThereWinner = isWinner(vertForO, horForO, diagonalForO, diagonalForORev);
		}
		
		else
		{
			char init  = 'X';
			
			gameMove(height, width,  playerColumn, init , arr);
			verticalMatches(arr, height, playerColumn, init , vertForX);
			horizontalMatches(arr,  width, height,  init, horForX);
			diagonalMatches(arr, width, height,  init, diagonalForX);
			reverseDiagonalMatches(arr, width, height,init, diagonalForXRev);

			isThereWinner = isWinner(vertForX, horForX, diagonalForX, diagonalForXRev);
		}

		isFull = isArrayFull(arr, width, height);
	}

	if(isFull && isThereWinner)
	{
		std::cout<<"Array is full"<<std::endl;
	}

	else
	{
		winnerAnnounce(counter);
	}
}

int main(){

	int height = 0, width = 0, counter = 0;
	int horForX = 0, vertForX = 0, diagonalForX = 0, diagonalForXRev = 0;
	int horForO = 0, vertForO = 0, diagonalForO = 0, diagonalForORev = 0;
	char arr[N][N] = {};

	inputBoardDimensions(height, width);
	 visualiseBoard(arr, height, width);
	playerMovement(height, width, arr, counter, horForO, horForX, vertForO, vertForX, diagonalForO, diagonalForX, diagonalForORev, diagonalForXRev);
	
	return 0;
}
