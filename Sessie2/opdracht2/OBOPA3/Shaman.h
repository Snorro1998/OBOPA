#pragma once
#include "NPCEmployer.h"

class Shaman : public NPCEmployer
{
public:
	Shaman(NPC *employedNPC) : NPCEmployer(employedNPC) {}

	std::string render() {
		return m_employedNPC->render() + "Occupation: Shaman\n";
	}
};

/*
class Shaman : public NPCEmployer
{
public:
	Shaman(NPC *employedNPC) : NPCEmployer(employedNPC) {}

	std::string render() {
		return m_employedNPC->render() + "Occupation: Shaman\n";
	}
};
*/