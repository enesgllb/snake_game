#include "RandomPositionGenerator.h"
#include <random>

std::pair<int, int> RandomPositionGenerator::generate_pos(const std::pair<int, int>& gridYX) {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> distY(0, gridYX.first);
        std::uniform_int_distribution<std::mt19937::result_type> distX(0, gridYX.second);
        int randomYPos = distY(rng);
        int randomXPos = distX(rng);

	return {randomYPos, randomXPos};
}
