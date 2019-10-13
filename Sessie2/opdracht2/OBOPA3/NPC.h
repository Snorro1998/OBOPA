#pragma once
#include <string>

class NPC
{
public:
	NPC();
	virtual ~NPC() {}

	virtual std::string render() = 0;
};

