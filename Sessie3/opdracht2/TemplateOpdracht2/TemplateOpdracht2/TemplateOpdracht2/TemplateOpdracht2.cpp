#include "pch.h"
#include <iostream>
#include <vector>

template <class T>
class MyContainer {

public:
	void put(const T& type);
	T get();
	int size();

private:
	std::vector<T> data;
};

template <class T>
void MyContainer<T>::put(T const& elem) {
	std::cout << "Voegt element '" << (elem) << "' toe" << std::endl;
	data.push_back(elem);
};

template <class T>
T MyContainer<T>::get() {
	return data.empty() ? 0 : *data.begin();
};

template <class T>
int MyContainer<T>::size() {
	return(data.size());
};


int main()
{
	MyContainer<int> testClass;

	std::cout << "Eerste element = " << testClass.get() << ", lijstgrootte = " << testClass.size() << std::endl;

	testClass.put(10);
	testClass.put(30);
	
	std::cout << "Eerste element = " << testClass.get() << ", lijstgrootte = " << testClass.size() << std::endl;

	return 0;
}