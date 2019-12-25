#pragma once

#include <string>
#include <vector>
#include <set>
#include <memory>
#include "Docent.h"
#include "Student.h"

class Module
{
public:
	Module(std::string naam, int ec);
	~Module();

	void voegDocentToe(Docent* d);
	void voegStudentToe(std::shared_ptr<Student> s);
	void geefModuleBeschrijving();
	void somDocentenOp();
	void somStudentenOp();
	void verwijderStudent(std::shared_ptr<Student> s);
	void wijzigEC(int ec);

	const std::set<std::shared_ptr<Student>> &geefStudenten() const;

private:
	std::string naam;
	std::vector<Docent*> docenten;
	std::set<std::shared_ptr<Student>> studenten;
	int ec;
};

