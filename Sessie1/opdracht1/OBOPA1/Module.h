#pragma once

#include <string>
#include <vector>
#include "Docent.h"
#include "Student.h"

class Module
{
public:
	Module(std::string naam, int ec);
	~Module();

	void voegDocentToe(Docent* d);
	void voegStudentToe(Student* s);
	void geefModuleBeschrijving();
	void somDocentenOp();
	void somStudentenOp();
	void verwijderStudent(int i);
	void wijzigEC(int i);

private:
	std::string naam;
	std::vector<Docent*> docenten;
	std::vector<Student*> studenten;
	int ec;
};

