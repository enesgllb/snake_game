#include "Background.h"

int main() {
	const int gridRowSize{50}; // x
	const int gridColSize{15}; // y
	const char fillingCharacter{'x'};

	Background background(gridRowSize, gridColSize, fillingCharacter);
	background.print_grid();
	return 0;
}
