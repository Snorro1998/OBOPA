#include "pch.h"
#include "Farmer.h"

Farmer::Farmer(NPC *employedNPC) : NPCEmployer(employedNPC) {}

std::string Farmer::render() {
	return m_employedNPC->render() + "Occupation: Farmer\n";
}