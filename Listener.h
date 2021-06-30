#pragma once

#include"Object.h"
#include<conio.h>

namespace sy {

	class Listener{
	public:
		//监听键盘的输入 按下按键返回对应按键的数值
		int listen();
		Listener();
		~Listener();
	};
}//namespace sy