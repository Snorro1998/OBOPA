#pragma once
#include <iostream>
#include <vector>
#include "Transactie.h"

class Bankrekening
{
public:
	Bankrekening(float saldo, std::vector<Transactie> transacties);
	~Bankrekening();

	Bankrekening operator+(const Transactie& transactie) const;
	Bankrekening operator-(const Transactie& transactie) const;

	friend std::ostream& operator<<(std::ostream& os, const Bankrekening& bankrekening);

private:
	float saldo;
	std::vector<Transactie> transacties;
};

