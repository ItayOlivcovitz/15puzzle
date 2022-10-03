#include "Game.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include"Node.h"
#include "List.h"
#define SIZE  4 

using std::string;
using std::to_string;
using std::cout;
using std::endl;
using namespace std; 


Game::Game()
{
	this->board = new Board();
}

void Game::startgame()
{
	board->createRandomBoard();
	
	board->printBinaryBoard();
}


