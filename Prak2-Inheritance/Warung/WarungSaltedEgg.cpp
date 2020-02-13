/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 13-02-2020 */
#include "WarungSaltedEgg.hpp"
#include <iostream>
using namespace std;

 // Masukan: Jumlah uang, nasi, telur, telur asin, dan ayam
WarungSaltedEgg::WarungSaltedEgg(int uang, int nasi, int telur, int telurAsin, int ayam) : WarungNasi(uang, telur, nasi) {
	this -> telurAsin = telurAsin;
	this -> ayam = ayam;
}

// Resep Nasi Ayam Salted Egg
//     1 Nasi
//     1 Telur
//     3 Telur Asin
//     1 Ayam
// Jika bahan yang dibutuhkan kurang, kembalikan false.
// Jika cukup, hitung pendapatan total. Pendapatan total dihitung dengan jumlah pesanan dikali 30000
// Setelah itu, tambahkan pendapatan total ke uang. Kembalikan true.
bool WarungSaltedEgg::masak(int pesanan) {
	int n = WarungNasi::getNasi();
	int t= WarungNasi::getTelur();
	int u = WarungNasi::getUang();
	if (n < pesanan && t < pesanan && this->telurAsin < 3*pesanan && this->ayam < pesanan) {
		return false;
	} else {
		int profit = pesanan * 30000;
		WarungNasi::setUang(u + profit);
		return true;
	}
}