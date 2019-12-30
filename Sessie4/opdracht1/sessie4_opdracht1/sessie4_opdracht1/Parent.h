#pragma once

#include "pch.h"

#include <string>
#include <ostream>
#include "Child.h"
#include <memory>

class Parent {
public:
	Parent(std::string name);
	Parent(const Parent& other);
	virtual ~Parent();
	Parent& operator=(const Parent& other);

	friend std::ostream& operator<<(std::ostream& os, const Parent& parent);

	void deleteChild();

private:
	std::string name;
	std::unique_ptr<Child> child;
};