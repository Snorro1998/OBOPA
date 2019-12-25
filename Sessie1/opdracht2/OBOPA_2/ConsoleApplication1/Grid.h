#pragma once
#include "Cell.h"

#define SIZE_HOR 25
#define SIZE_VER 25

class Grid
{
public:
	Grid();
	~Grid();

private:
	Cell raster[SIZE_HOR][SIZE_VER];
};

#if 0
#include<iostream>
#include "windows.h"
#include "Cell.h"

#define SIZE_HOR 25
#define SIZE_VER 25
#define CELL_FULL 'X'
#define CELL_EMPTY '.'

class Grid
{
public:
	Grid();
	~Grid();

	void clearScreen();

	void printGrid();
	void calcNeigh();
	void updateGrid();
	void generateGrid();
	char raster[SIZE_HOR][SIZE_VER];
	char rasterNeigh[SIZE_HOR][SIZE_VER];

	void fillCell(char i, char j);
	void addWalker();
};

#endif