#include "pch.h"

#include "Strategy.h"

Strategy::Strategy(bool wrap) : Strategy(2, 3, 3, 3, wrap) {}

Strategy::Strategy(int lmin, int lmax, int bmin, int bmax, bool wrap)
	: Strategy(lmin, lmax, bmin, bmax, wrap,
		{
			{ -1,-1 }, { 0,-1 }, { 1,-1 },
			{ -1,0 }, { 1,0 },
			{ -1,1 }, { 0,1 }, { 1,1 }
		})
{
}

Strategy::Strategy(int lmin, int lmax, int bmin, int bmax, bool wrap, std::vector<Offset> offsets)
	: liveMin(lmin), liveMax(lmax), bornMin(bmin), bornMax(bmax), wrapMode(wrap), offsets(offsets) {}

Strategy2x2::Strategy2x2(bool wrap) : Strategy2x2(2, 3, 3, 3, wrap) {}

Strategy2x2::Strategy2x2(int lmin, int lmax, int bmin, int bmax, bool wrap)
	: Strategy(lmin, lmax, bmin, bmax, wrap,
		{
			{0, -1},
			{-1,0}, {1,0},
			{0,1}
		})
{
}