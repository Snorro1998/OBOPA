#include "pch.h"
#include "Grid.h"


#if 0
Grid::Grid()
{
	for (int j = 0; j < SIZE_VER; j++) {
		for (int i = 0; i < SIZE_HOR; i++) {
			raster[i][j] = CELL_EMPTY;
		}
	}
}

Grid::~Grid()
{
}

void Grid::clearScreen() {
	system("cls");
}

void Grid::printGrid() {
	for (int j = 0; j < SIZE_VER; j++) {
		for (int i = 0; i < SIZE_HOR; i++) {
			std::cout << raster[i][j];
		}
		std::cout << std::endl;
	}
}

void Grid::calcNeigh() {
	for (int j = 0; j < SIZE_VER; j++) {
		for (int i = 0; i < SIZE_HOR; i++) {
			int numNeigh = 0;
			if (j > 0) {
				if (raster[i][j - 1] == CELL_FULL) numNeigh++;
			}
			if (j < SIZE_VER) {
				if (raster[i][j + 1] == CELL_FULL) numNeigh++;
			}
			if (i > 0) {

				if (j > 0) {
					if (raster[i - 1][j - 1] == CELL_FULL) numNeigh++;
				}
				if (j < SIZE_VER) {
					if (raster[i - 1][j + 1] == CELL_FULL) numNeigh++;
				}

				if (raster[i - 1][j] == CELL_FULL) numNeigh++;
			}

			if (i < SIZE_HOR) {
				if (j > 0) {
					if (raster[i + 1][j - 1] == CELL_FULL) numNeigh++;
				}
				if (j < SIZE_VER) {
					if (raster[i + 1][j + 1] == CELL_FULL) numNeigh++;
				}

				if (raster[i + 1][j] == CELL_FULL) numNeigh++;
			}
			rasterNeigh[i][j] = numNeigh;
		}
	}
}

void Grid::updateGrid() {
	for (int j = 0; j < SIZE_VER; j++) {
		for (int i = 0; i < SIZE_HOR; i++) {
			if (rasterNeigh[i][j] < 2 || rasterNeigh[i][j] > 3) {
				raster[i][j] = CELL_EMPTY;
			}
			else if (rasterNeigh[i][j] == 3 && raster[i][j] == CELL_EMPTY) {
				raster[i][j] = CELL_FULL;
			}
		}
	}
}

void Grid::generateGrid() {
	clearScreen();
	printGrid();
	calcNeigh();
	updateGrid();
}

void Grid::addWalker() {
	fillCell(1, 0);
	fillCell(2, 1);
	fillCell(0, 2);
	fillCell(1, 2);
	fillCell(2, 2);
}

void Grid::fillCell(char i, char j) {
	raster[i][j] = CELL_FULL;
}
#endif