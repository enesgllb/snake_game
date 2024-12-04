#include "Background.h"
#include <csignal>
#include <cstdlib>
#include <unistd.h>

void stop_program(int signal) {
	exit(0);
}


int main() {
	const int gridYSize{15};
	const int gridXSize{35};
	const char fillingCharacter{' '};
	
	Background background(gridYSize, gridXSize, fillingCharacter);
        background.add_snake_to_grid();

	std::pair<int, int> snakePos = background.get_snake_pos();
	int snakeX = snakePos.second;
	
        signal(SIGINT, stop_program);

	while (true) {
		background.clear_screen();
        	background.change_snake_pos(6, snakeX);
		snakeX++;
	       	snakeX = snakeX % gridXSize;
		background.print_grid();
		usleep(200000);
	}


	return 0;
}
