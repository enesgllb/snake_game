#ifndef DOT_H
#define DOT_H

#include <iostream>

class Dot {
public:
	Dot(const std::pair<int, int>& gridYX, const std::pair<int, int>& snakePos);
	
	void set_dot_pos(const std::pair<int, int>& dotPos);
	std::pair<int, int> get_dot_pos();
private:
	void init_dot_pos_(const std::pair<int, int>& gridYX, const std::pair<int, int>& snakePos);
	
	std::pair<int, int> dotPos_;
};

#endif
