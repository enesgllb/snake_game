#include <iostream>
#include <ncurses.h>
#include <unistd.h> // sleep() için
#include "Snake.h"
#include "Dot.h"

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
        clear();                   // Ekranı temizle
	
	if (!snake.set_snake_direction(direction))
		return 0;
        auto snakePos = snake.get_snake_pos();
        snake.set_snake_pos(direction, snakePos, gridYX);
        
	auto dotPos = dot.get_dot_pos();
        //set_dot_pos(direction, snakePos.first, snakePos.second);
        
	mvprintw(snakePos.first, snakePos.second, "x");
        mvprintw(dotPos.first, dotPos.second, "o");
        refresh();
        usleep(150000);
    }

    endwin(); // ncurses'ten çık
    return 0;
}

