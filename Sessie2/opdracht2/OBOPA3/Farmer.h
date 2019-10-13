#pragma once
#include "NPCEmployer.h"

class Farmer : public NPCEmployer
{
public:
	Farmer(NPC *employedNPC) : NPCEmployer(employedNPC) {}

	std::string render() {
		return m_employedNPC->render() + "Occupation: Farmer\n";
	}
};

