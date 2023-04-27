// TextualRPG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "GameZero.h"
#include "TestResults.h"
#include "CharacterTypesTester.h"
#include "PlayerActions.h"

int main()
{
    std::cout << "Hello TextualRPG!\n";


    GameZero* theGame = new GameZero();
   
    theGame->startGame();

   
   // TestResults* r;
   // r = CharacterTypesTester::runAllTests();
   //std::cout << r->toString() << std::endl;

}

