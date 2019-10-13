#include "pch.h"
#include "Orc.h"


Orc::Orc(std::string nam)
{
	name = nam;
}


std::string Orc::render()
{
	return "Elf\nname: " + name + "\n";
}