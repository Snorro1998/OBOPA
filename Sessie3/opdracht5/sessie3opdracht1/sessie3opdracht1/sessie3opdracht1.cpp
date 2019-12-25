#include "pch.h"
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <algorithm>
#include <functional>

std::mutex mut;

class ConcurrentVector {
public:
	void voegToe(int a) {
		std::lock_guard<std::mutex> lock(mut);
		data.push_back(a);
	};

	bool check(unsigned threads, int limit) {
		std::lock_guard<std::mutex> lock(mut);

		// sorteer de lijst
		std::sort(data.begin(), data.end());

		// als alles goed ging, dan moet elk element (dus van 0 t/m limit)
		// precies 2 keer voorkomen als we met 2 threads concurrent dingen toevoegen

		long verwacht = threads * limit;

		if (data.size() != verwacht) {
			return false;
		}

		int counter = 0;

		for (unsigned i = 0; i < data.size(); i += threads) {
			for (unsigned j = i; j < i + threads; ++j) {
				if (data[j] != counter) {
					std::cerr << "afwijking gevonden op index: " << j << std::endl;
					return false;
				}
			}
			++counter;
		}

		return true;
	}

private:
	std::vector<int> data;
};

void voegGetallenToe(ConcurrentVector &conc, int bovengrens) {
	for (int i = 0; i < bovengrens; i++) {
		conc.voegToe(i);
	}
}

int main() {
	ConcurrentVector con = ConcurrentVector();

	int limit = 1000;

	std::thread tre1(&voegGetallenToe, std::ref(con), limit);
	std::thread tre2(&voegGetallenToe, std::ref(con), limit);

	tre1.join();
	tre2.join();

	if (!con.check(2, limit)) {
		std::cerr << "test gefaald" << std::endl;
	}
	else {
		std::cerr << "alle tests geslaagd" << std::endl;
	}

	return 0;
}