#include "pch.h"
#include "Shaman.h"

Shaman::Shaman(NPC *employedNPC) : NPCEmployer(employedNPC) {}

std::string Shaman::render() {
	return m_employedNPC->render() + "Occupation: Shaman\n";
}