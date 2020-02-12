/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 06-02-2020 */
/* Program      : Vehicle.hpp */
/* Deskripsi    : Implementasi Vehicle */

#include "Vehicle.hpp"
#include <iostream>

using namespace std;

Vehicle::Vehicle() {
	this->fuel = 0;
}

void Vehicle::addFuel(float fuel) {
	this->fuel += fuel;
}
void Vehicle::drive() {
	cout << "Driving ..." << endl;
}

MotorCycle::MotorCycle() : Vehicle() {
	//
}

void MotorCycle:drive() {
	cout << "Use helmet" << endl;
	Vehicle::drive();
}

Car::Car() : Vehicle() {
	//
}

Car::

void
