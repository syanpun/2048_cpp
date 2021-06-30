// 2048.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include<Windows.h>
#include"Game.h"
#include"Object.h"

using namespace sy;
using std::string;

int main()
{
    std::cout << "Hello World!\n";
    Sleep(500);
    Game* game = new Game();
    game->start();
    delete game;
    return 0;
}

