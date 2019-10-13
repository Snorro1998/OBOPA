#pragma once
#include <string>
#include <iostream>

class Student
{
public:
	Student(std::string naam);
	~Student();

	std::string vertelEC();
	std::string vertelNaam();
	std::string vertelInfo();
	void geefPunten(int ec);

	std::string naam;
	int totaalEC = 0;
	/*
private:
	std::string naam;
	int totaalEC;*/
};

