#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "Snake.h"

class Background {
public:
	Background(int ySize, int xSize, char fillChar);

	void print_grid();
	void add_snake_to_grid();
	void change_snake_pos(int y, int x);
	std::pair<int, int> get_snake_pos();
	void clear_screen();

private:
	void init_grid_(int ySize, int xSize, char fillChar);

	std::vector<std::vector<char> > grid_;
	Snake snake_;
};

#endif
