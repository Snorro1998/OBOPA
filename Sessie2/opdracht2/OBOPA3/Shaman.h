#pragma once
#include "NPCEmployer.h"

class Shaman : public NPCEmployer
{
public:
	Shaman(NPC *employedNPC);

	std::string render() override;
};