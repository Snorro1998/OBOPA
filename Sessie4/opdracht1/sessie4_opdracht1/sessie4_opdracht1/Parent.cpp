#include "pch.h"

#include <iostream>
#include "Parent.h"

Parent::Parent(std::string name) {
	this->name = name;
	std::string childName = "ChildOf" + name;
	this->child = std::make_unique<Child>(childName);
}

Parent::Parent(const Parent& other) {
	std::cout << "Parent cctor" << std::endl;
	this->name = other.name;
	this->child = std::make_unique<Child>(*other.child);
}

Parent::~Parent() {
	std::cout << "Parent dtor : " << this->name << std::endl;
}

void Parent::deleteChild() {
	child.reset();
}

Parent& Parent::operator=(const Parent& other) {
	std::cout << "Parent assignment" << std::endl;

	if (this == &other) return *this;

	this->name = other.name;
	this->child = std::make_unique<Child>(*other.child);

	return *this;
}

#ifdef MOVESEMANTICS
Parent::Parent(Parent&& other) noexcept {
	this->name = other.name;
	other.name = "";
	this->child.reset(other.child.release());
}

Parent& Parent::operator=(Parent&& other) {
	std::cout << "move-operator assignment" << std::endl;
	if (this != &other) {
		this->child.reset();
		this->name = other.name;
		other.name = "";
		this->child.reset(other.child.release());
	}
	return *this;
}
#endif


std::ostream& operator<<(std::ostream& os, const Parent& parent) {
	os << "parent name: " << parent.name;
	if (parent.child.get() != nullptr)
		os << "," << *parent.child;
	return os;
}