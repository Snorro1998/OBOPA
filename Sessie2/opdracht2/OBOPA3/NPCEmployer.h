#pragma once
#include "NPC.h"

#include <memory>

class NPCEmployer : public NPC
{
protected:
	std::unique_ptr<NPC> m_employedNPC;

public:
	NPCEmployer(NPC *employedNPC);
};