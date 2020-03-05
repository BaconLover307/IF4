/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 06-02-2020 */
/* Program      : RekeningTabungan.hpp */
/* Deskripsi    : Implementasi RekeningTabungan */

#include "RekeningTabungan.h"
#include <iostream>

using namespace std;

RekeningTabungan::RekeningTabungan(double saldo, double bt) : Rekening(saldo) {
	if (bt < 0) this->biayaTransaksi = 0;
	else this->biayaTransaksi = bt;
}

void RekeningTabungan::setBiayaTransaksi(double bt) {
	if (bt < 0) this->biayaTransaksi = 0;
	else this->biayaTransaksi = bt;
}

double RekeningTabungan::getBiayaTransaksi() const{
	return biayaTransaksi;
}

void RekeningTabungan::simpanUang(double uang) {
	Rekening::simpanUang(uang);
	Rekening::setSaldo(Rekening::getSaldo() - biayaTransaksi);
}

bool RekeningTabungan::tarikUang(double uang) {
	bool ok = Rekening::tarikUang(uang);
	if (ok)
		Rekening::setSaldo(getSaldo() - biayaTransaksi);
	return ok;
}
