#pragma once
#include "NPC.h"

class Elf : public NPC
{
public:
	Elf(std::string nam);

	std::string render();
	std::string name;
};

