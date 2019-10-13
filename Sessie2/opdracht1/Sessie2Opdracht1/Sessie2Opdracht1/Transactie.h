#pragma once
#include <iostream>
#include <string>

class Transactie
{
public:
	Transactie(std::string soort = "BIJ", float bedrag = 21, std::string datum = "14/01/1998");
	~Transactie();

	float geefBedrag() const;
	std::string geefBeschrijving() const;

private:
	std::string soort;
	float bedrag;
	std::string datum;
};

