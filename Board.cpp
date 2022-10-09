#include "Board.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include"Node.h"
#include "List.h"
#define SIZE  4 

Board::Board()
{
	/*this->board_XY = new int* [SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		this->board_XY[i] = new int[SIZE];
	}*/

	this->binaryBoard = new char[8]();
}

void Board::win()

{
	int count1 = 1;
	int fromDownToUp = 0;
	int fromUpToDown = 0;
	int count2 = SIZE;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (this->board_XY[i][j] != count1)//|| this->board[i][j] != count2)
			{
				fromUpToDown++;
			}
			count1++;

		}


	}


	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (this->board_XY[i][j] != count2)
			{
				fromUpToDown++;
			}
			count2--;
		}


	}
	if (fromUpToDown == 16 || fromDownToUp == 16)
	{
		cout << "win" << endl;
	}
}

void Board::testWin()

{
	
	this->board_XY = generateAWinningBoard();
	this->printBoard_XY();
	win();

}

// * @brief create Random Board
void Board::createRandomBoard()

{

	Stack<int> s;
	List<int>* start = new List <int>();
	start->next = new Node<int>();
	Node<int>* temp = start->next;
	int max = SIZE * SIZE;
	//initialize List

	for (int i = 0; i < SIZE * SIZE; i++)
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->value = i;
		temp->next = new Node<int>();
	}
	temp->next = NULL;

	//put random number in the stack
	for (int i = 0; i < SIZE * SIZE; i++)
	{
		srand(time(NULL));
		int randomNumber = rand() % max + 1;
		randomNumber = start->remove(randomNumber);
		s.push(randomNumber);
		if (max > 1)
		{
			max--;
		}

	}
	;
	initialize(s);
	
}

// * @brief initialize board_XY with random numbers using stack
// *
// * @return Stack<int>
// */
void Board::initialize(Stack<int> randomBoard)
{
	int num1, num2, num3, num4;

	/*for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			this->board_XY[i][j] = randomBoard.pop();
		}

	}*/
	for (int i = 0; i < 8; i = i+2 ) //8 = array char*
	{
		num1 = randomBoard.pop();
		num2 = randomBoard.pop();
		num3 = randomBoard.pop();
		num4 = randomBoard.pop();
		
		this->binaryBoard[i] = (num1 << 4) | (num2 << 0);
		this->binaryBoard[i + 1] = (num3 << 4) | (num4 << 0);

		/*cout << "byte " << i + 1 << " : " << num1<<endl;
		cout << "byte " << i + 1 << " : " << num2<<endl;

		cout << "num1: ";
		printByte((num1 << 4));
		cout << "num2: ";
		printByte((num2 << 0));

		cout << "num1+num2: ";
		printByte(binaryBoard[i]);

		cout << "" << endl;

		cout << "byte " << i + 2 << " : " << num3 << endl;
		cout << "byte " << i + 2 << " : " << num4 << endl;

		cout << "num3: ";
		printByte((num3 << 4));
		cout << "num4: ";
		printByte((num4 << 0));

		cout << "num3+num4: ";
		printByte(binaryBoard[i+1]);
		cout << "" << endl;*/
	}


}

// * @brief generate a winning board_XY
// *
// * @return int** --  board_XY
// */
int** Board::generateAWinningBoard()
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
	this->board_XY = winBoard;
	return winBoard;
}


int Board::getHashCode()
{
    return 0;
}

// * @brief return empty spot
int Board::getEmptyspot()
{
	bool found = true;
	int byteCounter = 1;
	int num1 = 0, num2 = 0;
	while (found)
	{
		num1 = (binaryBoard[byteCounter - 1] & 0xF0) >> 4;// -1 because array start at 0
		num2 = binaryBoard[byteCounter-1] & 0x0F;

		if (num1 == 15 || num2 == 15)
		{
			found = false;
		}
		else
		{
			byteCounter++;
		}
		
	}
	if (num1 == 15)
	{
		return (byteCounter-1) * 2 + 1;
	}
	else
	{
		return (byteCounter - 1) * 2 + 2;
	}
}

int Board::getValueIn_BinaryBoard(const int& place)
{
	int temp;
	int num1;
	int placeBytes;
	
	if (place % 2 == 0)
	{
		placeBytes = place / 2;
		temp = this->binaryBoard[placeBytes - 1]; // -1 because attay start at 0 
		num1 = temp & 0x0F ;
	}
	
	else
	{
		placeBytes = place / 2 + 1;
		temp = this->binaryBoard[placeBytes - 1];// -1 because attay start at 0 
		num1 = (temp & 0xF0) >> 4;
	}
	return num1;
}

void Board::putNumberInPlace_BinaryBoard(const int& num,const int &place)
{
	int temp;
	int num1; 
	int num2;
	int num1OrNum2 = place;
	int placeBytes; // board_XY index to index to byte 
	
	while (num1OrNum2 > 5)
	{
		num1OrNum2 = num1OrNum2 - 4;
	}
	
	if (num1OrNum2 % 2 == 0)
	{
		placeBytes = place / 2;
		temp = this->binaryBoard[placeBytes -1 ]; // array start at 0
		num1 = (temp & 0xF0) >> 4;
		num2 = num & 0x0F;

		/*cout << "num1 :" << endl;
		printByte(num1);

		cout << "num2 :" << endl;
		printByte(num2);*/
		temp = (num1 << 4) | (num2 << 0);
		this->binaryBoard[placeBytes -1] = temp;
	}
	else
	{
		placeBytes = place / 2 + 1;
		temp = this->binaryBoard[placeBytes-1];
		num1 = (num & 0x0F);  
		num2 = temp & 0x0F;
		
		/*cout << "num1 :" << endl;
		printByte(num1);

		cout << "num2 :" << endl;
		printByte(num2);*/

		temp = (num1 << 4) | (num2 << 0);
		this->binaryBoard[placeBytes -1] = temp;
	}
	
}

// * @brief convert Board_XY to binaryBoard
// *
// * @return char* --  binaryBoard
// */
char* Board::board_XY_ToBinary()
{
	
	
	char* bytes =new char[8]();
	int coloum = 0;
	int num1;
	int num2;
	int num3;
	int num4;

	for (int i = 0; i < 8; i= i+2) // 8 = size of the char* array
	{
		num1 = this->getValueIn_Board_XY(0, coloum);
		num2 = this->getValueIn_Board_XY(1, coloum);
		num3 = this->getValueIn_Board_XY(2, coloum);
		num4 = this->getValueIn_Board_XY(3, coloum);
		coloum++;

		bytes[i] = (num1 << 4) | (num2 << 0);
		bytes[i + 1] = (num3 << 4) | (num4 << 0);

		//cout << "num1 : " << endl;
		//Board::printByte((num1 << 0));

		//cout << "num2 : " << endl;
		//Board::printByte((num2 << 4));

		//cout << "num1 + num2 : " << endl;      //   ----    one Byte    ----
		//Board::printByte(bytes[i]);           //    num1       -        num2

		//cout << "num3 : " << endl;
		//Board::printByte((num3 << 0));

		//cout << "num4 : " << endl;
		//Board::printByte((num4 << 4));

		//cout << "num3 + num4 : " << endl;      //   ----    one Byte    ----
		//Board::printByte(bytes[i+1]);           //    num1       -        num2	
	}
	return bytes;
}

// * @brief convert binaryBoard to Board_Xy
// *
// * @return int** --  Board_Xy
// *
int** Board::binary_To_Board_XY()
{
	int num1_num2;
	int num3_num4;
	int** newBoard_XY = new int* [SIZE];

	// create Board_XY
	for (int i = 0; i < SIZE; i++)
	{
		newBoard_XY[i] = new int[SIZE];
	}

	for (int i = 0; i < SIZE-1; i++)
	{
		num1_num2 = this->binaryBoard[i];
		num3_num4 = this->binaryBoard[i+1];
	}
	return newBoard_XY;
}

void Board::moveUp()
{
	int place_X, place_Y;
	int num1 = this->getEmptyspot(); // num1 = empty spot
	int num2;                       //  num2 = the value in place that i need to replace to num1
	
	if (num1 > 3)
	{
		place_X = num1 % 4 ; // board start at (0,0)
		place_Y = (num1 / 4) - 1 ;
		num2 = getValueIn_BinaryBoard(place_X  +  4* place_Y );
		putNumberInPlace_BinaryBoard(15 , place_X + 4 * place_Y);
		putNumberInPlace_BinaryBoard(num2, place_X + 4 * (place_Y + 1));
	}
}

void Board::moveDown()
{
	int place_X, place_Y;
	int num1 = this->getEmptyspot(); // num1 = empty spot
	int num2;                       //  num2 = the value in place that i need to replace to num1

	if (num1 < 13)
	{
		place_X = num1 % 4; // board start at (0,0)
		place_Y = (num1 / 4) + 1;
		num2 = getValueIn_BinaryBoard(place_X + 4 * place_Y);
		putNumberInPlace_BinaryBoard(15, place_X + 4 * place_Y);
		putNumberInPlace_BinaryBoard(num2, place_X + 4 * (place_Y - 1));
	}
}

void Board::moveLeft()
{
	int place_X, place_Y;
	int num1 = this->getEmptyspot(); // num1 = empty spot
	int num2;                       //  num2 = the value in place that i need to replace to num1

	if (num1 != 1 && num1 != 5 && num1 != 9 && num1 != 13)
	{
		place_X = ( num1 % 4 ) - 1; // board start at (0,0)
		place_Y = (num1 / 4);
		num2 = getValueIn_BinaryBoard(place_X + 4 * place_Y);
		putNumberInPlace_BinaryBoard(15, place_X + 4 * place_Y);
		putNumberInPlace_BinaryBoard(num2, (place_X + 1) + 4 * place_Y);
	}
}

void Board::moveRight()
{
	int place_X, place_Y;
	int num1 = this->getEmptyspot(); // num1 = empty spot
	int num2;                       //  num2 = the value in place that i need to replace to num1

	if (num1 != 4 && num1 != 8 && num1 != 12 && num1 != 16)
	{
		place_X = (num1 % 4) + 1; // board start at (0,0)
		place_Y = (num1 / 4);
		num2 = getValueIn_BinaryBoard(place_X + 4 * place_Y);
		putNumberInPlace_BinaryBoard(15, place_X + 4 * place_Y);
		putNumberInPlace_BinaryBoard(num2, (place_X - 1) + 4 * place_Y);
	}
}

//void Board::binaryToNumbers(int& num1, int& num2, const char* byte)
//{
//	
//		int num = ;
//		int dec_value = 0;
//
//		// Initializing base value to 1, i.e 2^0
//		int base = 1;
//
//		int temp = num;
//		while (temp) {
//			int last_digit = temp % 10;
//			temp = temp / 10;
//
//			dec_value += last_digit * base;
//
//			base = base * 2;
//		}
//}
int Board::getValueIn_Board_XY(const int x, const int y)
{
    return this->board_XY[y][x];
}

// * @brief print the Board
// @return it prints number +1 -- 0<num<16
void Board::printBoard_XY() const
{
	cout << "" << endl;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			helpToPrintBoard(this->board_XY[i][j]);
		}
		cout << "" << endl;
	}
}

// *@brief print number with spaces 
// @return it prints number +1 -- 0<num<16
void Board::helpToPrintBoard(const int num) const
{
	cout << "  ";
	if (num == 15)
	{
		cout << "e ";
	}
	else
		cout << num; //+1;

	if (num < 10)
	{
		cout << "  ";
	}
	else
	{
		cout << " ";
	}
}

void Board::printBinaryBoard() const
{
	cout << "" << endl;
	 int num1,num2, num3,num4;
	for (int i = 0; i < 8; i = i+2) // 8 = size of the char* array
	{
		cout << "" << endl;

		num1 = (binaryBoard[i] & 0xF0) >> 4;
		num2 = binaryBoard[i] & 0x0F;
		num3 = (binaryBoard[i+1] & 0xF0) >> 4;
		num4 = binaryBoard[i+1] & 0x0F;
	
		helpToPrintBoard(num1);
		helpToPrintBoard(num2);
		helpToPrintBoard(num3);
		helpToPrintBoard(num4);	
		cout << "byte "<< i + 1 << ":  "<< num1 << "   " << num2 << "  ";
		cout << "byte "<< i + 2 << ":  "<< num3 << "   " << num4 << "  ";
	}
	cout << "" << endl;
}

void Board::printByte(const char byte)  
{
	for (int i = 7; i >= 0; i--)
	{
		int b = byte >> i;
		if (b & 1)
		{
			cout << "1";
		}
		else
		{
			cout << "0";
		}
	}
	cout << "" << endl;
}

void Board::printArray(int** board)
{
}

Board::~Board()
{
}
