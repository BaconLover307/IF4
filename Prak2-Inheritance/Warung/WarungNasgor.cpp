/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 13-02-2020 */
#include "WarungNasgor.hpp"
#include <iostream>
using namespace std;

// Masukan: Jumlah uang, nasi, telur, dan kecap
WarungNasgor::WarungNasgor(int uang, int nasi, int telur, int kecap) : WarungNasi(uang, telur, nasi) {
	this->kecap = kecap;
}

// Memasak menu Nasi Goreng
// Resep Nasi Goreng:
//     1 buah nasi
//     1 buah telur
//     1 buah kecap
// Jika bahan yang dibutuhkan kurang, kembalikan false.
// Jika cukup, hitung pendapatan total. Pendapatan total dihitung dengan jumlah pesanan dikali 15000
// Setelah itu, tambahkan pendapatan total ke uang. Kembalikan true.
bool WarungNasgor::masak(int pesanan) {
	
	int n = WarungNasi::getNasi();
	int t = WarungNasi::getTelur();
	if (n < pesanan && t < pesanan && this->kecap < pesanan) {
		return false;
	} else {
		int profit = pesanan * 15000;
		WarungNasi::setUang(WarungNasi::getUang() + profit);
		return true;
	}

}