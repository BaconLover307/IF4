/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 13-02-2020 */

#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include "Bike.h"

using namespace std;

int main() {
	Car ca(4);
	Vehicle * cb = new Car(10);
	Bike * ba = new Bike;
	Vehicle va(*ba);
	delete ba;
	cb->drive();
	va.clean();
	ca.drive();
	va.park();
	delete cb;

  return 0;
}
