#include "pch.h"
#include <iostream>
#include <vector>
#include <thread>
#include <random>
#include <mutex>

std::mutex mut;

class ConcurrentVector {
public:
	void printData() {
		std::lock_guard<std::mutex> lock(mut);
		std::vector<int>::iterator it;
		int i = 0;
		for (it = data.begin(); it != data.end(); it++, i++) {
			std::cout << "index " << i << " van datavector bevat: " << (*it) << std::endl;
		}
		std::cout << std::endl;
	};

	void voegToe(int a) {
		std::lock_guard<std::mutex> lock(mut);
		data.push_back(a);
	};

private:
	std::vector<int> data;
};

void voegGetallenToe(ConcurrentVector conc, int getal) {
	for (int i = 0; i < 4; i++) {
		conc.voegToe(getal + i);
	}
	conc.printData();
}

int main() {
	
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(1, 6);

	ConcurrentVector con = ConcurrentVector();
	
	std::thread tre1(&voegGetallenToe, con, dist(rng));
	std::thread tre2(&voegGetallenToe, con, dist(rng) + 20);

	tre1.join();
	tre2.join();

	return 0;
}