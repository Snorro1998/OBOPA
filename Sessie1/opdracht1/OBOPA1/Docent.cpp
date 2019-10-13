#include "pch.h"
#include "Docent.h"


Docent::Docent(std::string naam) : naam(naam)
{
}


Docent::~Docent()
{
}

std::string Docent::vertelNaam() {
	return naam;
}