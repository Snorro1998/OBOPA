#pragma once

#include<iostream>
#include <memory>
#include "windows.h"
#include "Strategy.h"

#define SIZE_HOR 25
#define SIZE_VER 25
#define CELL_FULL 'X'
#define CELL_EMPTY '.'

class Grid final
{
public:
	enum StrategyType
	{
		normal, wrap, neighbour_variant
	};

	Grid(StrategyType type=normal, bool randomize=true);

	void clearScreen();

	void printGrid();
	void calcNeigh();
	void updateGrid();
	void generateGrid();
	char raster[SIZE_HOR][SIZE_VER];
	char rasterNeigh[SIZE_HOR][SIZE_VER];

	void fillCell(char i, char j);
private:
	std::unique_ptr<Strategy> strategy;
};