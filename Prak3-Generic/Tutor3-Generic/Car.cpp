/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 20-02-2020 */
/* Program      : Car.cpp */
/* Deskripsi    : Implementasi dari Car.h */

#include "Car.h"
#include <iostream>
using namespace std;

Car::Car(Fuel t_fuel) {
	this->fuel = t_fuel;
	this->gear = 0;
	this->ac_power = 0;
	this->on = false;
}
Fuel Car::getFuel() {
	return this->fuel;
}
int Car::getGear() {
	return this->gear;

}
int Car::getAcPower() {
	return this->ac_power;

}
bool Car::getOn() {
	return this->on;
}

void Car::fillingFuel(Fuel t_fuel, int amount_in_liter) {
	if (getFuel() != t_fuel) {
		throw t_fuel;
	} else {
		cout << "Berhasil isi bensin sebanyak " << amount_in_liter << " liter" << endl;
	}
}

void Car::changeGear(int t_gear) {
	if (t_gear > MAX_GEAR || t_gear < MIN_GEAR) {
		throw t_gear;
	} else {
		this->gear = t_gear;
		cout << "Berhasil mengubah gigi menjadi gigi " << t_gear << endl;
	}
}

void Car::changeAcPower(int t_ac_power){
	if (MIN_AC <= t_ac_power && t_ac_power <= MAX_AC) {
		this->ac_power = t_ac_power;
		cout << "Berhasil mengubah power ac menjadi " << t_ac_power << endl;
	} else {
		throw t_ac_power;
	}
}

void Car::start() {
	if (on) {
		throw on;
	} else {
		on = true;
		cout << "Berhasil melakukan starter mobil" << endl;
	}
}

void Car::service(Fuel t_fuel, int amount_in_liter, int t_gear, int t_ac_power) {
	try {
		start();
		fillingFuel(t_fuel, amount_in_liter);
		changeGear(t_gear);
		changeAcPower(t_ac_power);
	}
	catch(bool on) {
		cout << "Mobil sudah menyala\n";
	} 
	catch(int p) {
		cout << "Input angka diluar range\n";
	}
	catch(Fuel t_fuel) {
		cout << "Bensin tidak sesuai\n";
	}
}