#include "Tests.h"
#include "Board.h"
#include "Print.h"

Tests::Tests()
{
}

void Tests::tryToPutTwoNumbersInOneByte()
{
	Board* board = new Board();
	board->createRandomBoard();
	board->printBoard_XY();
	char bytes[16];
	int num1;
	int num2;
	int num3;
	int num4;
	int value = 0;

	for (int i = 0; i < SIZE; i++)
	{
			num1 = board->getValueInBoard_XY(0, i);
			num2 = board->getValueInBoard_XY(1, i);
			num3 = board->getValueInBoard_XY(2, i);
			num4 = board->getValueInBoard_XY(3, i);


			bytes[i] = (num1 << 4) | (num2 << 0);
			bytes[i + 1] = (num3 << 4) | (num4 << 0);
			
			cout << "num1 : " << endl;
			Board::printByte((num1 << 0));

			cout << "num2 : " << endl;
			Board::printByte((num2 << 4));

			cout << "num1 + num2 : " << endl;      //   ----    one Byte    ----
			Board::printByte(bytes[0]);           //    num1       -        num2

			cout << "num3 : " << endl;
			Board::printByte((num3 << 0));

			cout << "num4 : " << endl;
			Board::printByte((num4 << 4));

			cout << "num3 + num4 : " << endl;      //   ----    one Byte    ----
			Board::printByte(bytes[1]);           //    num1       -        num2


			
		


	}
}

void Tests::tryToConvertByteToNumbers()
{

}

void Tests::tryToConvert()
{
	 /*this->createRandomBoard();
	 this->binaryBoard = this->board_XY_ToBinary();
	 cout << "Binary board" << endl;
	 this->printBinaryBoard();
	 cout << "XY board" << endl;
	 this->printBoard_XY();*/
}

Tests::~Tests()
{
}
