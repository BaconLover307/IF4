/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 20-02-2020 */
/* Program      : main.cpp */
/* Deskripsi    : Main dari Car.h */

#include <iostream>
#include "Car.h"
using namespace std;

int main() {
    Car mobil(premium);
    mobil.fillingFuel(premium,100);
    mobil.changeAcPower(1);
    mobil.changeGear(1);
    //mobil.start();
    mobil.service(premium, 100, 1, 0);
}