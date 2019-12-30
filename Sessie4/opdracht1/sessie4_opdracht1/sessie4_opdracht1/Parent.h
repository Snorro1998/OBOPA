#pragma once

#include "pch.h"

#include <string>
#include <ostream>
#include "Child.h"
#include <memory>

#define MOVESEMANTICS

class Parent {
public:
	Parent(std::string name);
	Parent(const Parent& other);
	virtual ~Parent();
	Parent& operator=(const Parent& other);
#ifdef MOVESEMANTICS
	Parent(Parent&&) noexcept;
	Parent& operator=(Parent&& other);
#endif


	friend std::ostream& operator<<(std::ostream& os, const Parent& parent);

	void deleteChild();

private:
	std::string name;
	std::unique_ptr<Child> child;
};