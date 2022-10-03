#pragma once
#include <string>
#include "Stack.h"

class Board
{
	int** board_XY;
	char* binaryBoard;
	
public:
	
	Board();

	void win();
	void testWin();
	void createRandomBoard();

	void initialize(Stack<int> randomBoard);

	int** generateAWinningBoard();
	int getHashCode();

	char* board_XY_ToBinary();
	int** binary_To_Board_XY();
	//void  binaryToNumbers(int &num1 ,int &num2 ,const char* byte );


	int getValueInBoard_XY(const int x , const int y) ;



	void printBoard_XY() const;
	void helpToPrintBoard(const int num1) const;
	void printBinaryBoard() const;
	static void printByte(const  char byte) ;
	static  void printArray(int** board);
	~Board();

private:

};

