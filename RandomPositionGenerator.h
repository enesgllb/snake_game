#ifndef RANDOM_POSITION_GENERATOR_H
#define RANDOM_POSITION_GENERATOR_H

#include <iostream>

class RandomPositionGenerator {
public:
	static std::pair<int, int> generate_pos(int gridYSize, int gridXSize);
};


#endif
