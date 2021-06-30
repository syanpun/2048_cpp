#pragma once

#include<iostream>
#include<windows.h>
#include"Situation.h"
#include"Listener.h"

namespace sy {

	Situation::Situation(){
		steps = 0;
		index = -1;
		for (int i = 0; i < MAX_STEP_RECORD; i++) {
			grids[i] = NULL;
		}
	}

	Situation::~Situation() {
		emptyGrids();
	}

	Situation* Situation::start() {
		Listener listener;
		int select = 0;
		Grid* temp;
		system("cls");
		if (getSteps() == 0) {
			std::cout << "开始新游戏" << std::endl;
			emptyGrids();
			push(new Grid());
		}
		else {
			std::cout << "继续上次游戏" << std::endl;
		}
		Sleep(500);
		bool ifGo = true;
		bool isBacked = false; 
		string dirt;
		while (ifGo) {
			top()->show();
			temp = pop();
			if (top() != NULL) {
				std::cout << "上一步执行的操作：" << top()->getDirection() << std::endl;
				std::cout << "上一步的情况：" << std::endl;
				top()->show();
			}
			push(temp);
			std::cout << "按下 [0] 退出" << std::endl;
			std::cout << "按下 [1] 撤销一步" << std::endl;
			std::cout << getSteps() << std::endl;
			select = listener.listen();
			system("cls");
            switch (select) {
                //0
                case 48:
                    ifGo = false;
                    break;
				case 49:
					dirt = top()->getDirection();
					if (back() == NULL) {
						std::cout << "不能再撤回啦~" << std::endl;
					}
					else {
						std::cout << "撤回了一步: "  << dirt << std::endl;
					}
					break;
                //↑
                case 72:
                //↓
                case 80:
                //←
                case 75:
                //→
                case 77:
					Grid* next = top()->operate(Direction(select));
					Grid* last;
					if (top() != next) {
						push(next);
					}
                    break;
            }
		}
		return this;
	}

	int Situation::getSteps() {
		return steps;
	}

	int Situation::getScore() {
		return top()->getScore();
	}

	Grid* Situation::back() {
		Grid* temp = pop();
		if (top() == NULL) {
			push(temp);
			return NULL;
		}
		delete temp;
		return top();
	}

	int Situation::push(Grid* grid) {
		steps++;
		index++;
		index %= MAX_STEP_RECORD;
		if (grids[index] != NULL) {
			delete grids[index];
		}
		grids[index] = grid;
		return index;
	}

	Grid* Situation::pop() {
		if (steps == 0) {
			return NULL;
		}
		steps--;
		Grid* grid = grids[index];
		grids[index] = NULL;
		index--;
		if (index == -1) {
			index = MAX_STEP_RECORD - 1;
		}
		return grid;
	}

	Grid* Situation::top() {
		if (steps == 0) {
			return NULL;
		}
		return grids[index];
	}

	int Situation::emptyGrids() {
		int count = 0;
		Grid* grid = pop();
		while (grid != NULL) {
			delete grid;
			grid = pop();
			count++;
		}
		return count;
	}
}//namespace sy