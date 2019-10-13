#include "pch.h"
#include <queue>
#include <thread>
#include <iostream>
#include <condition_variable>
#include <string>

int counter = 0;
bool done = false;
std::queue<int> goods;

std::condition_variable flag;
std::mutex mutex;

void producer() {
	for (int i = 0; i < 500; ++i) {
		goods.push(i);
		counter++;
	}

	flag.notify_one();
	done = true;
}

void consumer() {
	std::unique_lock<std::mutex> lock(mutex);
	while (!done) {
		flag.wait(lock);
		while (!goods.empty()) {
			goods.pop();
			counter--;
		}
	}
}


int main() {
	std::thread producerThread(producer);
	std::thread consumerThread(consumer);

	producerThread.join();
	consumerThread.join();

	std::cout << "Net: " << counter << " " << goods.size() << " " << std::endl;

	return 0;
}