#pragma once

#include"Object.h"
#include<string>

namespace sy {

	enum Direction {
		up = 72,
		down = 80,
		left = 75,
		right = 77
	};

	class Grid{
	private:
		const static int GRID_SIZE = 4;
		const static int INIT_GRID_AMOUNT = 2;

		//记录按下了哪个方向键来到了这种情况
		string direction;
		//记录当前格子里最大的数字
		int maxNum;

		//当前分数
		int score;
		//记录方格上的各个数字
		int board[GRID_SIZE][GRID_SIZE];

		int countLength(int num);

	public:
		Grid();
		//拷贝构造函数
		Grid(const Grid& grid);
		~Grid();

		int getScore();
		string getDirection();

		void show();
		Grid* operate(Direction direction);
	};
}//namespace sy