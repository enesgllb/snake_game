#include "Dot.h"
#include "RandomPositionGenerator.h"

void Dot::init_dot_pos(int y, int x) {
	auto dotPos = RandomPositionGenerator::generate_pos(y, x);
	set_dot_pos(dotPos.first, dotPos.second);
}

void Dot::set_dot_pos(int y, int x) {
	dotPos_ = {y, x};
}

std::pair<int, int> Dot::get_dot_pos() {
	return dotPos_;
}
