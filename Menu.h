#pragma once

#include<string>
#include"Listener.h"
#include"Object.h"
#include"Grid.h"

namespace sy {

	class Menu{
	private:
		const static std::string INFO;
		const static std::string START;
		const static std::string EXIT;

	public:
		//显示菜单
		int show();
		Menu();
		~Menu();
	};
}//namespace sy