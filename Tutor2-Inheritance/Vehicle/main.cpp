/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 06-02-2020 */
/* Program      : main.cpp */
/* Deskripsi    : Main dari Vehicle.zip */

#include "Vehicle.h"
#include "Car.h"
#include "Bike.h"
#include <iostream>

using namespace std;

int main() {
	Vehicle vA(3,2);
	Vehicle vB(vA);
	Vehicle vC(6,50);
	Car cA(8);
	Car cB(cA);
	Car cC(6);
	Bike b;
	cC.drive();
	b.show();
	b.ride();

}