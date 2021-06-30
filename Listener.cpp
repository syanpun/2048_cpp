#include<conio.h>
#include <iostream>
#include"Listener.h"

namespace sy {

	Listener::Listener() {

	}

	Listener::~Listener() {

	}

	int Listener::listen() {
		while (!_kbhit());
		int ch = _getch();
		//当 getch() 返回 0 或 0xE0 时，就表示用户按了功能键，这时候需要再调用一次 getch()
		if (ch == 0 || ch == 0xE0) {
			return _getch();
		}
		return ch;
	}
}//namespace sy

