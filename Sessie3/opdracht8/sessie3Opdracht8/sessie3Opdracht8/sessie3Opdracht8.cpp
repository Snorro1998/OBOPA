#include "pch.h"
#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <cctype>
#include <cmath>
#include <iomanip>

#include <vector>

template <typename T>
void printVector(std::string naam, std::vector<T> vec) {
	if (naam.size())
		std::cout << naam.c_str() << " bevat: ";
	for (auto &x : vec)
		std::cout << x << " ";
	std::cout << std::endl;
}

void printVector(std::string naam, std::vector<std::string> vec) {
	if (naam.size())
		std::cout << naam.c_str() << " bevat: ";
	for (auto &x : vec)
		std::cout << x.c_str() << " ";
	std::cout << std::endl;
}


void maakHoofdletters(std::string &s) {
	std::transform(s.begin(), s.end(), s.begin(),
		[](unsigned char c) { return std::toupper(c); }
	);
}

void hoofdletters(std::vector<std::string> &vec) {
	for (auto &x : vec)
		maakHoofdletters(x);
}

void maakPositief(std::vector<double> &vecIn, std::vector<double> &vecOut) {
	for (auto &x : vecIn) {
		if (x >= 0) vecOut.push_back(x);
	}
}

void evenOneven(std::vector<double> &vecIn, std::vector<double> &vecEven, std::vector<double> &vecOneven) {
	for (auto &x : vecIn)
		if (fmod(x, 2.0) != 0)
			vecOneven.push_back(x);
		else
			vecEven.push_back(x);
}

double berekenSom(std::vector<double> &vecIn) {
	double som = 0;
	for (auto &x : vecIn)
		som += x;
	return som;
}

double berekenGemiddelde(std::vector<double> &vecIn) {
	return berekenSom(vecIn) / vecIn.size();
}

double berekenProduct(std::vector<double> &vecIn) {
	double product = 1;
	for (auto &x : vecIn)
		product *= x;
	return product;
}

#define PRINT_VECTOR(a) printVector(#a, a)

int main() {
	
	// gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
	// 1) de vector in 2 nieuwe vectoren te splitsen: 1 met alles wat alfabetisch voor 'purple' komt, 1 met alles er na
	std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" }, reeksOndergrens, reeksBovengrens;
	std::cout << "Kleurenreeks: ";
	printVector("", colours);


	auto colourCopy(colours);
	auto sortedColours(colours);
	std::sort(sortedColours.begin(), sortedColours.end());

	auto firstIndex = std::find(sortedColours.begin(), sortedColours.end(), "purple");

	std::copy(sortedColours.begin(), firstIndex, std::back_inserter(reeksOndergrens));
	std::copy(firstIndex, sortedColours.end(), std::back_inserter(reeksBovengrens));

	PRINT_VECTOR(reeksOndergrens);
	PRINT_VECTOR(reeksBovengrens);

	// 2) alle elementen UPPERCASE te maken
	hoofdletters(colourCopy);
	printVector("hoofdLetterReeks", colourCopy);
	//PRINT_VECTOR(colourCopy);

	// 3) alle dubbele te verwijderen
	colourCopy.clear();
	std::unique_copy(sortedColours.begin(), sortedColours.end(), std::back_inserter(colourCopy));
	printVector("uniekeReeks", colourCopy);
	//PRINT_VECTOR(colourCopy);



	// gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
	// 1) alle negatieve elementen te verwijderen
	std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 }, positiefReeks, evenReeks, onevenReeks;
	printVector("\nGetallenreeks", numbers);

	maakPositief(numbers, positiefReeks);
	PRINT_VECTOR(positiefReeks);

	// 2) voor alle elementen te bepalen of ze even of oneven zijn
	evenOneven(numbers, evenReeks, onevenReeks);
	PRINT_VECTOR(evenReeks);
	PRINT_VECTOR(onevenReeks);

	// 3) de som, het gemiddelde, en het product van alle getallen te berekenen
	std::cout << "de som van de getallenreeks is: " << std::setprecision(4) << std::fixed << berekenSom(numbers) << std::endl;
	std::cout << "het gemiddelde van de getallenreeks is: " << berekenGemiddelde(numbers) << std::endl;
	std::cout << "het product van de getallenreeks is: " << std::setprecision(0) << berekenProduct(numbers) << std::endl;

	return 0;
}
