#pragma once

#include "NPC.h"

class Elf : public NPC
{
public:
	Elf(std::string name);

	std::string render() override;
};

