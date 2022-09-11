#include "Game.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE  4 

using std::string;
using std::to_string;
using std::cout;
using std::endl;

/**
 * @brief create Random Board
 *
 * @return Stack<int>
 */
Stack<int> Game::createRandomBoard()
{

	Stack<int> s;
	
	

	int min = 1;
	int max = SIZE * SIZE;
	int numbers[SIZE * SIZE + 1]{ 0 };
	//push random numbers to the stack
	for (int i = 0; i < SIZE * SIZE; i++)
	{
		
		srand(time(NULL));
		int randomNumber = rand() % max + min ;

		
		while (numbers[randomNumber-1] == 1)
		{
			srand(time(NULL));
	        randomNumber = rand() % max + min ;
		}
		if (randomNumber == max)
		{
			max--;
		}
		if (randomNumber == min)
		{
			min++;
		}
		numbers[randomNumber] = 1;
		s.push(randomNumber);
	}
	return s;
}



/**
 * @brief constractor 
 */
Game::Game()
{
	Stack<int> randomBoard;
	board = new int* [SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		board[i] = new int[SIZE];
	}
	randomBoard = createRandomBoard();
	initialize(randomBoard);
	

}

/**
 * @brief Chacking if the user as won
 *
 * @return int: 0 - lose , 1 - won
 */
int Game::win()
{
	int count1 = 1;
	int count2 = SIZE-1;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (this->board[i][j] != count1 || this->board[i][j] != count2)
			{
				return 0;
			}
			count1++;
			count2--;
		}
		return 1;

	}
	return 0;
}
void Game::testWin()
{
	int** winBoard = generateAWinningBoard();
	this->board = generateAWinningBoard();
	if ( win() )
	{
		cout << "win" << endl;
	}

}
int** Game::generateAWinningBoard()
{
	int count = 1;
	int** winBoard = new int* [SIZE]; 
	for (int i = 0; i < SIZE; i++)
	{
		winBoard[i] = new int[SIZE];
	}
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			winBoard[i][j] = count;
			count++;
		}
	}
	return winBoard;
}

/**
 * @brief Using Stack to built the board
 */
void Game::initialize(Stack<int> randomBoard)
{
	
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			this->board[i][j] = randomBoard.pop();
		}

	}
}

/**
 * @brief Print the board
 */
void Game::print() const
{
	cout << ""<<endl;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << "  ";
			if (this->board[i][j] == 16)
			{
				cout << "e";
			}
			else
				cout << this->board[i][j];

			if (this->board[i][j] <10)
			{
				cout << "  ";
			}
			else
			{
				cout << " ";
			}

			
		}
		cout << "" << endl;
	}
}


