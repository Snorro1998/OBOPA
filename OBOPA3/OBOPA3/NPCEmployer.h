#pragma once
#include "NPC.h"

class NPCEmployer : public NPC
{
protected:
	NPC *m_employedNPC;

public:
	NPCEmployer(NPC *employedNPC) : m_employedNPC(employedNPC) {}
};