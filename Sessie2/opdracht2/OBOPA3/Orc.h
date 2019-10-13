#pragma once
#include "NPC.h"

class Orc : public NPC
{
public:
	Orc(std::string nam);

	std::string render();
	std::string name;
};

