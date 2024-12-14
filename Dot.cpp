#include "Dot.h"
#include "RandomPositionGenerator.h"
#include <ncurses.h>

Dot::Dot(const std::pair<int, int>& gridYX, const std::pair<int, int>& snakePos) {
	maxDotPositionSearchRetryNo_ = gridYX.first * gridYX.second;
	init_dot_pos_(gridYX, snakePos);
}

void Dot::init_dot_pos_(const std::pair<int, int>& gridYX, const std::pair<int, int>& snakePos) {
	auto dotPos = RandomPositionGenerator::generate_pos(gridYX);
        while (dotPos == snakePos) {
                init_dot_pos_(gridYX, snakePos);
                dotPos = get_dot_pos();
        }
	dotPos_ = dotPos;
}

void Dot::set_dot_pos(std::pair<int, int> gridYX, const std::vector<std::pair<int, int> >& snake) {
	gridYX.first -= 1;
	gridYX.second -= 1;
	auto dotPos = RandomPositionGenerator::generate_pos(gridYX);

	auto it = std::find_if(snake.begin(), snake.end(), 
                           [&dotPos](const std::pair<int, int>& p) {
                               return p == dotPos;
                           });

    	if (it != snake.end()) {
		maxDotPositionSearchRetryNo_--;
    		if (0 == maxDotPositionSearchRetryNo_) {
			std::cout << "YOU FINISHED THE GAME !!!";
			return;
		}
		set_dot_pos(gridYX, snake);
	} else {
		maxDotPositionSearchRetryNo_ = gridYX.first * gridYX.second;
		dotPos_ = dotPos;
    	}
}

std::pair<int, int> Dot::get_dot_pos() {
	return dotPos_;
}

void Dot::print_dot() {
	mvprintw(dotPos_.first, dotPos_.second, "o");
}
