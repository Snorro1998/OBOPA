#pragma once
#include "NPCEmployer.h"

class Soldier : public NPCEmployer
{
public:
	Soldier(NPC *employedNPC) : NPCEmployer(employedNPC) {}

	std::string render() {
		return m_employedNPC->render() + "Occupation: Soldier\n";
	}
};
/*
class Soldier : public NPCEmployer
{
public:
	Soldier(NPC *employedNPC) : NPCEmployer(employedNPC) {}

	std::string render() {
		return m_employedNPC->render() + "Occupation: Soldier\n";
	}
};*/