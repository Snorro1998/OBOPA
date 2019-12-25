#pragma once

#include <vector>

class Offset {
public:
	int dx, dy;

	Offset() : Offset(0, 0) {}
	Offset(int dx, int dy) : dx(dx), dy(dy) {}
};

class Strategy
{
public:
	int liveMin, liveMax, bornMin, bornMax;
	bool wrapMode;

	std::vector<Offset> offsets;

	Strategy(bool wrap=false);
	Strategy(int lmin, int lmax, int bmin, int bmax, bool wrap=false);
	virtual ~Strategy() {}
protected:
	Strategy(int lmin, int lmax, int bmin, int bmax, bool wrap, std::vector<Offset> offsets);
};

class Strategy2x2 : public Strategy
{
public:
	Strategy2x2(bool wrap=false);
	Strategy2x2(int lmin, int lmax, int bmin, int bmax, bool wrap=false);
	virtual ~Strategy2x2() {}
};