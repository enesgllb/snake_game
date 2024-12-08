#include "Dot.h"
#include "RandomPositionGenerator.h"

Dot::Dot(const std::pair<int, int>& gridYX, const std::pair<int, int>& snakePos) {
	init_dot_pos_(gridYX, snakePos);
}

void Dot::init_dot_pos_(const std::pair<int, int>& gridYX, const std::pair<int, int>& snakePos) {
	auto dotPos = RandomPositionGenerator::generate_pos(gridYX);
        while (dotPos == snakePos) {
                init_dot_pos_(gridYX, snakePos);
                dotPos = get_dot_pos();
        }
	set_dot_pos(dotPos);
}

void Dot::set_dot_pos(const std::pair<int, int>& dotPos) {
	dotPos_ = dotPos;
}

std::pair<int, int> Dot::get_dot_pos() {
	return dotPos_;
}
