#include "Background.h"

Background::Background(int rowSize, int colSize, char fillChar) {
	init_grid_(rowSize, colSize, fillChar);
}

void Background::init_grid_(int rowSize, int colSize, char fillChar) {
	grid_.resize(colSize);
	for (auto& row : grid_) {
		row.assign(rowSize, fillChar);
	}
}

void Background::print_grid() {
	for (const auto& col : grid_) {
		for (const auto& row : col) {
			std::cout << row;
		}
		std::cout << "\n";
	}
}
