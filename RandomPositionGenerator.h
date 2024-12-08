#ifndef RANDOM_POSITION_GENERATOR_H
#define RANDOM_POSITION_GENERATOR_H

#include <iostream>

class RandomPositionGenerator {
public:
	static std::pair<int, int> generate_pos(const std::pair<int, int>& gridYX);
};


#endif
