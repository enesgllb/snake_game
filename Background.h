#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "Snake.h"
#include "Dot.h"

class Background {
public:
	Background(int ySize, int xSize, char fillChar);

	void print_grid();
	void add_snake_to_grid(int gridYSize, int gridXSize);
	void change_snake_pos(int y, int x);
	std::pair<int, int> get_snake_pos();
	void clear_screen();
	void add_dot_to_grid(int gridYSize, int gridXSize);

private:
	void init_grid_(int ySize, int xSize, char fillChar);

	std::vector<std::vector<char> > grid_;
	Snake snake_;
	Dot dot_;
};

#endif
