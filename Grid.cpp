#include <iostream>
#include<ctime>
#include<windows.h>
#include"Grid.h"
#include"Situation.h"

namespace sy {

	Grid::Grid(){
        direction = "";
        maxNum = 0;
		score = 0;
		srand((unsigned int)time(NULL));
		for (int i = 0; i < GRID_SIZE; i++) {
			for (int j = 0; j < GRID_SIZE; j++) {
				board[i][j] = 0;
			}
		}
		int val = rand() % 2;
		int p = 0;
		for (int i = 0; i < INIT_GRID_AMOUNT; i++) {
			int posi = rand() % 16;
			if (p == posi) {
				posi++;
				posi %= 16;
			}
			p = posi;
			int x = posi % 4;
			int y = posi / 4;
			board[x][y] = (i == 0 ? 2 : (val == 1 ? 2 : 4));
		}
	}

	Grid::Grid(const Grid& grid){
        direction = "";
        maxNum = grid.maxNum;
		score = grid.score;
		for (int i = 0; i < GRID_SIZE; i++) {
			for (int j = 0; j < GRID_SIZE; j++) {
				board[i][j] = grid.board[i][j];
			}
		}
	}

	Grid::~Grid() {

	}

    string Grid::getDirection() {
        return direction;
    }

	int Grid::getScore() {
		return score;
	}

	Grid* Grid::operate(Direction direction) {
		Grid* grid = new Grid(*this);
        bool hasChanged = false;
        switch (direction) {
            case sy::up:
                grid->direction = "↑";
                for (int i = 0; i < GRID_SIZE; i++) {
                    for (int j = 1; j < GRID_SIZE; j++) {
                        for(int k = 0; k < GRID_SIZE - j; k++){
                            if(grid->board[k][i] == 0 && grid->board[k + 1][i] != 0){
                                hasChanged = true;
                                grid->board[k][i] = grid->board[k+1][i];
                                grid->board[k+1][i] = 0;
                            }
                        }
                    }
                }
                for (int i = 0; i < GRID_SIZE; i++) {
                    for (int j = 1; j < GRID_SIZE; j++) {
                        if (grid->board[j - 1][i] == grid->board[j][i] && grid->board[j - 1][i] != 0) {
                            hasChanged = true;
                            grid->board[j - 1][i] *= 2;
                            grid->board[j][i] = 0;
                            if (grid->board[j - 1][i] > maxNum) {
                                grid->maxNum = grid->board[j - 1][i];
                            }
                        }
                    }
                }
                if (hasChanged) {
                    for (int i = 0; i < GRID_SIZE; i++) {
                        for (int j = 1; j < GRID_SIZE; j++) {
                            for (int k = 0; k < GRID_SIZE - j; k++) {
                                if (grid->board[k][i] == 0 && grid->board[k + 1][i] != 0) {
                                    grid->board[k][i] = grid->board[k + 1][i];
                                    grid->board[k + 1][i] = 0;
                                }
                            }
                        }
                    }
                }
                break;
            case sy::down:
                grid->direction = "↓";
                for (int i = 0; i < GRID_SIZE; i++) {
                    for (int j = 1; j < GRID_SIZE; j++) {
                        for (int k = 0; k < GRID_SIZE - j; k++) {
                            if (grid->board[GRID_SIZE-1-k][i] == 0 && grid->board[GRID_SIZE - 1-k - 1][i] != 0) {
                                hasChanged = true;
                                grid->board[GRID_SIZE - 1-k][i] = grid->board[GRID_SIZE - 1-k - 1][i];
                                grid->board[GRID_SIZE - 1-k - 1][i] = 0;
                            }
                        }
                    }
                }
                for (int i = 0; i < GRID_SIZE; i++) {
                    for (int j = 1; j < GRID_SIZE; j++) {
                        if (grid->board[GRID_SIZE - 1 - j + 1][i] == grid->board[GRID_SIZE - 1 - j][i] && grid->board[GRID_SIZE - 1 - j + 1][i] != 0) {
                            hasChanged = true;
                            grid->board[GRID_SIZE - 1 - j + 1][i] *= 2;
                            grid->board[GRID_SIZE - 1 - j][i] = 0;
                            if (grid->board[GRID_SIZE - 1 - j + 1][i] > maxNum) {
                                grid->maxNum = grid->board[GRID_SIZE - 1 - j + 1][i];
                            }
                        }
                    }
                }
                if (hasChanged) {
                    if (hasChanged) {
                        for (int i = 0; i < GRID_SIZE; i++) {
                            for (int j = 1; j < GRID_SIZE; j++) {
                                for (int k = 0; k < GRID_SIZE - j; k++) {
                                    if (grid->board[GRID_SIZE - 1 - k][i] == 0 && grid->board[GRID_SIZE - 1 - k - 1][i] != 0) {
                                        grid->board[GRID_SIZE - 1 - k][i] = grid->board[GRID_SIZE - 1 - k - 1][i];
                                        grid->board[GRID_SIZE - 1 - k - 1][i] = 0;
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            case sy::left:
                grid->direction = "←";
                for (int i = 0; i < GRID_SIZE; i++) {
                    for (int j = 1; j < GRID_SIZE; j++) {
                        for (int k = 0; k < GRID_SIZE - j; k++) {
                            if (grid->board[i][k] == 0 && grid->board[i][k+1] != 0) {
                                hasChanged = true;
                                grid->board[i][k] = grid->board[i][k + 1];
                                grid->board[i][k + 1] = 0;
                            }
                        }
                    }
                }
                for (int i = 0; i < GRID_SIZE; i++) {
                    for (int j = 1; j < GRID_SIZE; j++) {
                        if (grid->board[i][j - 1] == grid->board[i][j] && grid->board[i][j - 1] != 0) {
                            hasChanged = true;
                            grid->board[i][j - 1] *= 2;
                            grid->board[i][j] = 0;
                            if (grid->board[i][j - 1] > maxNum) {
                                grid->maxNum = grid->board[i][j - 1];
                            }
                        }
                    }
                }
                if (hasChanged) {
                    for (int i = 0; i < GRID_SIZE; i++) {
                        for (int j = 1; j < GRID_SIZE; j++) {
                            for (int k = 0; k < GRID_SIZE - j; k++) {
                                if (grid->board[i][k] == 0 && grid->board[i][k + 1] != 0) {
                                    grid->board[i][k] = grid->board[i][k + 1];
                                    grid->board[i][k + 1] = 0;
                                }
                            }
                        }
                    }
                }
                break;
            case sy::right:
                grid->direction = "→";
                for (int i = 0; i < GRID_SIZE; i++) {
                    for (int j = 1; j < GRID_SIZE; j++) {
                        for (int k = 0; k < GRID_SIZE - j; k++) {
                            if (grid->board[i][GRID_SIZE - 1 - k] == 0 && grid->board[i][GRID_SIZE - 1 - k - 1] != 0) {
                                hasChanged = true;
                                grid->board[i][GRID_SIZE - 1 - k] = grid->board[i][GRID_SIZE - 1 - k - 1];
                                grid->board[i][GRID_SIZE - 1 - k - 1] = 0;
                            }
                        }
                    }
                }
                for (int i = 0; i < GRID_SIZE; i++) {
                    for (int j = 1; j < GRID_SIZE; j++) {
                        if (grid->board[i][GRID_SIZE - 1 - j + 1] == grid->board[i][GRID_SIZE - 1 - j] && grid->board[i][GRID_SIZE - 1 - j + 1] != 0) {
                            hasChanged = true;
                            grid->board[i][GRID_SIZE - 1 - j + 1] *= 2;
                            grid->board[i][GRID_SIZE - 1 - j] = 0;
                            if (grid->board[i][GRID_SIZE - 1 - j + 1] > maxNum) {
                                grid->maxNum = grid->board[i][GRID_SIZE - 1 - j + 1];
                            }
                        }
                    }
                }
                if (hasChanged) {
                    if (hasChanged) {
                        for (int i = 0; i < GRID_SIZE; i++) {
                            for (int j = 1; j < GRID_SIZE; j++) {
                                for (int k = 0; k < GRID_SIZE - j; k++) {
                                    if (grid->board[i][GRID_SIZE - 1 - k] == 0 && grid->board[i][GRID_SIZE - 1 - k - 1] != 0) {
                                        grid->board[i][GRID_SIZE - 1 - k] = grid->board[i][GRID_SIZE - 1 - k - 1];
                                        grid->board[i][GRID_SIZE - 1 - k - 1] = 0;
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            //default:      //Error	C2361	initialization of 'hasChanged' is skipped by 'default' label
                //break;
        }
        if (hasChanged) {
            srand((unsigned int)time(NULL));
            int val = rand() % 3;
            int posi = rand() % 16;
            int x = posi % 4;
            int y = posi / 4;
            while (grid->board[x][y] != 0) {
                posi++;
                posi %= 16;
                x = posi % 4;
                y = posi / 4;
            }
            grid->board[x][y] = ((val == 1) ? 2 : 4);
        }
        else {
            std::cout << "无效操作" << std::endl;
            delete grid;
            grid = this;
        }
        return grid;
	}

	void Grid::show() {
        int width = countLength(maxNum);
		for (int i = 0; i < GRID_SIZE; i++) {
			if (i == 0) {
				std::cout << " ┌ ";
				for (int j = 0; j < GRID_SIZE - 1; j++) {
                    for (int k = 0; k < width; k++) {
                        std::wcout << " ";
                    }
					std::cout << "  ┬  ";
				}
                for (int k = 0; k < width; k++) {
                    std::wcout << " ";
                }
				std::cout << " ┐" << std::endl;
			}
			else if (i <= GRID_SIZE - 1) {
				std::cout << " ├ ";
				for (int j = 0; j < GRID_SIZE - 1; j++) {
                    for (int k = 0; k < width; k++) {
                        std::wcout << " ";
                    }
					std::cout << "  ┼  ";
				}
                for (int k = 0; k < width; k++) {
                    std::wcout << " ";
                }
				std::cout << " ┥" << std::endl;
			}
			std::cout << "    ";
			for (int j = 0; j < GRID_SIZE; j++) {
                if (board[i][j] == 0) {
                    for (int k = 0; k < width; k++) {
                        std::wcout << " ";
                    }
                }
                else {
                    int spaceWidth = width - countLength(board[i][j]);
                    for (int k = 0; k < spaceWidth / 2; k++) {
                        std::wcout << " ";
                    }
                    std::cout << board[i][j];
                    for (int k = 0; k < spaceWidth - spaceWidth / 2; k++) {
                        std::wcout << " ";
                    }
                }
                std::wcout << "     ";
			}
			std::cout << std::endl;
			if (i == GRID_SIZE - 1) {
				std::cout << " └ ";
				for (int j = 0; j < GRID_SIZE - 1; j++) {
                    for (int k = 0; k < width; k++) {
                        std::wcout << " ";
                    }
					std::cout << "  ┴  ";
				}
                for (int k = 0; k < width; k++) {
                    std::wcout << " ";
                }
				std::cout << " ┘" << std::endl;
			}
		}
		
	}

    int Grid::countLength(int num) {
        int length = 1;
        while ((num /= 10) > 0) length++;
        return length;
    }

}//namespace sy