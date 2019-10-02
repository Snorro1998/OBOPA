#include "pch.h"
#include <iostream>

#include "Elf.h"
#include "Orc.h"

#include "Farmer.h"
#include "Soldier.h"
#include "Shaman.h"

int main() {
	NPC *orc1 = new Soldier(new Orc("Grunk"));
	std::cout << orc1->render() << std::endl;

	NPC *Elf1 = new Shaman(new Elf("Dobby"));
	std::cout << Elf1->render() << std::endl;

	NPC *Elf2 = new Farmer(new Elf("Elvis"));
	std::cout << Elf2->render() << std::endl;

	return 0;
}