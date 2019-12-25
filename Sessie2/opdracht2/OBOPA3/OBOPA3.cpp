#include "pch.h"
#include <iostream>

#include "Elf.h"
#include "Orc.h"

#include "Farmer.h"
#include "Soldier.h"
#include "Shaman.h"

#include <memory>

int main() {
	std::unique_ptr<NPC> orc1(new Soldier(new Orc("Grunk")));
	std::cout << orc1->render() << std::endl;

	std::unique_ptr<NPC> elf1(new Shaman(new Elf("Dobby")));
	std::cout << elf1->render() << std::endl;

	std::unique_ptr<NPC> elf2(new Farmer(new Elf("Elvis")));
	std::cout << elf2->render() << std::endl;

	return 0;
}