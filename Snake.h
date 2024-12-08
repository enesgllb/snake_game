#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <list>
#include "RandomPositionGenerator.h"
#include <ncurses.h>
#include <unistd.h>

class Snake {
public:
	Snake(const std::pair<int, int>& gridYX);
	
	void init_snake_pos_(const std::pair<int, int>& gridYX);
	std::pair<int, int>get_snake_pos();
	int set_snake_direction(char& direction);
	void set_snake_pos(char direction, std::pair<int, int>& snakePos, const std::pair<int, int>& gridYX);
private:
	std::list<std::pair<int, int> >snakePos_;
};

#endif
