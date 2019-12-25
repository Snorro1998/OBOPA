#pragma once
#include <string>

class NPC
{
public:
	NPC();
	virtual ~NPC() {}

	std::string name;

	virtual std::string render() = 0;
};

