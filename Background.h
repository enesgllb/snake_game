#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <iostream>

class Background {
public:
	Background(int rowSize, int colSize, char fillChar);

	void print_grid();

private:
	void init_grid_(int rowSize, int colSize, char fillChar);

	std::vector<std::vector<char> > grid_;
};

#endif
