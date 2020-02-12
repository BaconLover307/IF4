/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 06-02-2020 */
/* Program      : Rekening.hpp */
/* Deskripsi    : Implementasi Rekening */

#include "Rekening.h"
#include <iostream>

using namespace std;

Rekening::Rekening(double saldo) {
	if (saldo < 0) this->saldo = 0;
	else this->saldo = saldo;
}

void Rekening::setSaldo(double saldo) {
	this->saldo = saldo;
}

double Rekening::getSaldo() const{
	return saldo;
}

void Rekening::simpanUang(double uang) {
	saldo += uang;
}

bool Rekening::tarikUang(double uang) {
	if (uang <= saldo) {
		saldo -= uang;
		return true;
	} else return false;
}