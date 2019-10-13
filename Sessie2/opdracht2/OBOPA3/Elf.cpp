#include "pch.h"
#include "Elf.h"


Elf::Elf(std::string nam)
{
	name = nam;
}

std::string Elf::render()
{
	return "Elf\nname: " + name + "\n";
}