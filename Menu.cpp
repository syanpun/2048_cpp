#include"Menu.h"
#include"Listener.h"
#include <iostream>
#include <string>

namespace sy {

	const std::string Menu::INFO = "---------2048---------";
	const std::string Menu::START = "---------1.开始游戏---------";
	const std::string Menu::EXIT = "---------0.退出游戏---------";

	int Menu::show() {
		Listener listener;
		std::cout << INFO << std::endl;
		std::cout << START << std::endl;
		std::cout << EXIT << std::endl;
		return listener.listen();
	}

	Menu::Menu(){

	}

	Menu::~Menu() {

	}

}//namespace sy