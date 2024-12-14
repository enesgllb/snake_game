#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <vector>
#include "RandomPositionGenerator.h"
#include <ncurses.h>
#include <unistd.h>

class Snake {
public:
	Snake(const std::pair<int, int>& gridYX);
	
	void init_snake_pos_(const std::pair<int, int>& gridYX);
	std::pair<int, int>get_snake_pos();
	const std::vector<std::pair<int, int> >& get_whole_snake();
	int set_snake_direction(char& direction);
	void set_snake_pos(char direction, std::pair<int, int>& snakePos, const std::pair<int, int>& gridYX);
	void extend_snake();
	void print_snake();
private:
	std::vector<std::pair<int, int> >snakePos_;
	std::pair<int, int> snakeFarthestTailPos_;
};

#endif
