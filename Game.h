#pragma once

#include"Menu.h"
#include"Object.h"
#include"Situation.h"

namespace sy {

	class Game{
	private:
		//游戏菜单
		Menu* menu;
		//游戏
		Situation* situation = NULL;
		//最高分
		int highestScore;
		//游戏次数
		int gameCount;

	public:
		Game();
		~Game();
		//开始游戏
		void start();

	};
}//namespace sy