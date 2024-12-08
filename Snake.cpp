#include "Snake.h"

Snake::Snake(const std::pair<int, int>& gridYX) {
	init_snake_pos_(gridYX);
}

void Snake::init_snake_pos_(const std::pair<int, int>& gridYX) {
	auto snakePos = RandomPositionGenerator::generate_pos(gridYX);
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
        	case 'r': snakeX++; break;
        	case 'l': snakeX--; break;
        	case 'u': snakeY--; break;
        	case 'd': snakeY++; break;
        	default: std::cout << "Unknown direction" << std::endl; break;
    	}
    	snakeY = (snakeY + gridYX.first) % gridYX.first;
    	snakeX = (snakeX + gridYX.second) % gridYX.second;

	snakePos_.front() = snakePos;
}

std::pair<int, int> Snake::get_snake_pos() {
        return snakePos_.front();
}
