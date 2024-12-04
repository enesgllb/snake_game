#include "Snake.h"
#include "RandomPositionGenerator.h"

Snake::Snake() {
	snakePos_.push_back({0, 0});
}

void Snake::init_snake_pos(int gridYSize, int gridXSize) {
	auto snakePos = RandomPositionGenerator::generate_pos(gridYSize, gridXSize);
	set_snake_pos(snakePos.first, snakePos.second);
}

void Snake::set_snake_pos(int y, int x) {
	snakePos_.front() = {y, x};
}

std::pair<int, int> Snake::get_snake_pos() {
	return snakePos_.front();
}
