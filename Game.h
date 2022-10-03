#pragma once

#include <string>
#include "Stack.h"
#include "Board.h"

#define SIZE  4 

class Game
{
	Board* board ;

public:
	Game();
	void startgame();
	
};