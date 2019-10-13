#include "pch.h"
#include "Transactie.h"


Transactie::Transactie(std::string soort, float bedrag, std::string datum)
{
	this->soort = soort;
	this->bedrag = bedrag;
	this->datum = datum;
}


Transactie::~Transactie()
{
}

float Transactie::geefBedrag() const {
	return bedrag;
}

std::string Transactie::geefBeschrijving() const {
	//std::string tmp = datum + " " + soort + " " + std::to_string(bedrag);
	std::string tmp = soort + " " + std::to_string(bedrag) + " " + datum;
	return tmp;
}