#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <list>

class Snake {
public:
	Snake();
	
	void init_snake_pos(int gridYSize, int gridXSize);
	std::pair<int, int>get_snake_pos(); // returns snake head position
	void set_snake_pos(int y, int x);
private:
	std::list<std::pair<int, int> >snakePos_;
};

#endif
