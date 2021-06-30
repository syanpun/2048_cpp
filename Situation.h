#pragma once

#include"Grid.h"
#include"Object.h"

#define MAX_STEP_RECORD 100

namespace sy {


	class Situation{
	private:
		//总计步数
		int steps;
		//记录当前步骤所在位置
		int index;
		//记录的历史步骤
		Grid* grids[MAX_STEP_RECORD];

	public:
		Situation();
		~Situation();
		Situation* start();

		int getScore();
		int getSteps();
		
		//撤回一步
		Grid* back();

		//压入一个步骤
		int push(Grid* grid);
		//弹出一个步骤（撤回）
		Grid* pop();
		//返回当前步骤
		Grid* top();
		//清空历史步骤
		int emptyGrids();

	};
}//namespace sy