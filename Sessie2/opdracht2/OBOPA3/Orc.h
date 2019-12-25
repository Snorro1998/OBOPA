#pragma once

#include "NPC.h"

class Orc : public NPC
{
public:
	Orc(std::string name);

	std::string render() override;
};

