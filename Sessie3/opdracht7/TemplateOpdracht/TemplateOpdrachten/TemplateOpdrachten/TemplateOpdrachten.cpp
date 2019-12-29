#include "pch.h"
#include <string>
#include <iostream>
#include <vector>

float getallen[] = {90.01 , -200, 42000, 6.9, -91.2, 8.34, 374.63, 78, 38 };
std::string snacks[] = { "Patat", "Frikandel", "Kaassoufle", "Hamburger", "Kroket", "Bitterballen" };

//insertion sorteeralgoritme
template<typename T>
void sorteer(T reeks[], unsigned grootte) {
	for (unsigned i = 1; i < grootte; ++i) {
		for (unsigned j = i; j > 0 && reeks[j - 1] > reeks[j]; --j) {
			T tmp = reeks[j];
			reeks[j] = reeks[j - 1];
			reeks[j - 1] = tmp;
		}
	}
}

template<typename T>
class Wachtrij {
public:
	void put(T element) {
		inhoud.push_back(element);
	}

	// TODO: beginelement verwijderen? Of alleen opvragen?
	T get() {
		return inhoud[0];
	}

	void pop() {
		for (unsigned i = 1; i < inhoud.size(); ++i) {
			inhoud[i - 1] = inhoud[i];
		}

		inhoud.pop_back();
	}

	int size() {
		return inhoud.size();
	}

	void dump() const {
		for (const T &t : inhoud) {
			std::cout << " " << t;
		}
		std::cout << std::endl;
	}

private:
	std::vector<T> inhoud;
};

int main() {
	sorteer(getallen, 9);
	sorteer(snacks, 6);

	for (auto &x : getallen)
		std::cout << " " << x;
	std::cout << std::endl;

	for (auto &x : snacks)
		std::cout << " " << x;
	std::cout << std::endl;

	Wachtrij<int> w;

	w.dump();
	w.put(5);
	w.dump();
	w.put(40);
	w.dump();
	w.put(120);
	w.dump();
	w.put(-8);
	w.dump();

	std::cout << "kop: "<< w.get() << std::endl;

	w.pop();
	w.dump();
	w.pop();
	w.dump();
	w.pop();
	w.dump();

	return 0;
}