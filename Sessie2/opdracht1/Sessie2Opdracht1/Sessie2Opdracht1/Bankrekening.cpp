#include "pch.h"
#include "Bankrekening.h"


Bankrekening::Bankrekening(float saldo, std::vector<Transactie> transacties)
{
	this->saldo = saldo;
	this->transacties = transacties;
}

Bankrekening Bankrekening::operator+(const Transactie& transactie) const {
	std::vector<Transactie> transactiesNieuw = transacties;
	transactiesNieuw.push_back(transactie);
	return Bankrekening(saldo + transactie.geefBedrag(), transactiesNieuw);
};

Bankrekening Bankrekening::operator-(const Transactie& transactie) const {
	std::vector<Transactie> transactiesNieuw = transacties;
	transactiesNieuw.push_back(transactie);
	return Bankrekening(saldo - transactie.geefBedrag(), transactiesNieuw);
};

std::ostream& operator<<(std::ostream& os, const Bankrekening& bankrekening) {
	os << "Saldo: " << bankrekening.saldo << " EUR" << std::endl
		<< "Transactiegeschiedenis: " << std::endl;

	std::vector<Transactie> tra = bankrekening.transacties;

	for (const auto &t : tra)
	{
		os << t.geefBeschrijving() << std::endl;
	}
	os << std::endl;
	
	return os;
}