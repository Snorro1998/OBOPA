#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <array>

template<typename T>
T sorteer(T arr) {
	std::sort(arr.begin(), arr.end());
	return arr;
}

void printArrays(std::array<int, 5> intArray, std::array<std::string, 6> stringArray) {
	std::array<int, 5>::iterator intIter = intArray.begin();
	std::array<std::string, 6>::iterator stringIter = stringArray.begin();

	while (intIter != intArray.end()) {
		std::cout << (*intIter) << " ";
		intIter++;
	}
	std::cout << std::endl;

	while (stringIter != stringArray.end()) {
		std::cout << (*stringIter) << " ";
		stringIter++;
	}
	std::cout << std::endl << std::endl;
}

int main()
{
	std::array<int, 5> intArray = { 4, 2, 5, 3, 1 };
	std::array<std::string, 6> stringArray = { "Patat", "Frikandel", "Kaassoufle", "Hamburger", "Kroket", "Bitterballen" };
	
	printArrays(intArray, stringArray);

	intArray = sorteer(intArray);
	stringArray = sorteer(stringArray);

	printArrays(intArray, stringArray);

	return 0;
}