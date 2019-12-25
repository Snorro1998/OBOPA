#include "pch.h"
#include <iostream>
#include "Bankrekening.h"

int main()
{
	std::vector<Transactie> geen;

	Bankrekening bankrekening = Bankrekening(20, geen);

	Transactie transactie1("BIJ", 200, "6/9/2010");
	Transactie transactie2("AFS", 100, "7/9/2010");

	std::cout << bankrekening << std::endl;

	bankrekening = bankrekening + transactie1;
	std::cout << bankrekening << std::endl;

	bankrekening = bankrekening - transactie2;
	std::cout << bankrekening << std::endl;
}