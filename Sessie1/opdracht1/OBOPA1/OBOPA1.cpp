#include "pch.h"
#include <iostream>
#include "Module.h"
#include <vector>
#include <random>
#include "time.h"
#include <chrono> 
#include <algorithm>
#include <memory>

#define N_MODULES 3

std::vector<std::string> docentNamen = {
	"Adrie Meijer",
	"Harro Derksen",
	"Philip de Zeeuw"
};

std::vector<std::string> studentNamen = {
	"Tjaard",
	"Bas",
	"Arnoud",
	"Geoffrey",
	"Luuk",
	"Lennart",
	"Folkert",
	"Chantal",
	"Lisanne",
	"Lara"
};

const char *moduleNamen[]{
	"Tekenen",
	"3D modelleren",
	"Animatie"
};

// FIXME use cpp RNG
int random(int min, int max)
{
	static bool first = true;
	if (first)
	{
		srand(time(NULL));
		first = false;
	}
	return min + rand() % ((max + 1) - min);
}

void schoonSchermOp() {
	system("pause");
	system("cls");
}

void toonEC(std::vector<std::shared_ptr<Student>> studs) {
	std::cout << "Totaal EC per student:" << std::endl << std::endl;

	for (auto &x : studs) {
		std::cout << "Naam: " << x->naam << std::endl;
		std::cout << "EC: " << x->totaalEC << std::endl << std::endl;
	}
}

void toonModules(std::vector<std::unique_ptr<Module>> &mods) {
	std::cout << "Lijst van modules" << std::endl << std::endl;

	for (auto &x : mods) {
		x->geefModuleBeschrijving();
		std::cout << std::endl;
	}
}

void wijzigEC(std::vector<std::unique_ptr<Module>> &mods, std::vector<std::shared_ptr<Student>> &studs) {
	std::vector<std::unique_ptr<Module>>::iterator mod = mods.begin();
	(*mod)->wijzigEC(5);
	toonEC(studs);
}

void verwijderStudent(std::vector<std::unique_ptr<Module>> &mods) {
	auto it = mods[1]->geefStudenten().cbegin();
	mods[1]->verwijderStudent(*it);
}

int main()
{
	std::default_random_engine generator;
	generator.seed(std::chrono::system_clock::now().time_since_epoch().count());

	std::vector<std::unique_ptr<Module>> modules;
	std::vector<std::shared_ptr<Docent>> docenten;
	std::vector<std::shared_ptr<Student>> studenten;

	for (const auto &x : docentNamen) {
		docenten.emplace_back(new Docent(x));
	}

	for (const auto &x : studentNamen) {
		studenten.emplace_back(new Student(x));
	}

	std::shuffle(std::begin(docenten), std::end(docenten), generator);

	for (int i = 0; i < N_MODULES; i++) {
		int ec = random(1, 4);
		modules.emplace_back(new Module(moduleNamen[i], ec));
		modules[modules.size() - 1]->voegDocentToe(docenten[i].get());
	}


	std::shuffle(std::begin(studenten), std::end(studenten), generator);

	for (auto s : studenten) {

		int aantalModules = random(1, N_MODULES);
		int offset = random(0, N_MODULES);

		for (int j = 0; j < aantalModules; ++j) {
			modules[(j + offset) % aantalModules]->voegStudentToe(s);
		}
	}

	toonModules(modules);
	schoonSchermOp();
	toonEC(studenten);
	schoonSchermOp();
	wijzigEC(modules, studenten);
	schoonSchermOp();
	verwijderStudent(modules);
	toonModules(modules);
	schoonSchermOp();
	toonEC(studenten);
	schoonSchermOp();

	return 0;
}
