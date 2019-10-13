#pragma once
#include <string>

class Docent
{
public:
	Docent(std::string naam);
	~Docent();

	std::string vertelNaam();

private:
	std::string naam;
};

