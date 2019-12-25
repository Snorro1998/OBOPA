#include "pch.h"
#include <iostream>
#include "Module.h"
#include <vector>
#include <random>
#include "time.h"
#include <chrono> 
#include <algorithm>

#define N_DOCENTEN 3
#define N_STUDENTEN 10
#define N_MODULES 3

const char *docentNamen[]{
	"Adrie Meijer",
	"Harro Derksen",
	"Philip de Zeeuw"
};

const char *studentNamen[]{
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

void toonEC(std::vector<Student*> studs) {
	std::vector<Student*>::iterator stud = studs.begin();
	std::cout << "Totaal EC per student:" << std::endl << std::endl;
	while (stud != studs.end()) {
		std::cout << "Naam: " << (*stud)->naam << std::endl;
		std::cout << "EC: " << (*stud)->totaalEC << std::endl << std::endl;
		stud++;
	}
}

void toonModules(std::vector<Module*> mods) {
	std::cout << "Lijst van modules" << std::endl << std::endl;

	std::vector<Module*>::iterator it = mods.begin();
	while (it != mods.end()) {
		(*it)->geefModuleBeschrijving();
		std::cout << std::endl;
		it++;
	}
}

void wijzigEC(std::vector<Module*> mods, std::vector<Student*> studs) {
	std::vector<Module*>::iterator mod = mods.begin();
	(*mod)->wijzigEC(5);
	toonEC(studs);
}

void verwijderStudent(std::vector<Module*> mods) {
	//std::vector<Module*>::iterator mod = mods.begin() + 1;
	Student *s = mods[1]->geefStudent(0);
	for (Module *m : mods)
		m->verwijderStudent(s);
	//(*mod)->verwijderStudent(0);
	delete s;
	toonModules(mods);
}

int main()
{
	std::default_random_engine generator;
	generator.seed(std::chrono::system_clock::now().time_since_epoch().count());

	std::vector<Module*> modules;
	std::vector<Docent*> docenten;
	std::vector<Student*> studenten;

	for (int i = 0; i < N_DOCENTEN; i++) {
		Docent* nieuweDocent = new Docent(docentNamen[i]);
		docenten.push_back(nieuweDocent);
	}

	for (int i = 0; i < N_STUDENTEN; i++) {
		Student* nieuweStudent = new Student(studentNamen[i]);
		studenten.push_back(nieuweStudent);
	}

	std::shuffle(std::begin(docenten), std::end(docenten), generator);
	std::shuffle(std::begin(studenten), std::end(studenten), generator);

	for (int i = 0; i < N_MODULES; i++) {
		int ec = random(1, 4);
		Module* nieuweModule = new Module(moduleNamen[i], ec);
		nieuweModule->voegDocentToe(docenten[i]);
		modules.push_back(nieuweModule);
	}
	
	std::vector<Student*>::iterator stud = studenten.begin();
	while (stud != studenten.end()) {
		int aantalModules = random(1, N_MODULES);
		int offset = random(0, N_MODULES);
		for (int j = 0; j < aantalModules; j++) {
			modules[(j + offset) % aantalModules]->voegStudentToe(*stud);
		}
		stud++;
	}

	toonModules(modules);
	schoonSchermOp();
	toonEC(studenten);
	schoonSchermOp();
	wijzigEC(modules, studenten);
	schoonSchermOp();
	verwijderStudent(modules);

	return 0;
}