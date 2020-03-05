// Nama : Gregorius Jovan Kresnadi
// NIM  : 13518135
// Latihan UTS OOP

#include "Box.hpp"
#include <iostream>

using namespace std;

int main() {
	Box * a = new Box(2);
	Box b;
	Box c(1);
	b = *a;
	Box d(c);
	a->peek();
	c.peek();
	delete a;

	return 0;
}