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

	char* board_XY_ToBinary();
	int** binary_To_Board_XY();
	//void  binaryToNumbers(int &num1 ,int &num2 ,const char* byte );

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();


	int getValueIn_Board_XY(const int x , const int y) ;
	int** generateAWinningBoard();
	int getHashCode();
	int getEmptyspot();
	int getValueIn_BinaryBoard(const int &place);

	void putNumberInPlace_BinaryBoard(const int &num ,const int &place);

	void printBoard_XY() const;
	void helpToPrintBoard(const int num1) const;
	void printBinaryBoard() const;
	static void printByte(const  char byte) ;
	static  void printArray(int** board);
	~Board();

private:

};

