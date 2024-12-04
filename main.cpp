#include "Background.h"
#include <csignal>
#include <cstdlib>
#include <unistd.h>

void stop_program(int signal) {
	exit(0);
}

void set_direction(const char direction, int& snakeY, int& snakeX) {
	switch (direction) {
		case 'L' :
			snakeX++;
			break;
		case 'J' :
			snakeX--;
			break;
		case 'I' :
			snakeY--;
			break;
		case 'K' :
			snakeY++;
			break;
		default:
			std::cout << "Unknown direction" << std::endl;
	}
}

void run_test_scenario_1_straight_snake_run(Background& background, int snakeY, int& snakeX, int gridXSize) {
	background.clear_screen();
	background.change_snake_pos(snakeY, snakeX);
	snakeX++;
	snakeX = snakeX % gridXSize;
	background.print_grid();
	usleep(200000);	
}

void run_test_scenario_2_add_dot_and_make_snake_eats_it_run(Background& background, int& snakeY, int& snakeX, int gridYSize, int gridXSize) {
	background.clear_screen();
	background.print_grid();
        
	char direction;
	//direction = 'L'; // right +x
	//direction = 'J'; // left -x
	direction = 'I'; // up -y
	//direction = 'K'; // down +y
	
	set_direction(direction, snakeY, snakeX);
        snakeY = (snakeY + gridYSize) % gridYSize;
        snakeX = (snakeX + gridXSize) % gridXSize;
	background.change_snake_pos(snakeY, snakeX);

        usleep(200000);
}

int main() {
	signal(SIGINT, stop_program);

	const int gridYSize{15};
	const int gridXSize{35};
	const char fillingCharacter{' '};
	
	Background background(gridYSize, gridXSize, fillingCharacter);
        background.add_snake_to_grid(gridYSize, gridXSize);
	background.add_dot_to_grid(gridYSize, gridXSize);

	std::pair<int, int> snakePos = background.get_snake_pos();
	int snakeY = snakePos.first;
	int snakeX = snakePos.second;

	while (true) {
		//run_test_scenario_1_straight_snake_run(background, snakeY, snakeX, gridXSize);
		run_test_scenario_2_add_dot_and_make_snake_eats_it_run(background, snakeY, snakeX, gridYSize, gridXSize);
	}


	return 0;
}
