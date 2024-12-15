#include "Snake.h"
#include <iterator>
#include <ncurses.h>

Snake::Snake(const std::pair<int, int>& gridYX) {
	init_snake_pos_(gridYX);
}

void Snake::init_snake_pos_(const std::pair<int, int>& gridYX) {
	auto snakePos = RandomPositionGenerator::generate_pos(gridYX);
	snakePos_.reserve(gridYX.first * gridYX.second);
	snakePos_.push_back(snakePos);
}

int Snake::set_snake_direction(char& direction) {
        int ch = getch();
        switch (ch) {
            case KEY_UP:    if (direction != 'd') direction = 'u'; break;
            case KEY_DOWN:  if (direction != 'u') direction = 'd'; break;
            case KEY_LEFT:  if (direction != 'r') direction = 'l'; break;
            case KEY_RIGHT: if (direction != 'l') direction = 'r'; break;
            case 'q':       endwin(); return 0; // 'q' ile çıkış
            default: break;
        }
	return 1;
}

void Snake::set_snake_pos(char direction, std::pair<int, int>& snakePos, const std::pair<int, int>& gridYX) {
	int& snakeY = snakePos.first;
	int& snakeX = snakePos.second;
    	switch (direction) {
        	case 'r': 
			snakeX++; 
			snakeX = (snakeX + gridYX.second) % gridYX.second;
			if (0 == snakeX) snakeX = 1;
			break;

        	case 'l': 
			snakeX--; 
			snakeX = (snakeX + gridYX.second) % gridYX.second;
			if (0 == snakeX) snakeX = gridYX.second - 1;
			break;
        	
		case 'u': 
			snakeY--;
			snakeY = (snakeY + gridYX.first) % gridYX.first;
			if (0 == snakeY) snakeY = gridYX.first - 1;
			break;
        	
		case 'd': 
			snakeY++; 
			snakeY = (snakeY + gridYX.first) % gridYX.first;
			if (0 == snakeY) snakeY = 1;
			break;
        	
		default: 
			std::cout << "Unknown direction" << std::endl; break;
    	}
	
	snakeFarthestTailPos_ = snakePos_.back();
	for (int i = snakePos_.size() - 1; i > 0; --i) {
		snakePos_.at(i) = snakePos_.at(i-1);
	}
	snakePos_.front() = snakePos;
}

std::pair<int, int> Snake::get_snake_pos() {
        return snakePos_.front();
}

const std::vector<std::pair<int, int> >& Snake::get_whole_snake() {
	return snakePos_;
}

void Snake::extend_snake() {
	snakePos_.push_back(snakeFarthestTailPos_);
}

void Snake::print_snake() {
	mvprintw(snakePos_.front().first, snakePos_.front().second, "+");
	for (int i = 1; i < snakePos_.size(); ++i) {
		mvprintw(snakePos_.at(i).first, snakePos_.at(i).second, "x");
	}
}

bool Snake::check_if_snake_hits_itself() {
        auto it = std::find_if(snakePos_.begin()+1, snakePos_.end(),
                           [this](const std::pair<int, int>& p) {
                               return p == snakePos_.front();
                           });

        if (it != snakePos_.end()) {
		return false;
        }

	return true;
}
