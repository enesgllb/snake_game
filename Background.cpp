#include "Background.h"

Background::Background(int ySize, int xSize, char fillChar) {
	init_grid_(ySize, xSize, fillChar);
}

void Background::init_grid_(int ySize, int xSize, char fillChar) {
	grid_.resize(ySize);
	for (auto& x : grid_) {
		x.assign(xSize, fillChar);
	}
}

void Background::print_grid() {
	for (const auto& y : grid_) {
		for (const auto& x : y) {
			std::cout << x;
		}
		std::cout << "\n";
	}
}

void Background::add_snake_to_grid() {
	std::pair<int, int> snakePos = snake_.get_snake_pos();
	grid_.at(snakePos.first).at(snakePos.second) = 'x';
}

void Background::change_snake_pos(int y, int x) {
	auto snakePos = snake_.get_snake_pos();
	grid_.at(snakePos.first).at(snakePos.second) = ' ';
	snake_.set_snake_pos(y, x);
	grid_.at(y).at(x) = 'x';
}

std::pair<int, int> Background::get_snake_pos() {
	return snake_.get_snake_pos();
}

void Background::clear_screen() {
    system("clear");
}
