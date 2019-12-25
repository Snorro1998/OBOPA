#include "pch.h"
#include "Soldier.h"

Soldier::Soldier(NPC *employedNPC) : NPCEmployer(employedNPC) {}

std::string Soldier::render() {
	return m_employedNPC->render() + "Occupation: Soldier\n";
}