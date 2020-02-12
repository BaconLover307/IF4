/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 30-01-2020 */
/* Program      : main.cpp */
/* Deskripsi    : Main untuk box.cpp */

#include "Box.hpp"
#include <iostream>

using namespace std;

int main() {

	Box * x = new Box(2);
	Box y;
	Box z(1);
	y = *x;
	Box a(z);
	x -> peek();
	z.peek();
	delete x;

	return 0;
}
