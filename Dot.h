#ifndef DOT_H
#define DOT_H

#include <iostream>

class Dot {
public:
	Dot(const std::pair<int, int>& gridYX, const std::pair<int, int>& snakePos);
	
	void set_dot_pos(std::pair<int, int> gridYX, const std::vector<std::pair<int, int> >& snake);
	std::pair<int, int> get_dot_pos();
	void print_dot();
private:
	void init_dot_pos_(const std::pair<int, int>& gridYX, const std::pair<int, int>& snakePos);
	
	std::pair<int, int> dotPos_;
	int maxDotPositionSearchRetryNo_;
};

#endif
