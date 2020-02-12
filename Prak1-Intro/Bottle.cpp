/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 30-01-2020 */
/* Program      : Ball.cpp */
/* Deskripsi    : Implementasi bottle */

#include "Bottle.hpp"
#include <iostream>

using namespace std;

int Bottle::numOfBottle = 0;

Bottle::Bottle() : id(numOfBottle+1) {
    height = 10.00;
    radius = 10.00;
    waterHeight = 0;
    numOfBottle++;
}

Bottle::Bottle(float height, float radius) : id(numOfBottle+1) {
    this -> height = height;
    this -> radius = radius;
    waterHeight = 0;
    numOfBottle++;
}

Bottle::Bottle(const Bottle& b) : id(b.id) {
    height = b.height;
    radius = b.radius;
    waterHeight = b.waterHeight;
}
Bottle::~Bottle() {
    //numOfBottle--;
}

/* Mengembalikan id Bottle */
int Bottle::getId() const {
	return id;
}

/* Mengembalikan volume air dalam botol */
float Bottle::getWaterVolume() const {
	return PI * waterHeight * radius * radius;
}

/* Mengembalikan volume botol */
float Bottle::getBottleVolume() const {
	return PI * height * radius * radius;
}

/*
 * Mengubah tinggi Bottle. Jika tinggi baru kurang dari tinggi air,
 * maka tinggi air = tinggi yang baru.
 */
void Bottle::setHeight(float height) {
	this -> height = height;
	if (height < waterHeight) waterHeight = height;
}

/*
 * Menambahkan air ke dalam botol. Jika botol tidak muat, biarkan
 * botol penuh.
 */
void Bottle::addWater(float waterVolume) {
	float curVolume = getWaterVolume() + waterVolume;
	if (curVolume >= getBottleVolume()) waterHeight = height;
	else waterHeight = getWaterHeightIfVolume(curVolume);
	//else waterHeight = curVolume / PI / (radius * radius);
}

/*
 * Mengurangi air dari botol. Jika air yang tersedia kurang, biarkan
 * botol kosong.
 */
void Bottle::substractWater(float waterVolume) {
	if (waterVolume >= getWaterVolume()) waterHeight = 0;
	else {
		float curVolume = getWaterVolume() - waterVolume;
		waterHeight = getWaterHeightIfVolume(curVolume);
		//waterHeight = curVolume / PI / (radius * radius);
	}
}

/*
* Mengembalikan tinggi air dari botol jika diketahui suatu volume air.
* Tinggi botol diabaikan, dianggap tidak akan terlalu penuh.
*/
float Bottle::getWaterHeightIfVolume(float waterVolume) const {
		return waterVolume / PI / radius / radius;
}

/*
* Menuang isi botol ini ke botol lain sampai botol ini kosong.
* Jika botol lain penuh sebelum semua air pindah, maka penuangan
* berhenti dan terdapat sisa air di botol ini.
*/
void Bottle::pourWaterTo(Bottle& other) {
	if (getWaterVolume() >= (other.getBottleVolume()-other.getWaterVolume()))
	substractWater(other.getBottleVolume()-other.getWaterVolume());
	else substractWater(getWaterVolume());

	other.addWater(getWaterVolume());
}
