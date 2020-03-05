// Nama : Gregorius Jovan Kresnadi
// NIM  : 13518135
// Latihan UTS OOP

#include <bits/stdc++.h>
#include "Vehicle.h"
#include "Car.h"
#include "Bike.h"

using namespace std;

int main() {
	Car ca(4);
	Vehicle* cb = new Car(10);
	Vehicle* bb = new Bike;
	Vehicle va(*bb);
	delete bb;
	cb->drive();
	va.clean();
	ca.drive();
	va.park();
	delete cb;	
  return 0;
}
