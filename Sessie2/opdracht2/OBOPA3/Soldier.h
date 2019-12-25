#pragma once
#include "NPCEmployer.h"

class Soldier : public NPCEmployer
{
public:
	Soldier(NPC *employedNPC);

	std::string render() override;
};