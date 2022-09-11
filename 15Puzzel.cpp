// 15Puzzel.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Game.h"
#include "Stack.h"
#include <iostream>

int main()
{
   /* for (int i = 0; i < 100; i++)
    {
        int randomNumber = rand() % 16 + 0 + 1;
        if(randomNumber>16 || randomNumber<1)
        cout << randomNumber << endl;
    }*/
    Game* g1 = new Game();
    g1->print();

    /*Game* g2 = new Game();
    g2->print();

    Game* g3 = new Game();
    g3->print();*/
	
}


