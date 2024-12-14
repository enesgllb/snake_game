#include <iostream>
#include <ncurses.h>
#include <unistd.h> // sleep() için
#include "Snake.h"
#include "Dot.h"

void print_borders(std::pair<int, int> gridYX) {
	for (int i = 0; i < gridYX.first + 1; ++i) {
                mvprintw(i, 0, "|");
                //mvprintw(i, 0, std::to_string(i).c_str());
        }

	for (int i = 0; i < gridYX.first + 1; ++i) {
                mvprintw(i, gridYX.second + 1, "|");
        }

	for (int i = 0; i < gridYX.second + 2; ++i) {
                mvprintw(0, i, "-");
        }

        for (int i = 0; i < gridYX.second + 2; ++i) {
                mvprintw(gridYX.first, i, "-");
        }
}

int main() {
    initscr();              // ncurses başlat
    cbreak();               // Girdi tamponunu devre dışı bırak
    noecho();               // Klavye girdisini ekrana yazdırma
    keypad(stdscr, TRUE);   // Özel tuşları etkinleştir (örn: ok tuşları)
    curs_set(0);            // İmleci gizle
    nodelay(stdscr, TRUE);  // getch() bekleme yapmaz
    
    std::pair<int, int> gridYX{15, 35};
    
    Snake snake(gridYX);
    Dot dot(gridYX, snake.get_snake_pos());
    
    char direction = 'r';

    while (true) {
        clear();
	
	if (!snake.set_snake_direction(direction))
		return 0;
	auto snakePos = snake.get_snake_pos();
        snake.set_snake_pos(direction, snakePos, gridYX);
        
	auto dotPos = dot.get_dot_pos();
	if (snakePos == dotPos) {
		snake.extend_snake();
        	dot.set_dot_pos(gridYX, snake.get_whole_snake());
	}
	
	print_borders(gridYX);
	snake.print_snake();
	dot.print_dot();
        
        refresh();
        usleep(150000);
    }

    endwin(); // ncurses'ten çık
    return 0;
}

