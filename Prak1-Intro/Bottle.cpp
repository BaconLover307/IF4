/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 30-01-2020 */
/* Program      : Ball.cpp */
/* Deskripsi    : Implementasi bottle */

#include "Bottle.hpp"
#include <iostream>

using namespace std;

int numOfBottle = 0;

Bottle::Bottle(float height, float radius) : id(numOfBottle+1) {
	this->height = height;
	this->radius = radius;
	waterHeight = 0;
	numOfBottle++;
} 
Bottle::Bottle() : id(numOfBottle+1) {
	this->height = 10.00;
	this->radius = 10.00;
	waterHeight = 0;
	numOfBottle++;
}

Bottle::Bottle(const Bottle& bottle) : id(bottle.id) {
	this->height = bottle.height;
	this->radius = bottle.radius;
	this->waterHeight = bottle.waterHeight;
}

Bottle::~Bottle() {
	// none
}

int Bottle::getId() const {
	return id;
}

float Bottle::getWaterVolume() const {
	return PI * radius * radius * waterHeight;
}

float Bottle::getBottleVolume() const {
	return PI * radius * radius * height;
}

void Bottle::setHeight(float height) {
	waterHeight = height<waterHeight ? height : waterHeight;
	this->height = height; 
}

void Bottle::addWater(float waterVolume) {
    float addHeight = waterVolume / (PI * radius * radius);
    waterHeight += addHeight;
	if (waterHeight > height) waterHeight = height;
}

void Bottle::substractWater(float waterVolume) {
    float subHeight = waterVolume / (PI * radius * radius);
    waterHeight -= subHeight;
	if (waterHeight < height) waterHeight = height;
}

float Bottle::getWaterHeightIfVolume(float waterVolume) const {
	return waterVolume / (PI * radius * radius);
}

void Bottle::pourWaterTo(Bottle & other) {
	addWater(other.getWaterVolume());
	other.substractWater(other.getWaterVolume());
}
