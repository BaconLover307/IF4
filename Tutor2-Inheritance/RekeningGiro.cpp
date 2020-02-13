/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 06-02-2020 */
/* Program      : RekeningGiro.hpp */
/* Deskripsi    : Implementasi RekeningGiro */

#include "RekeningGiro.h"
#include <iostream>

using namespace std;

RekeningGiro::RekeningGiro(double saldo, double sb) : Rekening(saldo) {
	if (sb < 0) this->sukuBunga = 0;
	else this->sukuBunga = sb;
}

void RekeningGiro::setSukuBunga(double sb) {
	this->sukuBunga = sb;
}

double RekeningGiro::getSukuBunga() const{
	return sukuBunga;
}

double RekeningGiro::hitungBunga() {
	return Rekening::getSaldo() * sukuBunga;
}

/*
MotorCycle::MotorCycle() : Vehicle() {

}

void MotorCycle::drive() {
	cout << "Use helmet" << endl;
	Vehicle::drive();
}

void Car::openDoor() {
	cout << "Door opened" << endl;
}
*/
