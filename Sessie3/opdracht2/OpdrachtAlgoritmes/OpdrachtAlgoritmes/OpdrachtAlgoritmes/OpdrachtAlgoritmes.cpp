#include "pch.h"
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <locale>
#include <vector>
#include <numeric>

std::string zoekTerm = "purple";

bool isNegatief(int i) {
	return i < 0;
}

void printVector(std::vector<std::string> &vec) {
	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec.at(i);
		if (i != vec.size() - 1) std::cout << ", ";
		else std::cout << std::endl;
	}
	std::cout << std::endl;
}

void printVector2(std::vector<double> &vec) {
	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec.at(i);
		if (i != vec.size() - 1) std::cout << ", ";
		else std::cout << std::endl;
	}
	std::cout << std::endl;
}

void splitFunctie(std::vector<std::string> &vec, std::vector<std::string> &voor, std::vector<std::string> &na, std::string term) {
	std::size_t splitIndex = -1;
	std::vector<std::string>::iterator it = std::find(vec.begin(), vec.end(), term);

	if (it != vec.end()) {
		splitIndex = distance(vec.begin(), it);
		std::cout << "'" << term << "' gevonden in de vector op index " << splitIndex << std::endl;
	}
	else std::cout << "'" << term << "' niet gevonden in de vector'" << std::endl;

	if (splitIndex != -1) {

		std::vector<std::string> splitVoor(vec.begin(), vec.begin() + splitIndex);
		std::vector<std::string> splitNa(vec.begin() + splitIndex + 1, vec.end());

		voor = splitVoor;
		na = splitNa;
	}
}

void maakHoofdletters(std::vector<std::string> &vec) {
	for (int i = 0; i < vec.size(); i++) {
		std::transform(vec.at(i).begin(), vec.at(i).end(), vec.at(i).begin(), ::toupper);
	}
}

void verwijderDubbele(std::vector<std::string> &vec) {
	auto end = vec.end();
	for (auto it = vec.begin(); it != end; ++it) {
		end = std::remove(it + 1, end, *it);
	}
	vec.erase(end, vec.end());
}

void sorteer(std::vector<std::string> &vec) {
	std::sort(vec.begin(), vec.end());
}

void verwijderNegatief(std::vector<double> &vec) {
	vec.erase(std::remove_if(vec.begin(), vec.end(), isNegatief), vec.end());
}

//fransbauerfunctie die niet helemaal werkt
void bepaalEven(std::vector<double> &vec) {
	std::cout << "Heb je even voor mij..." << std::endl;
	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec.at(i) << ": " << ((int)vec.at(i) % 2 == 0 ? "ja" : "nee") << std::endl;
	}
	std::cout << std::endl;
}

double berekenSom(std::vector<double> &vec) {
	return std::accumulate(vec.begin(), vec.end(), 0.0);
}

double berekenGemiddelde(std::vector<double> &vec) {
	double som = berekenSom(vec);
	return som / vec.size();
}

//WERKT GELOOF IK NIET
double berekenProduct(std::vector<double>&vec) {
	return std::accumulate(vec.begin(), vec.end(), 1, std::multiplies<double>());
}

int main() {
	std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
	std::vector<std::string> coloursTmp = colours;
	
	std::cout << "Originele vector: " << std::endl;
	printVector(coloursTmp);

	sorteer(coloursTmp);
	std::cout << "Alfabetisch gesorteerde vector: " << std::endl;
	printVector(coloursTmp);

	std::vector<std::string> voorZoekterm;
	std::vector<std::string> naZoekterm;

	splitFunctie(coloursTmp, voorZoekterm, naZoekterm, zoekTerm);
	std::cout << std::endl;

	std::cout << "Elementen in vector voor '" << zoekTerm << "':" << std::endl;
	printVector(voorZoekterm);

	std::cout << "Elementen in vector na '" << zoekTerm << "':" << std::endl;
	printVector(naZoekterm);

	coloursTmp = colours;
	maakHoofdletters(coloursTmp);
	std::cout << "VECTOR IN KOEIENLETTERS: " << std::endl;
	printVector(coloursTmp);

	coloursTmp = colours;
	verwijderDubbele(coloursTmp);
	std::cout << "Vector zonder duplicaten: " << std::endl;
	printVector(coloursTmp);

	std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };
	std::vector<double> numbersTmp = numbers;

	std::cout << "Originele vector:" << std::endl;
	printVector2(numbersTmp);

	verwijderNegatief(numbersTmp);
	std::cout << "Vector zonder negatieve elementen:" << std::endl;
	printVector2(numbersTmp);

	numbersTmp = numbers;
	bepaalEven(numbersTmp);

	std::cout << "Som = " << berekenSom(numbersTmp) << std::endl;
	std::cout << "Gemiddelde = " << berekenGemiddelde(numbersTmp) << std::endl;
	std::cout << "Product = " << berekenProduct(numbersTmp) << std::endl;
	
	return 0;
}