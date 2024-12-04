#include "Snake.h"

Snake::Snake() {
	init_snake_pos();
}

void Snake::init_snake_pos() {
	snakePos_ = {7, 22}; // y and x - make this random generated
}

void Snake::set_snake_pos(int y, int x) {
	snakePos_ = {y, x};
}

std::pair<int, int> Snake::get_snake_pos() {
	return snakePos_;
}
