#include "pch.h"
#include "Module.h"
#include <iostream>
#include <memory>
#include <cassert>
#include <cstddef>

Module::Module(std::string naam, int ec) : naam(naam), ec(ec)
{
}

void Module::voegDocentToe(Docent* d) {
	docenten.push_back(d);
}

void Module::voegStudentToe(std::shared_ptr<Student> s) {
	studenten.insert(s);
	s->geefPunten(ec);
}

void Module::geefModuleBeschrijving() {
	std::cout << "Moduleinformatie:" << std::endl;
	std::cout << "Naam: " << naam << std::endl;
	somDocentenOp();
	
	std::cout << "EC: " << ec << std::endl;
	somStudentenOp();
}

void Module::somDocentenOp() {
	std::cout << "Docent" << (docenten.size() == 0 ? ": geen" : docenten.size() == 1 ? ": " : "en: ");

	std::vector<Docent*>::iterator it = docenten.begin();
	while (it != docenten.end()) {
		std::cout << (*it)->vertelNaam();
		if (it < docenten.end() - 1) std::cout << ", ";
		it++;
	}
	std::cout << std::endl;
}

void Module::somStudentenOp() {
	std::cout << "Student" << (studenten.size() == 0 ? ": geen" : studenten.size() == 1 ? ": " : "en: ");

	for (auto it = studenten.cbegin(); it != studenten.cend(); ++it) {
		if (it != studenten.cbegin())
			std::cout << ", ";
		std::cout << (*it)->vertelNaam();
	}
	std::cout << std::endl;
}

void Module::wijzigEC(int ec) {
	for (auto &x : studenten) {
		x->totaalEC += ec - this->ec;
	}
	this->ec = ec;
}

void Module::verwijderStudent(std::shared_ptr<Student> s) {
	s->geefPunten(-ec);
	assert(studenten.find(s) != studenten.end());
	studenten.erase(s);
}

const std::set<std::shared_ptr<Student>> &Module::geefStudenten() const {
	return studenten;
}

Module::~Module()
{
}
