#include "pch.h"
#include "Module.h"
#include <iostream>

Module::Module(std::string naam, int ec) : naam(naam), ec(ec)
{
}

void Module::voegDocentToe(Docent* d) {
	docenten.push_back(d);
}

void Module::voegStudentToe(Student* s) {
	studenten.push_back(s);
	s->geefPunten(ec);
}

void Module::geefModuleBeschrijving() {
	std::cout << "Moduleinformatie:" << std::endl;// << std::endl;
	std::cout << "Naam: " << naam << std::endl;
	somDocentenOp();
	
	std::cout << "EC: " << ec << std::endl;
	somStudentenOp();
}

void Module::somDocentenOp() {
	std::string str = docenten.size() == 0 ? ": geen" : docenten.size() == 1 ? ": " : "en: ";
	std::cout << "Docent" << str;

	std::vector<Docent*>::iterator it = docenten.begin();
	while (it != docenten.end()) {
		std::cout << (*it)->vertelNaam();
		if (it < docenten.end() - 1) std::cout << ", ";
		it++;
	}
	std::cout << std::endl;
}

void Module::somStudentenOp() {
	std::string str = studenten.size() == 0 ? ": geen" : studenten.size() == 1 ? ": " : "en: ";
	std::cout << "Student" << str;

	std::vector<Student*>::iterator it = studenten.begin();
	while (it != studenten.end()) {
		std::cout << (*it)->vertelNaam();
		if (it < studenten.end() - 1) std::cout << ", ";
		it++;
	}
	std::cout << std::endl;
}

void Module::wijzigEC(int i) {
	std::vector<Student*>::iterator stu = studenten.begin();
	while (stu != studenten.end()) {
		(*stu)->totaalEC += i - ec;
		stu++;
	}
	ec = i;
}

void Module::verwijderStudent(int i) {
	studenten.erase(studenten.begin() + i);
}


Module::~Module()
{
}
