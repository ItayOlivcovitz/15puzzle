#pragma once

#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

using std::string;
using std::to_string;
using std::cout;
using std::endl;


class Game
{
	int** board ;
	

	int**  generateAWinningBoard();
	
	void initialize(Stack<int>);
	void createRandomBoard();
	int win();
	

public:
	void testWin();
	Game ();
	
	void print() const;
};