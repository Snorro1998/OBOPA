#include "pch.h"
#include <algorithm>
#include <iostream>
#include <vector>

template<typename T>
T sorteer(T vect) {
	std::sort(vect.begin(), vect.end());
	return vect;
};

/*
template<typename T>
T printVector(T vect) {
	vect::iterator it = vect.begin();
	while (it != vect.end()) {
		std::cout << (*it) << " ";
		it++;
	}
};*/

int main()
{
	std::vector<int> ints = { 6085, 3009, 1998, 2019, 1925, 9001 };
	//std::string strings[] = {"ddd", "kk"};
	std::vector<std::string> strings = {"We", "reden", "met", "de", "auto"};

	std::vector<int>::iterator it1 = ints.begin();
	std::vector<std::string>::iterator it2 = strings.begin();

	while (it1 != ints.end()) {
		std::cout << (*it1) << " ";
		it1++;
	}

	std::cout << std::endl;

	ints = sorteer<std::vector<int>>(ints);
	strings = sorteer<std::vector<std::string>>(strings);



	it1 = ints.begin();

	while (it1 != ints.end()) {
		std::cout << (*it1) << " ";
		it1++;
	}

	std::cout << std::endl;

	std::vector<std::string> path;

	//for (std::vector<std::string>::const_iterator i = path.begin(); i != path.end(); ++i)
		//std::cout << *i << ' ';

	//std::cout << auto it2;
}