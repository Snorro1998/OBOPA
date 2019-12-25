#include "pch.h"
#include "Grid.h"

#include <cstring>
#include <random>

Grid::Grid(StrategyType type, bool randomize)
{
	if (randomize) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(0, 1);

		for (int j = 0; j < SIZE_VER; j++) {
			for (int i = 0; i < SIZE_HOR; i++) {
				raster[i][j] = dis(gen) ? CELL_FULL : CELL_EMPTY;
			}
		}
	}
	else {
		memset(raster, CELL_EMPTY, SIZE_VER * SIZE_HOR);

		fillCell(1, 0);
		fillCell(2, 1);
		fillCell(0, 2);
		fillCell(1, 2);
		fillCell(2, 2);
	}

	switch (type) {
	case normal:
		strategy.reset(new Strategy());
		break;
	case wrap:
		strategy.reset(new Strategy(true));
		break;
	case neighbour_variant:
		strategy.reset(new Strategy2x2(1, 3, 1, 2, true));
		break;
	}
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
	const std::vector<Offset> &offsets = strategy->offsets;

	for (int y = 0; y < SIZE_VER; ++y) {
		for (int x = 0; x < SIZE_HOR; ++x) {
			int nx, ny, count = 0;

			for (auto &o : offsets) {
				nx = x + o.dx;
				ny = y + o.dy;

				if (strategy->wrapMode) {
					if (nx < 0)
						nx += SIZE_HOR;
					else if (nx >= SIZE_HOR)
						nx -= SIZE_HOR;
					if (ny < 0)
						ny += SIZE_VER;
					else if (ny >= SIZE_VER)
						ny -= SIZE_VER;
				}

				// bounds check
				if (nx < 0 || ny < 0 || nx >= SIZE_HOR || ny >= SIZE_VER) {
					continue;
				}

				if (raster[nx][ny] == CELL_FULL) {
					++count;
				}
			}

			rasterNeigh[x][y] = count;
		}
	}
}

void Grid::updateGrid() {
	int liveMin = strategy->liveMin, liveMax = strategy->liveMax;
	int bornMin = strategy->bornMin, bornMax = strategy->bornMax;

	for (int y = 0; y < SIZE_VER; y++) {
		for (int x = 0; x < SIZE_HOR; x++) {
			if (rasterNeigh[x][y] < liveMin || rasterNeigh[x][y] > liveMax) {
				raster[x][y] = CELL_EMPTY;
			}
			else if (rasterNeigh[x][y] >= bornMin && rasterNeigh[x][y] <= bornMax && raster[x][y] == CELL_EMPTY) {
				raster[x][y] = CELL_FULL;
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

void Grid::fillCell(char i, char j) {
	raster[i][j] = CELL_FULL;
}