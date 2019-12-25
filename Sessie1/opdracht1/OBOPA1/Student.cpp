#include "pch.h"
#include "Student.h"


Student::Student(std::string naam) :naam(naam)
{
}

void Student::geefPunten(int ec) {
	totaalEC += ec;
}

std::string Student::vertelEC() {
	return std::to_string(totaalEC);
}

std::string Student::vertelNaam() {
	return naam;
}

std::string Student::vertelInfo() {
	std::cout << "Naam: " << vertelNaam() << "";
	std::string tmp = "Naam: " + vertelNaam() + ", EC: " + std::to_string(totaalEC);
	return tmp;
}
