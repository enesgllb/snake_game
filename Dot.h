#ifndef DOT_H
#define DOT_H

#include <iostream>

class Dot {
public:
	void init_dot_pos(int y, int x);
	void set_dot_pos(int y, int x);
	std::pair<int, int> get_dot_pos();
private:
	std::pair<int, int> dotPos_;
};

#endif
