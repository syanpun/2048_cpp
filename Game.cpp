#include"Game.h"
#include"Menu.h"
#include"Situation.h"
#include<iostream>
#include<windows.h>

namespace sy {

	Game::Game(){

		highestScore = 0;	//要初始化不然会报错
		gameCount = 0;
		menu = new Menu();
		situation = new Situation();
	}
	Game::~Game() {
		delete menu;
		delete situation;
	}

	void Game::start() {
		bool goon = true;
		while (goon) {
			system("cls");
			int select = menu->show();
			int score = 0;
			switch (select) {
			//开始新游戏
			case 49:
				delete situation;
				situation = new Situation();
				gameCount++;
			//继续上一个游戏
			case 50:
				gameCount++;
				score = situation->start()->getScore();
				break;
			//退出
			case 48:
				system("cls");
				goon = false;
				std::cout << "bye~" << std::endl;
				Sleep(300);
				break;
			default:
				std::cout << "*请按照菜单进行选择" << std::endl;
			}
			if (score > highestScore) {
				highestScore = score;
			}
		}
	}
}//namespace sy