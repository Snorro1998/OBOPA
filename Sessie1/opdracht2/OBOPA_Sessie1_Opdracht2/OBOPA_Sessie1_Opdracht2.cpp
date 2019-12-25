#include "pch.h"
#include "Grid.h"

int main()
{
	Grid grid = Grid();
	grid.addWalker();

	while (1) {
		grid.generateGrid();
		Sleep(150);
	}
}