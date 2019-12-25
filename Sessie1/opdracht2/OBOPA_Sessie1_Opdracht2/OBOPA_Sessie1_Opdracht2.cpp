#include "pch.h"
#include "Grid.h"

int main()
{
	Grid grid(Grid::StrategyType::neighbour_variant);

	while (1) {
		grid.generateGrid();
		Sleep(50);
	}

	return 0;
}