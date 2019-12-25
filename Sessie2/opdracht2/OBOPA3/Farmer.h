#pragma once
#include "NPCEmployer.h"

class Farmer : public NPCEmployer
{
public:
	Farmer(NPC *employedNPC);

	std::string render() override;
};

