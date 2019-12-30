#include "pch.h"

#include  "vld.h"
#include <iostream>
#include "Parent.h"

int main() {
	Parent* p1 = new Parent("Parent1");
	std::cout << "p1:" << *p1 << std::endl;

	Parent* p2 = new Parent(*p1); // roept de copy constructor aan
	std::cout << "p2:" << *p2 << std::endl;

	Parent* p3 = new Parent("Parent3");
	std::cout << "p3:" << *p3 << std::endl;

	*p3 = *p1; // roept de assignment operator aan
	std::cout << "p1:" << *p3 << std::endl;

	delete p1;
	delete p2;
	delete p3;

	auto p4 = std::make_shared<Parent>("Parent4");

	std::cout << "aantal keren gebruikt: " << p4.use_count() << std::endl;

	auto p5 = p4;
	auto p6 = p4;
	auto p7 = p4;

	std::cout << "aantal keren gebruikt: " << p4.use_count() << std::endl;

	p5->deleteChild();

	std::cout << *p4 << '\n' << *p5 << '\n' << *p6 << '\n' << *p7 << std::endl;

	return 0;
}